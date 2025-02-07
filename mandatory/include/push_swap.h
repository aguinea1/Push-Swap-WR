/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:01 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 22:54:09 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				order;
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

typedef struct s_chunk
{
	struct s_stack	*top;
	int				top_size;
	int				top_count;
	struct s_stack	*mid;
	int				mid_size;
	int				mid_count;
	struct s_stack	*min;
	int				min_size;
	int				min_count;
	int				divison;
	struct s_stack	**stack;
}	t_chunk;

// MAIN, PARSING AND NODE CREATION

int		main(int ac, char **av);
int		error_int(char **av);
int		error_dup(char **arr);
int		error_syntax(char	**arr);
void	new_node(t_stack **a, char **av);
void	append_node(t_stack **a, int n);
void	error_free(t_stack **a);
long	ft_atol(const char *nptr);

// MOVES
void	swap(t_stack **stack);
void	sa(t_stack **b, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b, int check);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack	**a, t_stack **b, int check);
void	pb(t_stack	**a, t_stack **b, int check);
void	rotate(t_stack **stack);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b, int check);
void	reverserotate(t_stack **stack);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b, int check);

// UTILS && MORE
int		ft_stacksize(t_stack *lst);
t_stack	*ft_lastnode(t_stack *lst);
t_stack	*biggest_node(t_stack	**stack);
int		is_sorted(t_stack *stack);
t_stack	*find_first(t_stack *last);

// LITTLE SORT
void	sort_three(t_stack **a);
void	sort_two(t_stack **a);
void	alg_sort(t_stack **a, t_stack **b, int ac);

//ALGORITHM

// UTILS && MORE
int		lonely_max(t_stack **a, t_chunk *chunk);
void	small_nbr_reverse(t_stack *a, int size);
int		check_max(t_stack *a, t_stack *last_max);
int		check_stack(t_stack **a, t_chunk *chunk);
void	small_nbr(t_stack *a, int size);
void	min_is_top(t_stack **a, t_stack **b, t_chunk *chunk);
t_stack	*find_mid(t_stack *c_analyze, t_chunk *new);
int		ft_is_bottom(t_stack *check, t_stack *list);
int		where_is_mid(t_stack *mid, t_stack *stack);
int		ft_lonely(t_stack *check, int size, t_stack *list);
int		min_on_top(t_stack **b, t_chunk *chunk);
void	ft_deal_else(t_stack **split, t_chunk *new, t_stack **ana, int *max);
void	ft_rem_chunk(t_chunk **chunk);

// DEALS && SPLITS
void	ft_deal(t_chunk *new, t_stack **analyze, t_stack **split, t_stack **a);
void	deal_bot(t_stack **split, t_stack **analyze, t_chunk *new, t_stack **a);
t_chunk	*splchunkbot(t_stack **analyze, t_stack **split, int size, t_stack **a);
t_chunk	*split_chunk(t_stack **analyze, t_stack **split, int size, t_stack **a);
void	deal_max(t_stack **analyze, t_stack **split, t_stack **a, int up);
void	deal_min(t_stack **analyze, t_stack **split, t_stack **a, int up);
void	deal_mid(t_stack **analyze, t_stack **split, t_stack **a, int up);

// MINI SORTS
void	sort_mid_bot(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_bot_a_two(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_three_top(t_stack **a);
void	ft_check_swap(t_stack **a, t_stack **b);
void	sort_min_2(t_stack **b, t_stack **a, t_chunk *chunk);
void	sort_min(t_stack **b, t_stack **a, t_chunk *chunk);
void	sort_mid_two(t_stack **a, t_stack **b);
void	sort_mid_three(t_stack **a, t_stack **b);
void	sort_mid(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_max(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_max_top(t_stack **a, t_stack **b, t_chunk *chunk);
void	small_sort(t_stack **a, t_stack **b, t_chunk *new, int flag);
void	sort_max_bot(t_stack **a, t_stack **b, t_chunk *chunk);
void	min_lonely_sort(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_min_three_bot(t_stack **a, t_stack **b);
void	min_is_top_else(t_stack **a, t_stack **b);
t_stack	*small_nbr_node(t_stack *node, int *current_order, int *min);
void	lonely_max_sort_four_part2(t_stack **a, t_stack **b);
void	lonely_sort_max_four(t_stack **a, t_stack **b);
void	lonely_max_sort(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_four_norm(t_stack **a, t_stack **b);
void	sort_max_top_norm_base(t_stack **a, t_stack **b, t_chunk *chunk);
void	sort_three_top_norm(t_stack **a);
void	lonely_max_sort(t_stack **a, t_stack **b, t_chunk *chunk);
void	lonely_sort_max_four(t_stack **a, t_stack **b);
void	lonely_max_sort_four_part2(t_stack **a, t_stack **b);
void	sort_bottom_three_mid_norm(t_stack **a, t_stack **b, t_chunk *chunk);
void	sorted_mid_norm(t_stack **a, t_stack **b, t_chunk *chunk);
void	sorted_mid_norm_spl(t_stack **a, t_stack **b, t_chunk *chunk);

// RECURSIVE && MORE
t_chunk	*decide_chunk(t_stack **a, t_stack **b, t_chunk *chunk, int flag);
void	recursive_chunk(t_stack **a, t_stack **b, t_chunk *chunk, int flag);
void	spec_resolve(t_stack **a, t_stack **b);

// OPTIMIZATIONS
void	deal_rr_mid(t_stack **analyze, t_stack **split, int *mid, t_chunk *new);
void	deal_rr_min(t_stack **analyze, t_stack **split, int *max, t_chunk *new);
void	sort_mid_and_min_bot(t_stack **a, t_stack **b, t_chunk *chunk);
int		chunk_is_sorted_reverse(t_stack *a, int size);
int		chunk_is_sorted(t_stack *a, int size);
int		is_bot_sorted(t_stack *stack, int size);
int		is_bot_sorted_rev(t_stack *stack, int size);
void	min_top_4_part2(t_stack **a, t_stack **b);
#endif
