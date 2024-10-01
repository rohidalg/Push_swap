/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2024/10/01 14:00:22 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_double(t_stack *stack)
{
    stack->move->rr = 0;
    stack->move->rrr = 0;

    while(stack->move->ra != 0 && stack->move->rb != 0)
    {
        stack->move->ra--;
        stack->move->rb--;
        stack->move->rr++;
    }
    while(stack->move->rra != 0 && stack->move->rrb != 0)
    {
        stack->move->rra--;
        stack->move->rrb--;
        stack->move->rrr++;
    }
}

