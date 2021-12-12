#include "dynarray.h"

int	ft_uatoi(char *str)
{
	int			i;
	long long	nb;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && nb <= 2147483647)
			nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return ((int)nb);
}
