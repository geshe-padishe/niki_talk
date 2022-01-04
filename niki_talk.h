#ifndef NIKI_TALK_H
# define NIKI_TALK_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
#include <signal.h>
# include "dynarray.h"

typedef struct s_character
{
	t_dynarray	*darr;
	int		index;
	char	character;
}				t_character;

#endif
