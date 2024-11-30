/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3_to_bottom2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 07:57:43 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 08:29:28 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*sort_list_u3_to_bottom_part5(t_list *alist, t_list *blist,
		t_list *ans_list, int sn)
{
	if (list_append(ans_list, PB + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, SA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, PB + blist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	list_remove_left(alist);
	list_remove_left(alist);
	list_remove_left(alist);
	if (list_append(alist, sn) == NULL)
		return (NULL);
	if (list_append(alist, sn + 1) == NULL)
		return (NULL);
	if (list_append(alist, sn + 2) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part6(t_list *alist, t_list *blist,
		t_list *ans_list, int sn)
{
	if (list_append(ans_list, PB + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, PB + blist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	list_remove_left(alist);
	list_remove_left(alist);
	list_remove_left(alist);
	if (list_append(alist, sn) == NULL)
		return (NULL);
	if (list_append(alist, sn + 1) == NULL)
		return (NULL);
	if (list_append(alist, sn + 2) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part7(t_list *alist, t_list *blist,
		t_list *ans_list, int sn)
{
	if (list_append(ans_list, PB + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, SA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, PB + blist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	list_remove_left(alist);
	list_remove_left(alist);
	list_remove_left(alist);
	if (list_append(alist, sn) == NULL)
		return (NULL);
	if (list_append(alist, sn + 1) == NULL)
		return (NULL);
	if (list_append(alist, sn + 2) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part8(t_list *alist, t_list *ans_list)
{
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	if (list_append(ans_list, RA + alist->idx) == NULL)
		return (NULL);
	list_rotate_left(alist);
	list_rotate_left(alist);
	list_rotate_left(alist);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part9(t_list *alist, t_list *ans_list, int *sn,
		int *flag)
{
	*flag = 1;
	*sn = list_min_limit(alist, 3);
	if ((list_gd(alist, 0) == *sn) && (list_gd(alist, 1) == *sn + 2))
	{
		if (sort_list_u3_to_bottom_part3(alist, ans_list) == NULL)
			return (NULL);
	}
	else if ((list_gd(alist, 0) == *sn + 1) && (list_gd(alist, 1) == *sn))
	{
		if (sort_list_u3_to_bottom_part4(alist, ans_list) == NULL)
			return (NULL);
	}
	else if ((list_gd(alist, 0) == *sn) && (list_gd(alist, 1) == *sn + 1))
	{
		if (sort_list_u3_to_bottom_part8(alist, ans_list) == NULL)
			return (NULL);
	}
	else
		*flag = 0;
	return (ans_list);
}
