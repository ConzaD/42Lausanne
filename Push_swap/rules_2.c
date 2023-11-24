/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:21 by dconza            #+#    #+#             */
/*   Updated: 2023/11/23 20:13:41 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void		sa(t_stack **stack_a){
	swap(*stack_a);
	ft_putstr("sa\n");
};

void		sb(t_stack **stack_b){
	swap(*stack_b);
	ft_putstr("sb\n");
};

void		ss(t_stack **stack_a, t_stack **stack_b){
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
};
