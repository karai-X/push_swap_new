/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:48:16 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 16:11:11 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*list_rotate_right_ans(t_list *list, t_list *ans_list)
{
	if (list_append(ans_list, RRA + list->idx) == NULL)
		return (NULL);
	list_rotate_right(list);
	return (ans_list);
}

t_list	*list_swap_ans(t_list *list, t_list *ans_list)
{
	if (list_append(ans_list, SA + list->idx) == NULL)
		return (NULL);
	list_swap(list, 0);
	return (ans_list);
}

t_list	*list_rotate_left_ans(t_list *list, t_list *ans_list)
{
	if (list_append(ans_list, RA + list->idx) == NULL)
		return (NULL);
	list_rotate_left(list);
	return (ans_list);
}
