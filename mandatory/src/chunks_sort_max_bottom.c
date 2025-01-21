/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_max_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:02:24 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/20 21:15:40 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_max_bottom_four(t_stack **a, t_stack **b)
{
	rra(a, 2);
	rra(a, 2);
	rra(a, 2);
	pb(a, b, 2);
	rra(a, 2);
	pb(a, b, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

static void	sort_bottom_three_max(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->top->order == 3)
	{
		rra(a, 2);
		rra(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
	else if (chunk->top->prev->order == 3)
	{
		rra(a, 2);
		rra(a, 2);
		sa(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
	else
	{
		rra(a, 2);
		rra(a, 2);
		pb(a, b, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}

static	void	sort_four_max_a(t_stack **a, t_stack **b)
{
	rra(a, 2);
	rra(a, 2);
	pb(a, b, 2);
	pb(a, b, 2);
	rra(a, 2);
	rra(a, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

/*static void	sorted_top(t_stack **a, t_chunk *chunk)
{
	rra(a, 2);
	if (chunk->top_size == 2)
		rra(a, 2);
	else if (chunk->top_size == 3)
	{
		rra(a, 2);
		rra(a, 2);
	}
	else if(chunk->top_size == 4)
	{
		rra(a, 2);
		rra(a, 2);
		rra(a, 2);
	}
}*/
void	sort_max_bot(t_stack **a, t_stack **b, t_chunk *chunk)
{
/*	if (is_bot_sorted_rev(ft_lastnode(*a), chunk->top_size) == 1)
	{
		sorted_top(a, chunk);
		return ;
	}*/
	if (chunk->top_size == 2)
	{
		rra(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
	else if (chunk->top_size == 3)
		sort_bottom_three_max(a, b, chunk);
	else
	{
		if (chunk->top->prev->prev->prev->order == 4
			|| chunk->top->prev->prev->order == 4)
			sort_four_max_a(a, b);
		else
			sort_max_bottom_four(a, b);
	}
}
