/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_mid_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:37:45 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/18 20:49:48 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_mid_bottom_four(t_stack **a, t_stack **b)
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

static void	sort_bottom_three_mid(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid->order == 3)
	{
		rra(a, 2);
		rra(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
	else if (chunk->mid->prev->order == 3)
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

void	sort_mid_bot(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid_size == 2)
	{
		rra(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
	else if (chunk->mid_size == 3)
		sort_bottom_three_mid(a, b, chunk);

	else
	{
		if (chunk->mid->prev->prev->order == 4 || chunk->mid->prev->prev->prev->order == 4)
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
		else
			sort_mid_bottom_four(a, b);
	}
}
