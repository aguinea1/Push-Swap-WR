/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:28 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 19:41:46 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	min_top_3(t_stack **a, t_stack **b)
{
	if ((*b)->order == 3)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else if ((*b)->next->order == 3)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
	else
	{
		pa(a, b, 2);
		ft_check_swap(NULL, b);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}

static int	is_min_lonely(t_stack **b, t_chunk *chunk)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = *b;
	while (i++ != chunk->min_size)
		head = head->next;
	if (!(head->next))
		return (1);
	return (0);
}

static void	min_push(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->min_size == 2)
	{
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (chunk->min_size == 3)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (chunk->min_size == 1)
		pa(a, b, 2);
	else if (chunk->min_size == 4)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
	}
}

void	min_is_top(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk_is_sorted_reverse(*b, chunk->min_size) == 1)
	{
		min_push(a, b, chunk);
		return ;
	}
	if (is_min_lonely(b, chunk) == 1)
	{
		min_lonely_sort(a, b, chunk);
		return ;
	}
	if (chunk->min_size == 2)
	{
		ft_check_swap(NULL, b);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if (chunk->min_size == 3)
		min_top_3(a, b);
	else
		min_is_top_else(a, b);
}
