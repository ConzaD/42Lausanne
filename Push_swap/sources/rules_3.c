/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:08:02 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 13:41:42 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ra(t_stack **stack_a, int j)
{
	rotate(stack_a);
	if(j == 0)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, int j)
{
	rotate(stack_b);
	if(j == 0)
		ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	rotate(stack_a);
	rotate(stack_b);
	if(j == 0)
		ft_putstr("rr\n");
}
