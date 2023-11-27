/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:19:30 by dconza            #+#    #+#             */
/*   Updated: 2023/11/27 11:34:44 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

static void	push(t_stack **src, t_stack **dest);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
static void	swap(t_stack *stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
static void	rotate(t_stack **stack);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
static void	rev_rotate(t_stack **stack);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

void	ft_fill_b(t_stack **stack_a, t_stack **stack_b);

int	ft_checksorted(t_stack *stack_a);

int	rotation_one(t_stack **a, t_stack **b, int c, char s);
int	rotation_two(t_stack **a, t_stack **b, int c, char s);
int	rotation_one_bis(t_stack **a, t_stack **b, int c, char s);
int	rotatiob_two_bis(t_stack **a, t_stack **b, int c, char s);
int	calculate_rotation_one(t_stack *a, t_stack *b, int c);
int	calculate_rotation_two(t_stack *a, t_stack *b, int c);
int	calculate_rotation_one_bis(t_stack *a, t_stack *b, int c);
int	calculate_rotation_two_bis(t_stack *a, t_stack *b, int c);

t_stack	*ft_lstlast(t_stack *lst);
int	ft_lstsize(t_stack *lst);
int	ft_find_place_a(t_stack *stack_a, int nbr_push);
int	ft_find_place_b(t_stack *stack_b, int nbr_push);
int	ft_min(t_stack *a);
int	ft_max(t_stack *a);
int	ft_find_index(t_stack *a, int nbr);

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *newest);
int			get_stack_size(t_stack	*stack);

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
void	exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
