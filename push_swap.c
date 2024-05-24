/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:28:41 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/24 15:20:29 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void ft_check_argv(t_list_ps **stack, int argc, char **argv)
// {
//     char **args;
//     // int i;
    
//     // i = 0;
//     if (argc == 2)
//         args = ft_split(argv[1], ' ');
//     else
//     {
//         // i = 1;
//         args = argv;
//     }
//     printf("%d\n", **args);
// }

int main (int argc, char **argv)
{
    if (argc < 2)
        return (-1);
    
    printf("%d\n", **argv);
    
    return (0);
}

// ** crea algotimos para 2,3,4,5 numeros y luego uno mas para el resto.
// ** comprueba que esten ordenados

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

