/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_integrate2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:34:45 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 15:42:21 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	integrate_sb_pa_ra_pa_ra_part(t_node *tmp_ptr)
{
	int	i;

	tmp_ptr->prev->next = tmp_ptr->next;
	tmp_ptr->next->prev = tmp_ptr->prev;
	i = 0;
	while (i < 4)
	{
		tmp_ptr = tmp_ptr->next;
		if (i < 2)
			tmp_ptr->data = PA;
		else
			tmp_ptr->data = RA;
		i += 1;
	}
}

void	integrate_sb_pa_ra_pa_ra(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node;

	if (list_is_empty(list) == true || list->len <= 100)
		return ;
	else
	{
		tmp_ptr = list->head->next;
		while (tmp_ptr != list->head)
		{
			if (tmp_ptr->data == SB)
			{
				integrate_sb_pa_ra_pa_ra_part(tmp_ptr);
				delete_node = tmp_ptr;
				list->len -= 1;
				tmp_ptr = tmp_ptr->next;
				free(delete_node);
			}
			else
				tmp_ptr = tmp_ptr->next;
		}
	}
}

void	integarate_pb_pb_rb_pa_part(t_node **tmp_ptr, int *cnt,
		t_list *ans_list)
{
	t_node	*delete_node;

	if ((*cnt == 1 || *cnt == 2) && (*tmp_ptr)->data == PB)
		*cnt = 2;
	else if ((*tmp_ptr)->data == PB)
		*cnt = 1;
	else if (*cnt == 2 && (*tmp_ptr)->data == RB)
		*cnt = 3;
	else if (*cnt == 3 && (*tmp_ptr)->data == PA)
	{
		*cnt = 0;
		(*tmp_ptr)->prev->prev->prev->data = SA;
		(*tmp_ptr)->prev->prev->data = PB;
		(*tmp_ptr)->prev->data = RB;
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

void	integarate_pb_pb_rb_pa(t_list *list)
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
			integarate_pb_pb_rb_pa_part(&tmp_ptr, &cnt, list);
			tmp_ptr = tmp_ptr->next;
		}
	}
}
