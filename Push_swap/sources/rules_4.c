/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:32 by dconza            #+#    #+#             */
/*   Updated: 2023/12/09 11:32:28 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rra(t_stack **stack_a, int j)
{
	rev_rotate(stack_a);
	if(j == 0);
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, int j)
{
	rev_rotate(stack_b);
	if(j == 0);
		ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int j)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if(j == 0);
		ft_putstr("rrr\n");
}
