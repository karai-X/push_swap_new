/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:28:53 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 14:29:29 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*divide_list_part1(t_list *alist, t_list *blist, t_list *ans_list,
		int move_block_blen_sn[4])
{
	while (move_block_blen_sn[2] - move_block_blen_sn[0] > 3
		&& move_block_blen_sn[0] < 3)
	{
		if (divide_list_part3(blist, ans_list, move_block_blen_sn) == NULL)
			return (NULL);
		if (list_gd(blist, 0) == (ans_list->bottom + 1))
		{
			if (divide_list_part2(alist, blist, ans_list) == NULL)
				return (NULL);
		}
		else if (list_gd(blist, 0) <= move_block_blen_sn[3] + 2)
		{
			if (list_rotate_left_ans(blist, ans_list) == NULL)
				list_append(ans_list, RB);
		}
		else
		{
			if (divide_list_part4(alist, blist, ans_list,
					move_block_blen_sn) == NULL)
				return (NULL);
		}
	}
	return (ans_list);
}

t_list	*divide_list_part2(t_list *alist, t_list *blist, t_list *ans_list)
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

t_list	*divide_list_part3(t_list *blist, t_list *ans_list,
		int *move_block_blen_sn)
{
	if (list_gd(blist, 0) == ans_list->bottom + 2 && list_gd(blist,
			1) == ans_list->bottom + 1)
	{
		if (list_swap_ans(blist, ans_list) == NULL)
			return (NULL);
	}
	if (list_gd(blist, 0) > move_block_blen_sn[3] + 2)
		move_block_blen_sn[0] += 1;
	return (ans_list);
}

t_list	*divide_list_part4(t_list *alist, t_list *blist, t_list *ans_list,
		int *move_block_blen_sn)
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

t_list	*divide_list(t_list *alist, t_list *blist, t_list *ans_list,
		int *block_cnt)
{
	int	move_block_blen_sn[4];

	move_block_blen_sn[0] = 0;
	move_block_blen_sn[1] = *block_cnt;
	move_block_blen_sn[2] = blist->len;
	move_block_blen_sn[3] = list_min(blist);
	if (blist->len <= 11)
	{
		if (move_block_blen_sn[2] > 6)
			move_block_blen_sn[3] = move_block_blen_sn[3]
				+ move_block_blen_sn[2] - 6;
		if (divide_list_part1(alist, blist, ans_list,
				move_block_blen_sn) == NULL)
			return (NULL);
	}
	else
	{
		if (divide_list_part5(alist, blist, ans_list,
				move_block_blen_sn) == NULL)
			return (NULL);
	}
	*block_cnt = move_block_blen_sn[1];
	return (ans_list);
}
