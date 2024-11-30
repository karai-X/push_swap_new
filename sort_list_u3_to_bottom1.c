/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3_to_bottom1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:53:03 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 09:57:20 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*sort_list_u3_to_bottom_part1(t_list *alist, t_list *ans_list)
{
	if (list_gd(alist, 0) > list_gd(alist, 1))
	{
		if (list_swap_ans(alist, ans_list) == NULL)
			return (NULL);
	}
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	ans_list->bottom += 2;
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part2(t_list *alist, t_list *blist,
		t_list *ans_list)
{
	int	sn;
	int	flag;

	if (sort_list_u3_to_bottom_part9(alist, ans_list, &sn, &flag) == NULL)
		return (NULL);
	if (flag == 0 && (list_gd(alist, 0) == sn + 1) && (list_gd(alist, 1) == sn
			+ 2))
	{
		if (sort_list_u3_to_bottom_part5(alist, blist, ans_list, sn) == NULL)
			return (NULL);
	}
	else if (flag == 0 && (list_gd(alist, 0) == sn + 2) && (list_gd(alist,
				1) == sn))
	{
		if (sort_list_u3_to_bottom_part6(alist, blist, ans_list, sn) == NULL)
			return (NULL);
	}
	else if (flag == 0 && (list_gd(alist, 0) == sn + 2) && (list_gd(alist,
				1) == sn + 1))
	{
		if (sort_list_u3_to_bottom_part7(alist, blist, ans_list, sn) == NULL)
			return (NULL);
	}
	ans_list->bottom += 3;
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part3(t_list *alist, t_list *ans_list)
{
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_swap_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part4(t_list *alist, t_list *ans_list)
{
	if (list_swap_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom(t_list *alist, t_list *blist, t_list *ans_list,
		int num)
{
	if (num == 1)
	{
		if (list_rotate_left_ans(alist, ans_list) == NULL)
			return (NULL);
		ans_list->bottom += 1;
	}
	else if (num == 2)
	{
		if (sort_list_u3_to_bottom_part1(alist, ans_list) == NULL)
			return (NULL);
	}
	else if (num == 3)
	{
		if (sort_list_u3_to_bottom_part2(alist, blist, ans_list) == NULL)
			return (NULL);
	}
	return (ans_list);
}
