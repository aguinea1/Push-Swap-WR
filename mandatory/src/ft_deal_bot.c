/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:39:24 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 20:57:49 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	ft_handle_bot_min(t_stack **analyze, t_stack **split, t_chunk *new)
{
	t_stack	*tail;

	new->min_count++;
	tail = ft_lastnode(*analyze);
	if (new->min_count == 1)
		new->min = tail;
	deal_min(analyze, split, new->stack, 1);
}

static void	ft_handle_bot_mid(t_stack **analyze, t_stack **split, t_chunk *new)
{
	t_stack	*tail;

	new->mid_count++;
	tail = ft_lastnode(*analyze);
	if (new->mid_count == 1)
		new->mid = tail;
	deal_mid(analyze, split, new->stack, 1);
}

static void	ft_handle_bot_max(t_stack **analyze, t_stack **split, t_chunk *new)
{
	t_stack	*tail;

	new->top_count++;
	tail = ft_lastnode(*analyze);
	if (new->top_count == 1)
		new->top = tail;
	deal_max(analyze, split, new->stack, 1);
}

void	deal_bot(t_stack **split, t_stack **analyze, t_chunk *new, t_stack **a)
{
	int		i;
	t_stack	*tail;

	i = 0;
	new->top_count = 0;
	new->mid_count = 0;
	new->min_count = 0;
	new->stack = a;
	small_nbr_reverse(ft_lastnode(*analyze), new->divison);
	while (i++ < new->divison)
	{
		tail = ft_lastnode(*analyze);
		if (new->min_size >= tail->order)
			ft_handle_bot_min(analyze, split, new);
		else if ((new->min_size + new->mid_size) >= tail->order)
			ft_handle_bot_mid(analyze, split, new);
		else
			ft_handle_bot_max(analyze, split, new);
	}
	if (analyze == a)
		new->min = ft_lastnode(*split);
}
