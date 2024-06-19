/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:49 by rohidalg          #+#    #+#             */
/*   Updated: 2024/06/19 18:50:11 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list **stack)
{
    t_list *first;
    t_list *next;
    int tmp_nmb;
    int tmp_index;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    first = *stack;
    next = first->next;
    if (!first || !next)
        ft_putendl_fd("ERROR_SWAP", 1);
    tmp_nmb = first->nmb;
    tmp_index= first->index;
    first->nmb = next->nmb;
    first->index = next->index;
    next->nmb = tmp_nmb;
    next->index = tmp_index;
    return(0);
}

int sa(t_list **stack_a)
{
    if (swap(stack_a) == -1)
        return(-1);
    ft_putendl_fd("sa", 1);
    return(0);
}

int sb(t_list **stack_b)
{
    if (swap(stack_b) == -1)
        return(-1);
    ft_putendl_fd("sb", 1);
    return(0);
}

int ss(t_list **stack_a, t_list **stack_b)
{
    if (swap(stack_a) == -1 || swap(stack_b) == -1)
        return(-1);
    ft_putendl_fd("ss",1);
    return(0);
}

// int push(t_list **stack_to, t_list  **stack_from)
// {
//     t_list  *tmp;
//     t_list  *first_to;
//     t_list  *first_from;

//     if (ft_lstsize(*stack_from) == 0)
//         return(-1);
//     first_to = *stack_to;
//     first_from = *stack_from;
//     tmp = first_from;
//     first_from = first_from->next;
//     *stack_from = first_to;
// }

// int pa(t_list **stack_b, t_list **stack_a)
// {
    
// }

// sa = swap a // intercambia los 2 elementos superiores de la pila a
// sb = swap b // intercambia los 2 elementos superiores de la pila b
// ss = swap a + swap b // tanto sa como sb
// pa = push a // mueve el elemento superior de la pila b a la parte superior de la pila a
// pb = push b // mueve el elemento superior de la pila a a la parte superior de la pila b
// ra = rotate a // desplaza todos los elementos de la pila a de abajo hacia arriba
// rb = rotate b // desplaza todos los elementos de la pila b de abajo hacia arriba
// rr = rotate a + rotate b // tanto ra como rb
// rra = reverse rotate a // desplaza todos los elementos de la pila a de arriba a abajo
// rrb = reverse rotate b // desplaza todos los elementos de la pila b de arriba a abajo
// rrr = reverse rotate a + reverse rotate b // tanto rra como rrb