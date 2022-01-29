/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:53:18 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/25 00:16:58 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
*void	ft_print_nb_base(unsigned int nb, unsigned int base)
*{
*	if (nb > 0)
*	{
*		ft_print_nb_base(nb / base, base);
*		printf("%u", nb % 2);
*	}
*}
*/
int	ft_send_char(char c, int pid)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		usleep(100);
		if ((c & (000000001 << index)) > 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		index++;
	}
	return (0);
}

int	ft_send_end_signal(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(100);
		if (kill(pid, SIGUSR2) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	pid = ft_uatoi(argv[1]);
	if (pid <= 0)
		return (-1);
	while (argv[2][i])
	{
		if (ft_send_char(argv[2][i], pid))
			return (-1);
		i++;
	}
	if (ft_send_end_signal(pid) == -1)
		return (-1);
	return (0);
}
