/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:54:58 by dconza            #+#    #+#             */
/*   Updated: 2023/11/27 11:30:42 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == calculate_rotation_one(*stack_a, *stack_b, tmp->nbr))
				i = rotation_one(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == calculate_rotation_two(*stack_a, *stack_b, tmp->nbr))
				i = rotation_two(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == calculate_rotation_one_bis(*stack_a, *stack_b, tmp->nbr))
				i = rotation_one_bis(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == calculate_rotation_two_bis(*stack_a, *stack_b, tmp->nbr))
				i = rotation_two_bis(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}
