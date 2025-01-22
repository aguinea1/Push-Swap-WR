/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_bottom_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:15:03 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 19:20:32 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	min_on_top(t_stack **b, t_chunk *chunk)
{
	int		i;
	int		res;
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
			break ;
		head = head->next;
	}
	return (res);
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

static void	sort_min_three_two(t_stack **a, t_stack **b)
{
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

void	sort_min_three_bot(t_stack **a, t_stack **b)
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
	sort_min_three_two(a, b);
}
