/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:33:10 by karai             #+#    #+#             */
/*   Updated: 2024/12/19 23:19:07 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "bc_list.h"
# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>

# define SA 1
# define SB 2
# define SS 3
# define PB 4
# define PA 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

int		*ft_comp_cord_main(int *argc, char *argv[]);
int		*ft_comp_cord_main_part(int argc, int *array);
int		*ft_comp_cord(int *array, int length);
void	ft_comp_cord_part(int *temp_array, int *array, int length);
int		*ft_comp_cord_for_split(int *argc, char ***argv, int *split_flag);

bool	ft_is_duplicate(int *array, int length);
void	ft_sort_upper(int *array, int length);
bool	already_sort(int *array, int num);
bool	ft_atoi_for_ps(char *np, int *val);

void	*free2dim(char **array_2d);
void	*print_error(void);

#endif
