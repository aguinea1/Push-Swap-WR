/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:29:21 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 14:26:24 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_min_four_2(t_stack **a, t_stack **b)
{
	pa(a, b, 2);
	rrb(b, 2);
	if ((*b)->order == 4)
	{
		pa(a, b, 2);
		rrb(b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
	{
		rrb(b, 2);
		pa(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}

static void	sort_min_4(t_stack **b, t_stack **a)
{
	rrb(b, 2);
	rrb(b, 2);
	if ((*b)->order == 4 || (*b)->next->order == 4)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		rrb(b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
		sort_min_four_2(a, b);
}

static void	sorted_min_two(t_stack **a, t_stack **b, int size)
{
	rrb(b, 2);
	pa(a, b, 2);
	if (size == 2)
	{
		rrb(b, 2);
		pa(a, b, 2);
	}
	else if (size == 3)
	{
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
	}
	else if (size == 4)
	{
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
	}
}

static void	sorted_min_one(t_stack **a, t_stack **b, int size)
{
	rrb(b, 2);
	if (size == 2)
	{
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (size == 3)
	{
		rrb(b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (size == 4)
	{
		rrb(b, 2);
		rrb(b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
}

void	sort_min(t_stack **b, t_stack **a, t_chunk *chunk)
{
	if (min_on_top(b, chunk) == 1)
	{
		min_is_top(a, b, chunk);
		return ;
	}
	if (is_bot_sorted_rev(ft_lastnode(*b), chunk->min_size) == 1)
	{
		sorted_min_two(a, b, chunk->min_size);
		return ;
	}
	if (is_bot_sorted(ft_lastnode(*b), chunk->min_size) == 1)
	{
		sorted_min_one(a, b, chunk->min_size);
		return ;
	}
	if (chunk->min_size == 4)
	{
		sort_min_4(b, a);
		return ;
	}
	if (chunk->min_size == 3)
		sort_min_three_bot(a, b);
	else
		sort_min_2(b, a, chunk);
}
