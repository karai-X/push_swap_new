/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:04 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 11:30:48 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*move_bottom_list(t_list *alist, t_list *blist, t_list *ans_list)
{
	while (list_is_empty(alist) == false)
	{
		if (list_appendleft(blist, list_gd(alist, 0)) == NULL)
			return (NULL);
		list_rotate_left(blist);
		list_remove_left(alist);
		if (list_append(ans_list, PB + alist->idx) == NULL)
			return (NULL);
		if (list_append(ans_list, RA) == NULL)
			return (NULL);
	}
	return (ans_list);
}

t_list	*ft_dfs(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	int	block_cnt;

	while (blist->len > 3)
	{
		block_cnt = 0;
		divide_list(alist, blist, ans_list, &block_cnt);
		if (list_appendleft(block_list, block_cnt) == NULL)
			return (NULL);
	}
	return (ans_list);
}

int	list_min_limit(t_list *list, int num)
{
	int	sn;
	int	i;

	sn = INT_MAX;
	i = 0;
	while (i < num)
	{
		if (list_gd(list, i) < sn)
			sn = list_gd(list, i);
		i += 1;
	}
	return (sn);
}
