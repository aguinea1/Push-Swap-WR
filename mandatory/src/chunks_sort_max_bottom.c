/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_max_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:02:24 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/19 02:55:02 by aguinea          ###   ########.fr       */
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

void	sort_max_bot(t_stack **a, t_stack **b, t_chunk *chunk)
{
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
