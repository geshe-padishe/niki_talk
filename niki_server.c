#include "niki_talk.h"

t_character	c;

void	sig1_handler(int i)
{
	(void)i;
	c.character |= (000000001 << c.index);
	printf("c.d = %d ", c.character);
	printf("c = %c ", c.character);
	printf("index = %d", c.index);
	printf(" SIG1\n");
	c.index++;
	if (c.index == 7)
	{
		printf("FINAL D = %d ", c.character);
		printf("FINAL C = %c\n", c.character);
		push_dynarray(c.darr, &c.character, 1, 0);
		c.character = 0;
		c.index = 0;
	}
}

void	sig2_handler(int i)
{
	(void)i;
	printf("c.d = %d ", c.character);
	printf("c = %c ", c.character);
	printf("index = %d", c.index);
	printf(" SIG2\n");
	c.index++;
	if (c.index == 7)
	{
		printf("FINAL D = %d ", c.character);
		printf("FINAL C = %c\n", c.character);
		push_dynarray(c.darr, &c.character, 1, 0);
		c.character = 0;
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

	signal(SIGUSR1, sig1_handler);
	signal(SIGUSR2, sig2_handler);

	printf("\npid = %d\n", getpid());
//	while (c.darr->nb_cells > i)
//	{
//		printf("%c\n", ((char *)c.darr->list)[i]);
//		i++;
//	}
	while (1);
	return (0);
}
