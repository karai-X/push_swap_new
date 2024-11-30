/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 16:22:54 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	print_ans_part(int num)
{
	if (num == SA)
		printf("sa\n");
	if (num == SB)
		printf("sb\n");
	if (num == SS)
		printf("ss\n");
	if (num == PB)
		printf("pb\n");
	if (num == PA)
		printf("pa\n");
	if (num == RA)
		printf("ra\n");
	if (num == RB)
		printf("rb\n");
	if (num == RR)
		printf("rr\n");
	if (num == RRA)
		printf("rra\n");
	if (num == RRB)
		printf("rrb\n");
	if (num == RRR)
		printf("rrr\n");
}

void	print_ans(t_list *ans_list)
{
	t_node	*tmp_ptr;

	tmp_ptr = ans_list->head;
	print_ans_part(tmp_ptr->data);
	tmp_ptr = tmp_ptr->next;
	while (tmp_ptr != ans_list->head)
	{
		print_ans_part(tmp_ptr->data);
		tmp_ptr = tmp_ptr->next;
	}
}

void	list_free_all(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	list_free(alist);
	list_free(blist);
	list_free(ans_list);
	list_free(block_list);
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_list	alist[1];
	t_list	blist[1];
	t_list	ans_list[1];
	t_list	block_list[1];

	// To implement error check
	array = ft_comp_cord_main(argc, argv);
	if (array == NULL)
		return (1);
	list_initialize(alist, blist, ans_list, block_list);
	if (list_initial_make(alist, array, argc) == NULL)
	{
		free(array);
		return (1);
	}
	if (ft_solve(alist, blist, ans_list, block_list) == NULL)
	{
		list_free_all(alist, blist, ans_list, block_list);
		free(array);
		return (1);
	}
	ft_integrate(ans_list);
	print_ans(ans_list);
	list_free_all(alist, blist, ans_list, block_list);
	free(array);
}
