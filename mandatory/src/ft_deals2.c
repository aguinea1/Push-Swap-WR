/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:49:41 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 21:05:00 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	ft_handle_min(t_stack **ana, t_stack **split, t_chunk *new, int *i)
{
	if ((*i + 1 < new->divison) && ana == new->stack
		&& (*ana)->next->order > (new->min_size + new->mid_size))
	{
		deal_rr_min(ana, split, &(new->top_count), new);
		(*i)++;
	}
	else
		deal_min(ana, split, new->stack, 0);
}

static void	ft_handle_mid(t_stack **ana, t_stack **split, t_chunk *new, int *i)
{
	if ((*i + 1 < new->divison) && ana != new->stack
		&& (*ana)->next->order <= new->min_size)
	{
		deal_rr_mid(ana, split, &(new->mid_count), new);
		(*i)++;
	}
	else
	{
		new->mid_count++;
		if (new->mid_count == 1)
			new->mid = *ana;
		deal_mid(ana, split, new->stack, 0);
	}
}

static void	ft_handle_max(t_stack **analyze, t_stack **split, t_chunk *new)
{
	new->top_count++;
	if (new->top_count == 1)
		new->top = *analyze;
	deal_max(analyze, split, new->stack, 0);
}

void	ft_deal(t_chunk *new, t_stack **analyze, t_stack **split, t_stack **a)
{
	int		i;

	i = 0;
	new->top_count = 0;
	new->mid_count = 0;
	new->stack = a;
	small_nbr(*analyze, new->divison);
	while (i++ < new->divison)
	{
		if (new->min_size >= (*analyze)->order)
			ft_handle_min(analyze, split, new, &i);
		else if ((new->min_size + new->mid_size) >= (*analyze)->order)
			ft_handle_mid(analyze, split, new, &i);
		else
			ft_handle_max(analyze, split, new);
	}
}
