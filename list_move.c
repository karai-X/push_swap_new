/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:21:38 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 10:22:18 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*list_move_part1(t_list *alist, t_list *blist, t_list *ans_list)
{
	if (list_appendleft(alist, list_gd(blist, 0)) == NULL)
		return (NULL);
	list_remove_left(blist);
	if (list_append(ans_list, PA) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	ans_list->bottom += 1;
	return (ans_list);
}

t_list	*list_move_part2(t_list *alist, t_list *blist, t_list *ans_list)
{
	if (list_append(ans_list, PB + alist->idx) == NULL)
		return (NULL);
	if (list_appendleft(blist, list_gd(alist, 0)) == NULL)
		return (NULL);
	list_remove_left(alist);
	return (ans_list);
}

t_list	*list_move(t_list *alist, t_list *blist, t_list *ans_list, int move_num)
{
	int	i;

	i = 0;
	while (i < move_num)
	{
		if (list_gd(alist, 0) == (ans_list->bottom + 1))
		{
			if (list_rotate_left_ans(alist, ans_list) == NULL)
				return (NULL);
			ans_list->bottom += 1;
			while (list_gd(blist, 0) == (ans_list->bottom + 1))
			{
				if (list_move_part1(alist, blist, ans_list) == NULL)
					return (NULL);
			}
		}
		else
		{
			if (list_move_part2(alist, blist, ans_list) == NULL)
				return (NULL);
		}
		i += 1;
	}
	return (ans_list);
}
