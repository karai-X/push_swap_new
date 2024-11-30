/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_integrate1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:00:01 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 15:37:56 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	ft_integrate(t_list *ans_list)
{
	int	i;

	i = 0;
	integrate_sb_pa_ra_pa_ra(ans_list);
	while (i < 6)
	{
		integrate_pb_pa(ans_list);
		integarate_pb_ra_pa(ans_list);
		integrate_rb_ra(ans_list);
		if (i > 2)
		{
			integarate_pb_pb_rb_pa(ans_list);
			integarate_pa_pa_ra_pb(ans_list);
		}
		i += 1;
	}
}

void	integarate_pb_ra_pa_part(t_node **tmp_ptr, int *cnt)
{
	t_node	*delete_node;

	(*tmp_ptr)->prev->prev->data = SA;
	(*tmp_ptr)->prev->data = RA;
	(*tmp_ptr)->prev->next = (*tmp_ptr)->next;
	(*tmp_ptr)->next->prev = (*tmp_ptr)->prev;
	delete_node = (*tmp_ptr);
	(*tmp_ptr) = (*tmp_ptr)->prev;
	free(delete_node);
	*cnt = 0;
}

void	integarate_pb_ra_pa(t_list *list)
{
	t_node	*tmp_ptr;
	int		cnt;

	cnt = 0;
	if (list_is_empty(list) == true)
		return ;
	else
	{
		tmp_ptr = list->head->next;
		while (tmp_ptr != list->head)
		{
			if (tmp_ptr->data == PB)
				cnt = 1;
			else if (cnt == 1 && tmp_ptr->data == RA)
				cnt = 2;
			else if (cnt == 2 && tmp_ptr->data == PA)
			{
				integarate_pb_ra_pa_part(&tmp_ptr, &cnt);
				list->len -= 1;
			}
			else
				cnt = 0;
			tmp_ptr = tmp_ptr->next;
		}
	}
}

void	integrate_pb_pa_part(t_list *list, t_node *tmp_ptr)
{
	t_node	*delete_node1;

	delete_node1 = tmp_ptr->prev;
	tmp_ptr->prev->prev->next = tmp_ptr->next;
	tmp_ptr->next->prev = tmp_ptr->prev->prev;
	if (tmp_ptr->prev == list->head)
		list->head = tmp_ptr->next;
	free(delete_node1);
	list->len -= 2;
}

void	integrate_pb_pa(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node2;

	if (list_is_empty(list) == true || list->len <= 10)
		return ;
	else
	{
		tmp_ptr = list->head->next->next;
		while (tmp_ptr != list->head)
		{
			if ((tmp_ptr->prev->data == PB && tmp_ptr->data == PA)
				|| (tmp_ptr->prev->data == PA && tmp_ptr->data == PB))
			{
				integrate_pb_pa_part(list, tmp_ptr);
				delete_node2 = tmp_ptr;
				tmp_ptr = tmp_ptr->next;
				free(delete_node2);
			}
			tmp_ptr = tmp_ptr->next;
		}
	}
}
