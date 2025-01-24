/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_min_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:36:20 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/23 15:05:42 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	lonely_min_four(t_stack **a, t_stack **b)
{
	if ((*b)->next->next->next->order == 4)
		rrb(b, 2);
	else if ((*b)->next->next->order == 4)
	{
		rrb(b, 2);
		rrb(b, 2);
	}
	pa(a, b, 2);
	pa(a, b, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

static void	lonely_min_three(t_stack **a, t_stack **b)
{
	if ((*b)->next->next->order == 3)
		rrb(b, 2);
	else if ((*b)->next->order == 3)
		rb(b, 2);
	pa(a, b, 2);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

void	min_lonely_sort(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->min_size == 4)
		lonely_min_four(a, b);
	else if (chunk->min_size == 3)
		lonely_min_three(a, b);
	else if (chunk->min_size == 2)
	{
		ft_check_swap(NULL, b);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else
		pa(a, b, 2);
}
