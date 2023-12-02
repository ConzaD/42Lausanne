/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:14:39 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 13:41:22 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotation_one(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->value != c)
			ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->value != c)
			rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	rotation_two(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->value != c)
			rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	rotation_one_bis(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->value != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	rotation_two_bis(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
