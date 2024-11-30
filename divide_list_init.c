/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_list_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:19:39 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 10:00:04 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*divide_list_init_part1(t_list *alist, t_list *blist, t_list *ans_list,
		int sn)
{
	while (alist->len > 3)
	{
		if (list_gd(alist, 0) <= sn + 2)
		{
			if (list_rotate_left_ans(alist, ans_list) == NULL)
				return (NULL);
		}
		else
		{
			if (list_appendleft(blist, list_gd(alist, 0)) == NULL)
				return (NULL);
			list_remove_left(alist);
			if (list_append(ans_list, PB + alist->idx) == NULL)
				return (NULL);
		}
	}
	return (ans_list);
}

t_list	*divide_list_init_part2(t_list *alist, t_list *blist, t_list *ans_list,
		int sn)
{
	int	init_alist_len;

	init_alist_len = alist->len;
	while (alist->len > init_alist_len / 2)
	{
		if (list_gd(alist, 0) < sn + (init_alist_len + 1) / 2)
		{
			if (list_appendleft(blist, list_gd(alist, 0)) == NULL)
				return (NULL);
			list_remove_left(alist);
			if (list_append(ans_list, PB + alist->idx) == NULL)
				return (NULL);
		}
		else
		{
			list_rotate_left(alist);
			if (list_append(ans_list, RA + alist->idx) == NULL)
				return (NULL);
		}
	}
	return (ans_list);
}

t_list	*divide_list_init(t_list *alist, t_list *blist, t_list *ans_list)
{
	int	sn;

	sn = list_min(alist);
	if (alist->len <= 6)
	{
		if (divide_list_init_part1(alist, blist, ans_list, sn) == NULL)
			return (NULL);
	}
	else
	{
		if (divide_list_init_part2(alist, blist, ans_list, sn) == NULL)
			return (NULL);
	}
	return (ans_list);
}
