/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_mid_bot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:14 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/20 17:14:34 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_mid_bottom_four(t_stack **a, t_stack **b, t_chunk *chunk)
{
	rrr(a, b, 2);
	rrr(a, b, 2);
	rrr(a, b, 2);
	pb(a, b, 2);
	rra(a, 2);
	pb(a, b, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, b);
	if (chunk->min_size == 4)
		rrb(b, 2);
}

static void	sort_bottom_three_mid(t_stack **a, t_stack **b, t_chunk *chunk)
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
	else if (chunk->mid->prev->order == 3)
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
}

void	sort_mid_and_min_bot(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid_size == 2)
	{
		rrr(a, b, 2);
		rrr(a, b, 2);
		ft_check_swap(a, b);
	}
	else if (chunk->mid_size == 3)
		sort_bottom_three_mid(a, b, chunk);

	else
	{
		if (chunk->mid->prev->prev->order == 4 || chunk->mid->prev->prev->prev->order == 4)
		{
			rrr(a, b, 2);
			rrr(a, b, 2);
			pb(a, b, 2);
			pb(a, b, 2);
			rra(a, 2);
			rra(a, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			pa(a, b, 2);
			ft_check_swap(a, b);
			rrb(b, 2);
			if (chunk->min_size == 4)
				rrb(b, 2);
		}
		else
			sort_mid_bottom_four(a, b, chunk);
	}
}

