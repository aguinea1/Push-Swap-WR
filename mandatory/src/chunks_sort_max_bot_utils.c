/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_max_bot_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:10:02 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 19:43:40 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	sort_max_top_norm(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (((*a)->next->next->next->order == 4) || (chunk->top_size == 3))
		sort_three_top_norm(a);
	else if ((*a)->next->next->order == 4)
	{
		pb(a, b, 2);
		pb(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
		sort_four_norm(a, b);
}

void	sort_max_top_norm_base(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk_is_sorted(*a, chunk->top_size) == 1)
		return ;
	if (chunk->top_size == 2)
	{
		ft_check_swap(a, NULL);
		return ;
	}
	if (lonely_max(a, chunk) == 1)
	{
		lonely_max_sort(a, b, chunk);
		return ;
	}
	else
		sort_max_top_norm(a, b, chunk);
}

void	sort_three_top_norm(t_stack **a)
{
	if ((*a)->next->next->order == 3)
	{
		if ((*a)->next->order == 1)
			sa(a, 2);
		return ;
	}
	if ((*a)->next->order == 3)
	{
		ra(a, 2);
		sa(a, 2);
		rra(a, 2);
		if ((*a)->order == 2)
			sa(a, 2);
		return ;
	}
	if ((*a)->order == 3)
	{
		sa(a, 2);
		ra(a, 2);
		sa(a, 2);
		rra(a, 2);
		ft_check_swap(a, NULL);
	}
}
