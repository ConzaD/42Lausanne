/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:19:30 by dconza            #+#    #+#             */
/*   Updated: 2023/12/02 14:09:09 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

static void	push(t_stack **src, t_stack **dest);
void		pa(t_stack **stack_a, t_stack **stack_b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
static void	swap(t_stack *stack);
void		sa(t_stack **stack_a, int j);
void		sb(t_stack **stack_b, int j);
void		ss(t_stack **stack_a, t_stack **stack_b, int j);
static void	rotate(t_stack **stack);
void		ra(t_stack **stack_a, int j);
void		rb(t_stack **stack_b, int j);
void		rr(t_stack **stack_a, t_stack **stack_b, int j);
static void	rev_rotate(t_stack **stack);
void		rrr(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **stack_a, int j);
void		rrb(t_stack **stack_b, int j);

void		ft_fill_b(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sort_b(t_stack **stack_a);
t_stack		**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **stack_a);

int		ft_checksorted(t_stack *stack_a);
int		ft_isalpha(int c);
void	alpha_check(char **argv);
int		check_args(char **argv);
int		ft_checkdup(t_stack *a);

int		rotation_one(t_stack **a, t_stack **b, int c, char s);
int		rotation_two(t_stack **a, t_stack **b, int c, char s);
int		rotation_three(t_stack **a, t_stack **b, int c, char s);
int		rotation_four(t_stack **a, t_stack **b, int c, char s);
int		calculate_rotation_one(t_stack *a, t_stack *b, int c);
int		calculate_rotation_two(t_stack *a, t_stack *b, int c);
int		calculate_rotation_three(t_stack *a, t_stack *b, int c);
int		calculate_rotation_four(t_stack *a, t_stack *b, int c);

t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_sort_three(t_stack **stack_a);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);
int		ft_find_index(t_stack *a, int nbr);

void	ft_free(t_stack **lst);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);
t_stack	*ft_stack_new(int content);

long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
void		ft_error(void);
void		list_args(char **argv, t_stack **stack_a);
t_stack	*ft_parse(int argc, char **argv);

static int	count_words(const char *str, char c);
static char	*word_dup(const char *str, int start, int finish);
char	**ft_split(char const *s, char c);
void	ft_freestr(char **lst);
t_stack	*ft_parse_args_quoted(char **argv);

#endif
