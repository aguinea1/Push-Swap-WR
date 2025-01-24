/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:15:25 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 22:52:29 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"
#include "../libft/libft.h"
/*
static void	ft_rem_chunk(t_chunk **chunk)
{
	(*chunk)->min_size = 0;
	(*chunk)->top_size = 0;
	(*chunk)->mid_size = 0;
	(*chunk)->top = NULL;
	(*chunk)->mid = NULL;
	(*chunk)->min = NULL;
	free (*chunk);
}*/
static t_chunk	*ft_pointers(t_stack **split, t_chunk *new, int b)
{
	if (b == 0)
	{
		new->mid = NULL;
		new->mid = ft_lastnode(*split);
	}
	return (new);
}

static t_chunk	*splitdebo(t_stack **s, t_stack **an, t_chunk *new, t_stack **a)
{
	deal_bot(s, an, new, a);
	if (a != an)
		new = ft_pointers(s, new, 0);
	return (new);
}

t_chunk	*splchunkbot(t_stack **analyze, t_stack **split, int size, t_stack **a)
{
	t_chunk	*new;

	new = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new)
		return (NULL);
	new->divison = size;
	new->min_size = (size / 3);
	if (size % 3 == 2)
	{
		new->mid_size = (size / 3) + 1;
		new->top_size = (size / 3) + 1;
	}
	else if (size % 3 == 1)
	{
		new->mid_size = (size / 3);
		new->top_size = (size / 3) + 1;
	}
	else
	{
		new->mid_size = size / 3;
		new->top_size = (size / 3);
	}
	new = splitdebo(split, analyze, new, a);
	return (new);
}

static t_chunk	*spldeal(t_stack **an, t_stack **a, t_stack **spl, t_chunk *new)
{
	ft_deal(new, an, spl, a);
	if (an != a)
		new = ft_pointers(spl, new, 0);
	if (an != a)
		new->min = ft_lastnode(*an);
	else
		new->min = ft_lastnode(*spl);
	if (an == a)
		new->top = ft_lastnode(*an);
	return (new);
}

t_chunk	*split_chunk(t_stack **analyze, t_stack **split, int size, t_stack **a)
{
	t_chunk	*new;

	new = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new)
		return (NULL);
	new->divison = size;
	new->min_size = size / 3;
	if (size % 3 == 2)
	{
		new->mid_size = (size / 3) + 1;
		new->top_size = (size / 3) + 1;
	}
	else if (size % 3 == 1)
	{
		new->mid_size = size / 3;
		new->top_size = (size / 3) + 1;
	}
	else
	{
		new->mid_size = size / 3;
		new->top_size = size / 3;
	}
	return (new = spldeal(analyze, a, split, new), new);
}
