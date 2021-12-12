/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:38 by nikotikch         #+#    #+#             */
/*   Updated: 2021/12/12 19:02:07 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARRAY_H
# define DYNARRAY_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_dynarray
{
	void		*list;
	void		*tmp;
	uint64_t	cell_size;
	uint64_t	nb_cells;
	uint64_t	byte_size;
}				t_dynarray;

int		ft_uatoi(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		init_dynarray(t_dynarray *dynarray,
			uint64_t nb_cells, size_t cell_size);
void	clear_dynarray(t_dynarray *dynarray);
void	free_dynarray(t_dynarray *dynarray);
int		pop_dynarray(t_dynarray *dynarray, uint64_t nb_cells_pop, bool way);
int		push_dynarray(t_dynarray *dynarray, void *new_cells,
			uint64_t nb_ncells, bool way);
int		dynarray_realloc(t_dynarray *dynarray, size_t new_byte_size);
int		dynarray_extract(t_dynarray *darr, uint64_t index, uint64_t nb_ext);
int		dyn_insr(t_dynarray *darr, void *ncells,
			uint64_t index, uint64_t nb_ncells);
void	*dynacc(t_dynarray *darr, uint64_t index);

#endif
