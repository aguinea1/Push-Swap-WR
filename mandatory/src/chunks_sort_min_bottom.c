/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:29:21 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/21 13:08:02 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	min_on_top(t_stack **b, t_chunk *chunk)
{
	int	i;
	int	res;
	t_stack	*head;

	i = 0;
	res = 0;
	head = *b;
	while (chunk->min_size >= i)
	{
		if (chunk->min == head)
		{
			res = 1;
			break ;
		}
		i++;
		if (!(head->next))
			break;
		head = head->next;
	}
	return (res);
}
/*
static void	sort_four(t_stack **a)
{
	sa(a, 2);
	ra(a, 2);
	sa(a, 2);
	ra(a, 2);
	sa(a, 2);
	rra(a, 2);
	ft_check_swap(a, NULL);
	rra(a, 2);
	ft_check_swap(a, NULL);
	sort_three_top(a);
}*/
static void	sort_min_4(t_stack **b, t_stack **a)
{
	rrb(b, 2);
	rrb(b, 2);
	if ((*b)->order == 4 || (*b)->next->order == 4)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		rrb(b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
	{
		pa(a, b, 2);
		rrb(b, 2);
		if ((*b)->order == 4)
		{
			pa(a, b, 2);
			rrb(b, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
		}
		else
		{
			rrb(b, 2);
			pa(a, b, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
		}

	}
}

void	sort_min_2(t_stack **b, t_stack **a, t_chunk *chunk)
{
	if (min_on_top(b, chunk) == 0)
		rrb(b, 2);
	if ((*b)->order == 1)
	{
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		return ;
	}
	else
	{
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
	}
}
static void	sorted_min_two(t_stack **a, t_stack **b, int size)
{
	rrb(b, 2);
	pa(a, b, 2);
	if (size == 2)
	{
		rrb(b, 2);
		pa(a, b, 2);
	}
	else if (size == 3)
	{
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
	}
	else if(size == 4)
	{
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		pa(a, b, 2);
	}
}

static void	sorted_min_one(t_stack **a, t_stack **b, int size)
{
	rrb(b, 2);
	if (size == 2)
	{
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (size == 3)
	{
		rrb(b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if(size == 4)
	{
		rrb(b, 2);
		rrb(b, 2);
		rrb(b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
}

void	sort_min(t_stack **b, t_stack **a, t_chunk *chunk)
{
	if (min_on_top(b, chunk) == 1)
	{
		min_is_top(a, b, chunk);
		return ;
	}
	if (is_bot_sorted_rev(ft_lastnode(*b), chunk->min_size) == 1)
	{
		sorted_min_two(a, b, chunk->min_size);
		return;
	}
	if (is_bot_sorted(ft_lastnode(*b), chunk->min_size) == 1)
	{
		sorted_min_one(a, b, chunk->min_size);
		return;
	}

	if (chunk->min_size == 4)
	{
		sort_min_4(b, a);
		return ;
	}
	if (chunk->min_size == 3)
	{
		rrb(b, 2);
		if ((*b)->order == 3)
		{
			pa(a, b, 2);
			rrb(b, 2);
			pa(a, b, 2);
			rrb(b, 2);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			return ;
		}
		rrb(b, 2);
		if ((*b)->order == 3)
		{
			pa(a, b, 2);
			rrb(b, 2);
			ft_check_swap(NULL, b);
			pa(a, b, 2);
			pa(a, b, 2);
		}
		else if ((*b)->order != 3)
		{
			rrb(b, 2);
			pa(a, b, 2);
			ft_check_swap(NULL, b);
			pa(a, b, 2);
			pa(a, b, 2);
		}
	}
	else
		sort_min_2(b, a, chunk);
}

