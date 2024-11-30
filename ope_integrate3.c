/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_integrate3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:44:51 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 15:46:50 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	integarate_pa_pa_ra_pb_part(t_node **tmp_ptr, int *cnt,
		t_list *ans_list)
{
	t_node	*delete_node;

	if ((*cnt == 1 || *cnt == 2) && (*tmp_ptr)->data == PA)
		*cnt = 2;
	else if ((*tmp_ptr)->data == PA)
		*cnt = 1;
	else if (*cnt == 2 && (*tmp_ptr)->data == RA)
		*cnt = 3;
	else if (*cnt == 3 && (*tmp_ptr)->data == PB)
	{
		*cnt = 0;
		(*tmp_ptr)->prev->prev->prev->data = SB;
		(*tmp_ptr)->prev->prev->data = PA;
		(*tmp_ptr)->prev->data = RA;
		(*tmp_ptr)->prev->next = (*tmp_ptr)->next;
		(*tmp_ptr)->next->prev = (*tmp_ptr)->prev;
		delete_node = (*tmp_ptr);
		(*tmp_ptr) = (*tmp_ptr)->prev;
		free(delete_node);
		ans_list->len -= 1;
	}
	else
		*cnt = 0;
}

void	integarate_pa_pa_ra_pb(t_list *list)
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
			integarate_pa_pa_ra_pb_part(&tmp_ptr, &cnt, list);
			tmp_ptr = tmp_ptr->next;
		}
	}
}

void	integrate_rb_ra(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node;

	if (list_is_empty(list) == true || list->len <= 3)
		return ;
	else
	{
		tmp_ptr = list->head->next->next;
		while (tmp_ptr != list->head)
		{
			if ((tmp_ptr->prev->data == RA && tmp_ptr->data == RB)
				|| (tmp_ptr->prev->data == RB && tmp_ptr->data == RA))
			{
				delete_node = tmp_ptr;
				tmp_ptr->prev->next = tmp_ptr->next;
				tmp_ptr->next->prev = tmp_ptr->prev;
				tmp_ptr->prev->data = RR;
				tmp_ptr = tmp_ptr->prev;
				free(delete_node);
				list->len -= 1;
			}
			tmp_ptr = tmp_ptr->next;
		}
	}
}
