/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:05 by rohidalg          #+#    #+#             */
/*   Updated: 2024/11/14 14:35:58 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define MAX 2147483648
# define MIN -2147483648

typedef struct s_stack
{
	struct s_list		*first;
	struct s_move		*move;
	struct s_cheap		*cheap;
	struct s_extremes	*extremes;
}						t_stack;

typedef struct s_move
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_move;

typedef struct s_cheap
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;

typedef struct s_extremes
{
	int					min_a;
	int					max_a;
	int					min_b;
	int					max_b;
}						t_extremes;

void					ft_check_argv(int argc, char **argv);
void					ft_print_list(t_list *stack);
void					ft_free_stack(t_list **stack);
int						swap(t_list **stack);
int						sa(t_list **stack);
int						sb(t_list **stack);
int						ss(t_list **stack_a, t_list **stack_b);
int						push(t_list **stack_to, t_list **stack_from);
int						pa(t_list **stack_b, t_list **stack_a);
int						pb(t_list **stack_a, t_list **stack_b);
int						rotate(t_list **stack_from);
int						ra(t_list **stack_a);
int						rb(t_list **stack_b);
int						rr(t_list **stack_a, t_list **stack_b);
int						reverse_rotate(t_list **stack_from);
int						rra(t_list **stack_a);
int						rrb(t_list **stack_b);
int						rrr(t_list **stack_a, t_list **stack_b);
int						ft_little_num(t_list **stack_from, int lit);
int						ft_high_num(t_list **stack_from, int max);
void					ft_next(t_list **stack_from, t_list **stack_to);
int						ft_distance(t_list **stack_from, int nmb);
int						ft_order(t_list **stack_from);
void					ft_three_num(t_list **stack_a, t_list **stack_b);
void					ft_four_num(t_list **stack_a, t_list **stack_b);
void					ft_five_num(t_list **stack_a, t_list **stack_b);
void					ft_options(t_list **stack_from, t_list **stack_to);
void					ft_more_five(t_list **stack_a, t_list **stack_b);

#endif