/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_double_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:18 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/20 20:58:12 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void deal_rr_min(t_stack **analyze, t_stack **split, int max, t_chunk *new)
{
	pb(analyze, split, 2);
	if (max == 0)
		new->top = *analyze;
	rr(analyze, split, 2);
}

void deal_rr_mid(t_stack **analyze, t_stack **split, int mid, t_chunk *chunk)
{
	if (mid == 0)
		chunk->mid = *analyze;
	pa(split, analyze, 2);
	rr(analyze, split, 2);
}

int		is_bot_sorted(t_stack *stack, int size)
{
	int	i;
	t_stack *tail;

	i = 0;
	tail = stack;
	while (++i < size)
	{
		if (tail->order > tail->prev->order)
			return (0);
		tail = tail->prev;
	}
	return (1);
}

int	is_bot_sorted_rev(t_stack *stack, int size)
{
	int	i;
	t_stack *tail;

	i = 0;
	tail = stack;
	while (++i < size)
	{
		if (tail->order < tail->prev->order)
			return (0);
		tail = tail->prev;
	}
	return (1);
}





