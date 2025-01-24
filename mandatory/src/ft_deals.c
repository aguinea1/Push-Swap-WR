/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:48:59 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 22:53:18 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	deal_min(t_stack **analyze, t_stack **split, t_stack **a, int up)
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

void	deal_mid(t_stack **analyze, t_stack **split, t_stack **a, int up)
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

void	deal_max(t_stack **analyze, t_stack **split, t_stack **a, int up)
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

void	ft_rem_chunk(t_chunk **chunk)
{
	(*chunk)->min_size = 0;
	(*chunk)->top_size = 0;
	(*chunk)->mid_size = 0;
	(*chunk)->top = NULL;
	(*chunk)->mid = NULL;
	(*chunk)->min = NULL;
	free (*chunk);
}
