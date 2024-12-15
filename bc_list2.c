/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:37:52 by karai             #+#    #+#             */
/*   Updated: 2024/12/15 13:07:25 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

int	list_gd(t_list *list, int idx)
{
	int		i;
	t_node	*tmp_ptr;

	if (list_is_empty(list))
		return (-1);
	else
	{
		i = 0;
		tmp_ptr = list->head;
		while (i != idx)
		{
			tmp_ptr = tmp_ptr->next;
			i += 1;
		}
		return (tmp_ptr->data);
	}
}

int	list_min(t_list *list)
{
	int		minimum;
	int		i;
	t_node	*tmp_ptr;

	if (list_is_empty(list) == true)
		return (-1);
	else
	{
		minimum = list_gd(list, 0);
		i = 0;
		tmp_ptr = list->head;
		while (i < list->len)
		{
			if (minimum > tmp_ptr->data)
				minimum = tmp_ptr->data;
			tmp_ptr = tmp_ptr->next;
			i += 1;
		}
	}
	return (minimum);
}

int	list_last(t_list *list)
{
	if (list_is_empty(list))
		return (-1);
	else
		return (list->head->prev->data);
}

void	list_remove_left(t_list *list)
{
	t_node	*tmp_ptr;

	if (list_is_empty(list) == false)
	{
		list->head->next->prev = list->head->prev;
		list->head->prev->next = list->head->next;
		tmp_ptr = list->head;
		if (list->head == list->head->next)
			list->head = NULL;
		else
			list->head = list->head->next;
		free(tmp_ptr);
		list->len -= 1;
	}
}

void	list_remove_right(t_list *list)
{
	t_node	*tmp_ptr;

	tmp_ptr = NULL;
	if (list_is_empty(list) == false)
	{
		if (list->head == list->head->next)
			list->head = NULL;
		else
		{
			tmp_ptr = list->head->prev;
			tmp_ptr->prev->next = tmp_ptr->next;
			tmp_ptr->next->prev = tmp_ptr->prev;
		}
		free(tmp_ptr);
		list->len -= 1;
	}
}
