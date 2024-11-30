/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:11:57 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 14:24:52 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*divide_list_part5(t_list *alist, t_list *blist, t_list *ans_list,
		int move_block_blen_sn[4])
{
	while (move_block_blen_sn[0] < move_block_blen_sn[2] / 2)
	{
		if (list_gd(blist, 0) > move_block_blen_sn[3] + (move_block_blen_sn[2]
				- 1) / 2)
			move_block_blen_sn[0] += 1;
		if (list_gd(blist, 0) == ans_list->bottom + 1)
		{
			if (divide_list_part6(alist, blist, ans_list) == NULL)
				return (NULL);
		}
		else if (list_gd(blist, 0) <= move_block_blen_sn[3]
			+ (move_block_blen_sn[2] - 1) / 2)
		{
			list_rotate_left(blist);
			list_append(ans_list, RA + blist->idx);
		}
		else
		{
			if (divide_list_part7(alist, blist, ans_list,
					move_block_blen_sn) == NULL)
				return (NULL);
		}
	}
	return (ans_list);
}

t_list	*divide_list_part6(t_list *alist, t_list *blist, t_list *ans_list)
{
	if (list_last(ans_list) == PB)
		list_remove_right(ans_list);
	else
	{
		if (list_append(ans_list, PA) == NULL)
			return (NULL);
	}
	if (list_appendleft(alist, list_gd(blist, 0)) == NULL)
		return (NULL);
	list_remove_left(blist);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	ans_list->bottom += 1;
	return (ans_list);
}

t_list	*divide_list_part7(t_list *alist, t_list *blist, t_list *ans_list,
		int move_block_blen_sn[4])
{
	if (list_last(ans_list) == PB)
		list_remove_right(ans_list);
	else
	{
		if (list_append(ans_list, PA) == NULL)
			return (NULL);
	}
	if (list_appendleft(alist, list_gd(blist, 0)) == NULL)
		return (NULL);
	list_remove_left(blist);
	move_block_blen_sn[1] += 1;
	return (ans_list);
}
