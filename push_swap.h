/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:33:10 by karai             #+#    #+#             */
/*   Updated: 2024/11/28 21:29:15 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

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

int		*ft_comp_cord_main(int argc, char *argv[]);
void	ft_sort_upper(int *array, int length);
int		*ft_comp_cord(int *array, int length);
bool	ft_is_duplicate(int *array, int length);

#endif
