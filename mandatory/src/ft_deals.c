/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:48:59 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 21:09:24 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	deal_min(t_stack **analyze, t_stack **split, t_stack **a, int up)
{
	if (*analyze == *a)
	{
		if (up == 0)
		{
			pb(analyze, split, 2);
			rb(split, 2);
		}
		else
		{
			rra(analyze, 2);
			pb(analyze, split, 2);
			rb(split, 2);
		}
	}
	else
	{
		if (up == 0)
			rb(analyze, 2);
		else
			rrb(analyze, 2);
	}
}

static void	deal_mid(t_stack **analyze, t_stack **split, t_stack **a, int up)
{
	if (*analyze == *a)
	{
		if (up == 0)
			pb(analyze, split, 2);
		else
		{
			rra(analyze, 2);
			pb(analyze, split, 2);
		}
	}
	else
	{
		if (up == 0)
		{
			pa(split, analyze, 2);
			ra(split, 2);
		}
		else
		{
			rrb(analyze, 2);
			pa(split, analyze, 2);
			ra(split, 2);
		}
	}
}

static void	deal_max(t_stack **analyze, t_stack **split, t_stack **a, int up)
{
	if (*analyze == *a)
	{
		if (up == 0)
			ra(analyze, 2);
		else
			rra(analyze, 2);
	}
	else
	{
		if (up == 0)
			pa(split, analyze, 2);
		else
		{
			rrb(analyze, 2);
			pa(split, analyze, 2);
		}
	}
}

void	ft_deal(t_chunk *new, t_stack **analyze, t_stack **split, t_stack **a)
{
	int		i;
	int		max;
	int		mid;

	i = 0;
	max = 0;
	mid = 0;
	small_nbr(*analyze, new->divison);
	while (i++ < new->divison)
	{
		if (new->min_size >= (*analyze)->order)
		{
			if ((i + 1 < new->divison ) && analyze == a
				&& (*analyze)->next->order > (new->min_size + new->mid_size))
			{
				deal_rr_min(analyze, split, max, new);
				max++;
				i++;
			}
			else
				deal_min(analyze, split, a, 0);
		}
		else if ((new->min_size + new->mid_size) >= (*analyze)->order)
		{
			if ((i + 1 < new->divison) && analyze != a
				&& (*analyze)->next->order <= new->min_size)
			{
				deal_rr_mid(analyze, split, mid, new);
				mid++;
				i++;
			}
			else
			{
				mid++;
				if (mid == 1)
					new->mid = *analyze;
				deal_mid(analyze, split, a, 0);
			}
		}
		else
		{
			max++;
			if (max == 1)
				new->top = *analyze;
			deal_max(analyze, split, a, 0);
		}
	}
}

void deal_bot(t_stack **split, t_stack **analyze, t_chunk *new, t_stack **a)
{
	int		i;
	int		top;
	int		mid;
	int		min;
	t_stack	*tail;

	i = 0;
	top = 0;
	mid = 0;
	min = 0;
	small_nbr_reverse(ft_lastnode(*analyze), new->divison);
	while (i < new->divison)
	{
		tail = ft_lastnode(*analyze);
		if (new->min_size >= (tail)->order)
		{
			min++;
			if (min == 1)
				new->min = tail;
			deal_min(analyze, split, a, 1);
		}
		else if ((new->min_size + new->mid_size) >= (tail)->order)
		{
			mid++;
			if (mid == 1)
				new->mid = tail;
			deal_mid(analyze, split, a, 1);
		}
		else
		{
			top++;
			if (top == 1)
				new->top = tail;
			deal_max(analyze, split, a, 1);
		}
		i++;
	}
	if (analyze == a)
			new->min = ft_lastnode(*split);
}




