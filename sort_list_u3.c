/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:52:52 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 20:08:43 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*sort_list_u3_part(t_list *list, t_list *ans_list, int sn)
{
	if ((list_gd(list, 0) == sn) && (list_gd(list, 1) == sn + 2))
	{
		if (list_rotate_right_ans(list, ans_list) == NULL)
			return (NULL);
	}
	if (((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn))
		|| ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn + 1)))
	{
		if (list_swap_ans(list, ans_list) == NULL)
			return (NULL);
	}
	if ((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn + 2))
	{
		if (list_rotate_right_ans(list, ans_list) == NULL)
			return (NULL);
	}
	if ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn))
	{
		if (list_rotate_left_ans(list, ans_list) == NULL)
			return (NULL);
	}
	return (list);
}

t_list	*sort_list_u3(t_list *list, t_list *ans_list)
{
	int	sn;

	sn = list_min(list);
	if (list->len == 1)
		return (list);
	else if (list->len == 2)
	{
		if (list_gd(list, 0) > list_gd(list, 1))
		{
			if (list_swap_ans(list, ans_list) == NULL)
				return (NULL);
		}
	}
	else if (list->len == 3)
	{
		if (sort_list_u3_part(list, ans_list, sn) == NULL)
			return (NULL);
	}
	return (list);
}
