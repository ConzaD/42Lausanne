/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:32:13 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 14:17:32 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->value = 0;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = calculate_rotation_two(a, b, b->value);
	while (tmp)
	{
		if (i > calculate_rotation_one(a, b, tmp->value))
			i = calculate_rotation_one(a, b, tmp->value);
		if (i > calculate_rotation_two(a, b, tmp->value))
			i = calculate_rotation_two(a, b, tmp->value);
		if (i > calculate_rotation_three(a, b, tmp->value))
			i = calculate_rotation_three(a, b, tmp->value);
		if (i > calculate_rotation_four(a, b, tmp->value))
			i = calculate_rotation_four(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = calculate_rotation_two(a, b, a->value);
	while (tmp)
	{
		if (i > calculate_rotation_one(a, b, tmp->value))
			i = calculate_rotation_one(a, b, tmp->value);
		if (i > calculate_rotation_two(a, b, tmp->value))
			i = calculate_rotation_two(a, b, tmp->value);
		if (i > calculate_rotation_three(a, b, tmp->value))
			i = calculate_rotation_three(a, b, tmp->value);
		if (i > calculate_rotation_four(a, b, tmp->value))
			i = calculate_rotation_four(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->value = content;
	new->next = NULL;
	return (new);
}
