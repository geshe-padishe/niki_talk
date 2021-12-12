#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "niki_talk.h"

t_character	c;


void	sig1_handler(int i)
{
	(void)i;
	c.character = c.character | 000000001 << c.index;
	c.index++;
	if (c.index == 7)
	{
		push_dynarray(c.darr, &c.character, 1, 0);
		c.character = '0';
		c.index = 0;
	}
}

void	sig2_handler(int i)
{
	(void)i;
	c.character = c.character | 000000001 << c.index;
	c.index++;
	if (c.index == 7)
	{
		push_dynarray(c.darr, &c.character, 1, 0);
		c.character = '0';
		c.index = 0;
	}
}

void	ft_print_nb_base(unsigned int nb, unsigned int base)
{
	if (nb > 0)
	{
		ft_print_nb_base(nb / base, base);
		printf("%u", nb % 2);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	unsigned long i;

	i = 0;

	c.index = 0;
	c.character = 0;
	t_dynarray darr;
	c.darr = &darr;
	init_dynarray(c.darr, 10, 1);
	printf("darr *p = %p\n", c.darr);
	signal(SIGUSR1, sig1_handler);
	signal(SIGUSR2, sig2_handler);
	for (i = 0; i <= 14; i++)
	{
		if (i % 2 == 0)
			raise(SIGUSR1);
		else
			raise(SIGUSR2);
	}
	printf("\npid = %d\n", getpid());
	while (c.darr->nb_cells > i)
	{
		printf("%c\n", ((char *)c.darr->list)[i]);
		i++;
	}
	dprintf(1, "nb_cells: %llu, cell_size: %llu, byte_size: %llu\n", c.darr->nb_cells, c.darr->cell_size, c.darr->byte_size);
	while (1)
		sleep(1);
	return (0);
}
