/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:46 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 15:44:51 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BC_LIST_H
# define BC_LIST_H

# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;
typedef struct s_list
{
	t_node			*head;
	int				idx;
	int				len;
	int				bottom;
}					t_list;

bool				list_is_empty(t_list *list);
t_list				*list_append(t_list *list, int num);
void				list_print(t_list *list);
t_list				*list_appendleft(t_list *list, int num);
void				list_rotate_right(t_list *list);
void				list_rotate_left(t_list *list);
void				list_remove_left(t_list *list);
int					list_gd(t_list *list, int idx);
void				list_swap(t_list *list, int idx);
int					list_last(t_list *list);
void				list_remove_right(t_list *list);
void				list_free(t_list *list);

t_list				*list_rotate_right_ans(t_list *list, t_list *ans_list);
t_list				*list_swap_ans(t_list *list, t_list *ans_list);
t_list				*list_rotate_left_ans(t_list *list, t_list *ans_list);

t_list				*sort_list_u3_part(t_list *list, t_list *ans_list, int sn);
t_list				*sort_list_u3(t_list *list, t_list *ans_list);

t_list				*divide_list(t_list *alist, t_list *blist, t_list *ans_list,
						int *block_cnt);
t_list				*divide_list_part1(t_list *alist, t_list *blist,
						t_list *ans_list, int move_block_blen_sn[4]);
t_list				*divide_list_part2(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*divide_list_part3(t_list *blist, t_list *ans_list,
						int *move_block_blen_sn);
t_list				*divide_list_part4(t_list *alist, t_list *blist,
						t_list *ans_list, int *move_block_blen_sn);
t_list				*divide_list_part5(t_list *alist, t_list *blist,
						t_list *ans_list, int move_block_blen_sn[4]);
t_list				*divide_list_part6(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*divide_list_part7(t_list *alist, t_list *blist,
						t_list *ans_list, int move_block_blen_sn[4]);

int					list_min(t_list *list);
t_list				*move_bottom_list(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*ft_dfs(t_list *blist, t_list *alist, t_list *ans_list,
						t_list *block_list);

t_list				*list_move(t_list *alist, t_list *blist, t_list *ans_list,
						int move_num);
t_list				*list_move_part1(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*list_move_part2(t_list *alist, t_list *blist,
						t_list *ans_list);

t_list				*divide_list_init(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*divide_list_init_part1(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);
t_list				*divide_list_init_part2(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);

t_list				*sort_list_u3_to_bottom(t_list *alist, t_list *blist,
						t_list *ans_list, int num);
t_list				*sort_list_u3_to_bottom_part1(t_list *alist,
						t_list *ans_list);
t_list				*sort_list_u3_to_bottom_part2(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*sort_list_u3_to_bottom_part3(t_list *alist,
						t_list *ans_list);
t_list				*sort_list_u3_to_bottom_part4(t_list *alist,
						t_list *ans_list);
t_list				*sort_list_u3_to_bottom_part5(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);
t_list				*sort_list_u3_to_bottom_part6(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);
t_list				*sort_list_u3_to_bottom_part7(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);
t_list				*sort_list_u3_to_bottom_part8(t_list *alist,
						t_list *ans_list);
t_list				*sort_list_u3_to_bottom_part9(t_list *alist,
						t_list *ans_list, int *sn, int *flag);

t_list				*sort_list_u3_to_other(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*sort_list_u3_to_other_part1(t_list *alist, t_list *blist,
						t_list *ans_list, int *alist_top);

int					list_min_limit(t_list *list, int num);
void				list_initialize(t_list *alist, t_list *blist,
						t_list *ans_list, t_list *block_list);
t_list				*list_initial_make(t_list *alist, int *array, int argc);

void				integrate_pb_pa_part(t_list *list, t_node *tmp_ptr);
void				integrate_pb_pa(t_list *list);
void				integrate_rb_ra(t_list *list);
void				ft_integrate(t_list *ans_list);
void				integarate_pb_ra_pa_part(t_node **tmp_ptr, int *cnt);
void				integarate_pb_ra_pa(t_list *list);
void				integrate_sb_pa_ra_pa_ra_part(t_node *tmp_ptr);
void				integrate_sb_pa_ra_pa_ra(t_list *list);
void				integarate_pb_pb_rb_pa_part(t_node **tmp_ptr, int *cnt,
						t_list *ans_list);
void				integarate_pb_pb_rb_pa(t_list *list);
void				integarate_pa_pa_ra_pb_part(t_node **tmp_ptr, int *cnt,
						t_list *ans_list);
void				integarate_pa_pa_ra_pb(t_list *list);

t_list				*ft_solve(t_list *alist, t_list *blist, t_list *ans_list,
						t_list *block_list);
t_list				*ft_solve_part1(t_list *alist, t_list *blist,
						t_list *ans_list, int len);
t_list				*ft_solve_part2(t_list *alist, t_list *blist,
						t_list *ans_list, t_list *block_list);

#endif
