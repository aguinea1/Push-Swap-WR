/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:29:35 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/28 17:36:42 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	spec_resolve(t_stack **a, t_stack **b)
{
	t_chunk	*chunk;

	chunk = split_chunk(a, b, ft_stacksize(*a), a);
	recursive_chunk(a, b, chunk, 3);
	recursive_chunk(a, b, chunk, 2);
	recursive_chunk(a, b, chunk, 1);
	ft_rem_chunk(&chunk);
}

static t_chunk	*decide_chunk_mid(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (where_is_mid(chunk->mid, *a) == 0)
	{
		if (ft_is_bottom(chunk->mid, *b) == 0)
			return (split_chunk(b, a, chunk->mid_size, a));
		else
			return (splchunkbot(b, a, chunk->mid_size, a));
	}
	else
	{
		if (ft_is_bottom(chunk->mid, *a) == 0)
			return (split_chunk(a, b, chunk->mid_size, a));
		else
			return (splchunkbot(a, b, chunk->mid_size, a));
	}
}

t_chunk	*decide_chunk(t_stack **a, t_stack **b, t_chunk *chunk, int flag)
{
	t_chunk	*result;

	if (flag == 1)
	{
		if (ft_is_bottom(chunk->min, *b) == 0
			|| ft_lonely(chunk->min, chunk->min_size, *b) == 1)
			return (result = split_chunk(b, a, chunk->min_size, a), result);
		else
			return (result = splchunkbot(b, a, chunk->min_size, a), result);
	}
	else if (flag == 3)
	{
		if (ft_is_bottom(chunk->top, *a) == 0
			|| ft_lonely(ft_lastnode(*a), chunk->top_size, *a) == 1)
			return (result = split_chunk(a, b, chunk->top_size, a), result);
		else
			return (result = splchunkbot(a, b, chunk->top_size, a), result);
	}
	else
		return (result = decide_chunk_mid(a, b, chunk), result);
}

void	recursive_chunk(t_stack **a, t_stack **b, t_chunk *chunk, int flag)
{
	t_chunk	*new;

	if (chunk->divison < 13)
	{
		small_sort(a, b, chunk, flag);
		return ;
	}
	new = decide_chunk(a, b, chunk, flag);
	recursive_chunk(a, b, new, 3);
	recursive_chunk(a, b, new, 2);
	recursive_chunk(a, b, new, 1);
	ft_rem_chunk(&new);
}
