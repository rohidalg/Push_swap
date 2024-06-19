/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:38 by rohidalg          #+#    #+#             */
/*   Updated: 2024/06/19 15:41:49 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **stack)
{
	t_list	*nmb;
	t_list	*tmp;

	nmb = *stack;
	while (nmb)
	{
		tmp = nmb;
		nmb = nmb->next;
		free(tmp);
	}
	free(stack);
}