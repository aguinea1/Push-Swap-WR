/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_max_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:50:15 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 13:44:23 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	lonely_max_sort_four_part2(t_stack **a, t_stack **b)
{
	if ((*a)->order == 4 || (*a)->next->order == 4)
	{
		if ((*a)->next->order == 4)
			sa(a, 2);
		ra(a, 2);
		sort_three_top(a);
	}
	else
	{
		pb(a, b, 2);
		pb(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}

static void	lonely_sort_max_four(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next->order == 4)
		sort_three_top(a);
	else if (((*a)->order == 1 && (*a)->next->order == 2)
		|| ((*a)->order == 2 && (*a)->next->order == 1))
	{
		if ((*a)->next->next->order == 3)
			ft_check_swap(a, NULL);
		else
		{
			pb(a, b, 2);
			pb(a, b, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			pa(a, b, 2);
		}
		return ;
	}
	else if (((*a)->order == 3 && (*a)->next->order == 4)
		|| ((*a)->order == 4 && (*a)->next->order == 3))
	{
		if ((*a)->order == 4)
			sa(a, 2);
		ra(a, 2);
		ra(a, 2);
		ft_check_swap(a, b);
	}
	else
		lonely_max_sort_four_part2(a, b);
}

static void	lonely_max_sort(t_stack **a, t_stack **b, t_chunk *chunk)
{
	t_stack	*biggest;
	t_stack	*last;
	t_stack	*temp;

	temp = *a;
	biggest = biggest_node(a);
	last = ft_lastnode(*a);
	if (chunk->top_size == 3)
	{
		if (is_sorted(*a))
			return ;
		if (temp->nbr == biggest->nbr)
			ra(a, 2);
		else if ((*a)->next->nbr == biggest->nbr)
			rra(a, 2);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, 2);
		return ;
	}
	else
		lonely_sort_max_four(a, b);
}

void	sort_three_top(t_stack **a)
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

static void	sort_four(t_stack **a, t_stack **b)
{
	if ((*a)->next->order == 4)
	{
		pb(a, b, 2);
		sa(a, 2);
		pb(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
	{
		sa(a, 2);
		pb(a, b, 2);
		sa(a, 2);
		pb(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}

void	sort_max_top(t_stack **a, t_stack **b, t_chunk *chunk)
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
	{
		if (((*a)->next->next->next->order == 4) || (chunk->top_size == 3))
			sort_three_top(a);
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
			sort_four(a, b);
	}
}
