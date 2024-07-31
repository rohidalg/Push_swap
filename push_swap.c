/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:28:41 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/25 19:24:55 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->nmb, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

static void	ft_putin_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_argv(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_putin_stack(stack_a, argc, argv);
	printf("===============\n");
	ft_print_list(*stack_a);
	printf("---------------\n");
	ft_print_list(*stack_b);
	printf("===============\n");
	
	ft_options(stack_a, stack_b);
	
	printf("===============\n");
	ft_print_list(*stack_a);
	printf("---------------\n");
	ft_print_list(*stack_b);
	printf("===============\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

// ** crea algotimos para 2,3,4,5 numeros y luego uno mas para el resto.
// ** comprueba que esten ordenados

// sa = swap a // intercambia los 2 elementos superiores de la pila a
// sb = swap b // intercambia los 2 elementos superiores de la pila b
// ss = swap a + swap b // tanto sa como sb
// pa = push a
	// mueve el elemento superior de la pila b a la parte superior de la pila a
// pb = push b
	// mueve el elemento superior de la pila a a la parte superior de la pila b
// ra = rotate a
	// desplaza todos los elementos de la pila a de abajo hacia arriba
// rb = rotate b
	// desplaza todos los elementos de la pila b de abajo hacia arriba
// rr = rotate a + rotate b // tanto ra como rb
// rra = reverse rotate a
	// desplaza todos los elementos de la pila a de arriba a abajo
// rrb = reverse rotate b
	// desplaza todos los elementos de la pila b de arriba a abajo
// rrr = reverse rotate a + reverse rotate b // tanto rra como rrb
