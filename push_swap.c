/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:28:41 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/05 16:38:36 by rohidalg         ###   ########.fr       */
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
// imprime todos los numeros de la lista

void	ft_return(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	distance;

	size = ft_lstsize(*stack_b);
	distance = ft_distance(stack_b, stack->max_b);
	while (distance-- != 0)
		rb(stack_b);
	while (size-- != 0)
		pa(stack_b, stack_a);
}
// busca el max y lo pone el primero y de ahi lo develve al stack_a

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
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}
// mete los numeros al final del stack

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	ft_check_argv(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_putin_stack(stack_a, argc, argv);
	ft_options(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
