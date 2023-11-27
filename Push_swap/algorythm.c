/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:54:58 by dconza            #+#    #+#             */
/*   Updated: 2023/11/27 10:52:36 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fill_stack_b_first(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    if (stack_b < (*stack_b)->next)
        rb(stack_b);   
};

void    fill_stack_b_second(t_stack **stack_a, t_stack **stack_b)
{
    int tmp;

    pb(stack_a, stack_b);
    tmp = (*stack_b)->next;
    if (stack_b < tmp)
    {

    }

};

void    sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_b)
    {
        /*i guess work*/
    }
}