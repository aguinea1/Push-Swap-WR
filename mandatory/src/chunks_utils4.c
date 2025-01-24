/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:44:42 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 19:34:55 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_three_norm_mid2(t_stack **a, t_stack **b, t_chunk *chunk)
{
	rrr(a, b, 2);
	rrr(a, b, 2);
	pb(a, b, 2);
	rra(a, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	if (chunk->min_size == 3)
	{
		rrb(b, 2);
		ft_check_swap(a, b);
	}
	ft_check_swap(a, NULL);
}

static void	sort_three_norm_mid(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid->prev->order == 3)
	{
		rrr(a, b, 2);
		rrr(a, b, 2);
		ft_check_swap(a, b);
		if (chunk->min_size == 3)
		{
			rrr(a, b, 2);
			ft_check_swap(a, b);
		}
		else
		{
			rra(a, 2);
			ft_check_swap(a, NULL);
		}
	}
	else
		sort_three_norm_mid2(a, b, chunk);
}

void	sort_bottom_three_mid_norm(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid->order == 3)
	{
		rrr(a, b, 2);
		rrr(a, b, 2);
		if (chunk->min_size == 3)
			rrr(a, b, 2);
		else
			rra(a, 2);
		ft_check_swap(a, b);
	}
	else
		sort_three_norm_mid(a, b, chunk);
}

void	sorted_mid_norm(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->min_size == 4)
	{
		rrr(a, b, 2);
		rrr(a, b, 2);
		rrr(a, b, 2);
	}
	else if (chunk->min_size == 3)
	{
		rrr(a, b, 2);
		rrr(a, b, 2);
		rra(a, 2);
	}
}
