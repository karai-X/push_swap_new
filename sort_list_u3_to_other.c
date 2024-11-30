/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3_to_other.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:32:07 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 09:58:07 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*sort_list_u3_to_other_part1(t_list *alist, t_list *blist,
		t_list *ans_list, int *alist_top)
{
	if (list_appendleft(alist, list_gd(blist, 0)) == NULL)
		return (NULL);
	list_remove_left(blist);
	if (list_append(ans_list, PA) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	ans_list->bottom += 1;
	while (*alist_top > 0)
	{
		if (list_gd(alist, 0) == ans_list->bottom + 1)
		{
			if (list_rotate_left_ans(alist, ans_list) == NULL)
				return (NULL);
			ans_list->bottom += 1;
			*alist_top -= 1;
		}
		else
			break ;
	}
	return (ans_list);
}

t_list	*sort_list_u3_to_other(t_list *alist, t_list *blist, t_list *ans_list)
{
	int	alist_top;

	alist_top = 0;
	while (blist->len != 0)
	{
		if (list_gd(blist, 0) == ans_list->bottom + 1)
		{
			if (sort_list_u3_to_other_part1(alist, blist, ans_list,
					&alist_top) == NULL)
				return (NULL);
		}
		else
		{
			list_appendleft(alist, list_gd(blist, 0));
			list_remove_left(blist);
			list_append(ans_list, PA);
			alist_top += 1;
			if (alist_top >= 2 && (list_gd(alist, 0) > list_gd(alist, 1)))
				if (list_swap_ans(alist, ans_list) == NULL)
					return (NULL);
		}
	}
	return (ans_list);
}
