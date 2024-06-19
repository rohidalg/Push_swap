/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:05 by rohidalg          #+#    #+#             */
/*   Updated: 2024/06/19 18:20:14 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void ft_check_argv(int argc, char **argv);
void ft_print_list(t_list *stack);
void	ft_free_stack(t_list **stack);
int swap(t_list **stack);
int sa(t_list **stack);
int sb(t_list **stack);
int ss(t_list **stack_a, t_list **stack_b);
int push(t_list **stack_to, t_list  **stack_from);

#endif