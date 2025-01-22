/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_top_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:32:34 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 19:42:16 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	min_top_4(t_stack **a, t_stack **b)
{
	if ((*b)->order == 4 || (*b)->next->order == 4)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
	}
	else
		min_top_4_part2(a, b);
}

void	min_top_4_part2(t_stack **a, t_stack **b)
{
	pa(a, b, 2);
	rrb(b, 2);
	if ((*b)->order == 4)
		pa(a, b, 2);
	else
	{
		rrb(b, 2);
		pa(a, b, 2);
	}
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

void	min_is_top_else(t_stack **a, t_stack **b)
{
	if ((*b)->order == 4 || (*b)->next->order == 4)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
		ft_check_swap(a, b);
		pa(a, b, 2);
	}
	else
		min_top_4(a, b);
}
