/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:54:58 by dconza            #+#    #+#             */
/*   Updated: 2023/12/09 11:38:06 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if (i == calculate_rotation_one(*stack_a, *stack_b, tmp->value))
				i = rotation_one(stack_a, stack_b, tmp->value, 'a');
			else if (i == calculate_rotation_two(*stack_a, *stack_b, tmp->value))
				i = rotation_two(stack_a, stack_b, tmp->value, 'a');
			else if (i == calculate_rotation_three(*stack_a, *stack_b, tmp->value))
				i = rotation_three(stack_a, stack_b, tmp->value, 'a');
			else if (i == calculate_rotation_four(*stack_a, *stack_b, tmp->value))
				i = rotation_four(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == calculate_rotation_one(*stack_a, *stack_b, tmp->value))
				i = rotation_one(stack_a, stack_b, tmp->value, 'b');
			else if (i == calculate_rotation_three(*stack_a, *stack_b, tmp->value))
				i = rotation_three(stack_a, stack_b, tmp->value, 'b');
			else if (i == calculate_rotation_two(*stack_a, *stack_b, tmp->value))
				i = rotation_two(stack_a, stack_b, tmp->value, 'b');
			else if (i == calculate_rotation_four(*stack_a, *stack_b, tmp->value))
				i = rotation_four(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				rra(stack_a, 0);
		}
	}
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
