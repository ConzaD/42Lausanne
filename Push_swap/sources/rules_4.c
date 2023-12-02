/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:30:32 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 13:41:45 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
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
