/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:29:25 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 16:22:10 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*ft_solve_part1(t_list *alist, t_list *blist, t_list *ans_list, int len)
{
	if (len < 4)
	{
		if (sort_list_u3(alist, ans_list) == NULL)
			return (NULL);
	}
	else if (len < 7)
	{
		if (divide_list_init(alist, blist, ans_list) == NULL)
			return (NULL);
		if (sort_list_u3(alist, ans_list) == NULL)
			return (NULL);
		if (sort_list_u3(blist, ans_list) == NULL)
			return (NULL);
		if (move_bottom_list(blist, alist, ans_list) == NULL)
			return (NULL);
	}
	return (ans_list);
}

t_list	*ft_solve_part2(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	if (list_gd(block_list, 0) <= 3 && list_gd(block_list, 0) >= 1)
	{
		if (sort_list_u3_to_bottom(alist, blist, ans_list, list_gd(block_list,
					0)) == NULL)
			return (NULL);
		list_remove_left(block_list);
	}
	else
	{
		if (list_move(alist, blist, ans_list, list_gd(block_list, 0)) == NULL)
			return (NULL);
		list_remove_left(block_list);
		if (ft_dfs(alist, blist, ans_list, block_list) == NULL)
			return (NULL);
		if (sort_list_u3_to_other(alist, blist, ans_list) == NULL)
			return (NULL);
	}
	return (ans_list);
}

t_list	*ft_solve(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	int	len;

	len = alist->len;
	if (ft_solve_part1(alist, blist, ans_list, len) == NULL)
		return (NULL);
	if (len >= 7)
	{
		divide_list_init(alist, blist, ans_list);
		if (list_appendleft(block_list, len / 2) == NULL)
			return (NULL);
		if (list_appendleft(block_list, 0) == NULL)
			return (NULL);
		while (list_is_empty(block_list) == false)
		{
			if (ft_solve_part2(alist, blist, ans_list, block_list) == NULL)
				return (NULL);
		}
	}
	return (ans_list);
}
