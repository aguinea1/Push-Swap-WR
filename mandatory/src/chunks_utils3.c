/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:45:14 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/23 10:54:04 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	check_stack(t_stack **a, t_chunk *chunk)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (chunk->mid == head)
			return (1);
		head = head->next;
	}
	return (0);
}
/*
void	deal_bot(t_stack **split, t_stack **analyze, t_chunk *new, t_stack **a)
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
}*/
