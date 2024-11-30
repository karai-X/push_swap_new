/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:12:43 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 16:13:18 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*list_append(t_list *list, int num)
{
	t_node	*new_node;
	t_node	*tmp_ptr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = num;
	if (list_is_empty(list) == true)
	{
		list->head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		tmp_ptr = list->head->prev;
		list->head->prev = new_node;
		new_node->next = list->head;
		new_node->prev = tmp_ptr;
		tmp_ptr->next = new_node;
	}
	list->len += 1;
	return (list);
}

t_list	*list_appendleft(t_list *list, int num)
{
	if (list_append(list, num) == NULL)
		return (NULL);
	list_rotate_right(list);
	return (list);
}

void	list_swap(t_list *list, int idx)
{
	int		i;
	t_node	*tmp_ptr;
	int		tmp_num;

	tmp_ptr = list->head;
	i = 0;
	while (i != idx)
	{
		tmp_ptr = tmp_ptr->next;
		i += 1;
	}
	tmp_num = tmp_ptr->next->data;
	tmp_ptr->next->data = tmp_ptr->data;
	tmp_ptr->data = tmp_num;
}

void	list_free(t_list *list)
{
	while (list_is_empty(list) == false)
	{
		list_remove_left(list);
	}
}

void	list_rotate_left(t_list *list)
{
	if (list_is_empty(list) == false)
		list->head = list->head->next;
}
