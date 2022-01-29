/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:07:55 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/24 23:43:29 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include "dynarray.h"

typedef struct s_character
{
	t_dynarray	*darr;
	int			index;
	char		character;
}				t_character;

#endif
