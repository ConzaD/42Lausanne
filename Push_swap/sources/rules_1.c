/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:07 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 13:41:35 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*dest)
		return ;
	tmp = *src;
	*src = *dest;
	*dest = (*dest)->next;
	(*src)->next = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int j)
{
	push(stack_a, stack_b)
	if(j == 0);
		ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	push(stack_b, stack_a)
	if(j == 0);
		ft_putstr("pa\n");
}
