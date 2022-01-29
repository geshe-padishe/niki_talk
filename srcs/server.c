/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:01:44 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/29 23:59:06 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_character	g_c;

void	ft_itoa(int pid)
{
	char	c;

	c = (pid % 10) + 48;
	if (pid > 9)
		ft_itoa(pid / 10);
	write(1, &c, 1);
}

void	ft_print_string(void)
{
	int	i;

	i = 0;
	while (g_c.darr->nb_cells > i)
	{
		write(1, &((char *)g_c.darr->list)[i], 1);
		i++;
	}
	free_dynarray(g_c.darr);
}

void	sig1_handler(int i)
{
	(void)i;
	if (g_c.darr->list == NULL)
		if (init_dynarray(g_c.darr, 10, 1) == -1)
			return ;
	g_c.character |= (000000001 << g_c.index);
	g_c.index++;
	if (g_c.index == 8)
	{
		if (push_dynarray(g_c.darr, &g_c.character, 1, 0) == -1)
			return ;
		g_c.character = 0;
		g_c.index = 0;
	}
}

void	sig2_handler(int i)
{
	(void)i;
	g_c.index++;
	if (g_c.darr->list == NULL)
		if (init_dynarray(g_c.darr, 10, 1) == -1)
			return ;
	if (g_c.index == 8)
	{
		if (g_c.character == 0)
			ft_print_string();
		else
			if (push_dynarray(g_c.darr, &g_c.character, 1, 0) == -1)
				return ;
		g_c.character = 0;
		g_c.index = 0;
	}
}

int	main(int argc, char **argv)
{
	t_dynarray		darr;
	int				pid;

	(void)argc;
	(void)argv;
	g_c.index = 0;
	g_c.character = 0;
	g_c.darr = &darr;
	init_dynarray(g_c.darr, 10, 1);
	signal(SIGUSR1, sig1_handler);
	signal(SIGUSR2, sig2_handler);
	write(1, "pid = ", 6);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
