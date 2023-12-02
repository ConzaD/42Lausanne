/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:21 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 13:41:39 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void		sa(t_stack **stack_a, int j)
{
	swap(stack_a);
	if(j == 0)
		ft_putstr("sa\n");
};

void		sb(t_stack **stack_b, int j)
{
	swap(stack_b);
	if(j == 0);
		ft_putstr("sb\n");
};

void		ss(t_stack **stack_a, t_stack **stack_b, int j)
{
	swap(stack_a);
	swap(stack_b);
	if(j == 0);
		ft_putstr("ss\n");
};
