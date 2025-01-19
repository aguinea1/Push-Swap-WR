/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_mid_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:25 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/15 10:23:54 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	sort_four(t_stack **a, t_stack **b, t_chunk *chunk)
{
	pa(a, b, 2);
	rb(b, 2);
	rb(b, 2);
	pa(a, b, 2);
	rrb(b, 2);
	rrb(b, 2);
	ft_check_swap(a, b);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
	if (chunk->divison == 1)
		return ;
}

void	sort_mid_two(t_stack **a, t_stack **b)
{
	pa(a, b, 2);
	pa(a, b, 2);
	ft_check_swap(a, NULL);
}

void	sort_mid_three(t_stack **a, t_stack **b)
{
	if ((*b)->order == 3 || ((*b)->next->order == 3))
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
		rb(b, 2);
		pa(a, b, 2);
		rrb(b, 2);
		ft_check_swap(a, NULL);
		pa(a, b, 2);
		ft_check_swap(a, NULL);
	}
}
void	sort_mid(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->mid_size == 4)
	{
		if ((*b)->order == 4 || (*b)->next->order == 4)
		{
			pa(a, b, 2);
			pa(a, b, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
		}
		else if ((*b)->next->next->order == 4)
		{
			pa(a, b, 2);
			rb(b, 2);
			pa(a, b, 2);
			rrb(b, 2);
			ft_check_swap(a, b);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
			pa(a, b, 2);
			ft_check_swap(a, NULL);
		}
		else
			sort_four(a, b, chunk);
	}
	else if (chunk->mid_size == 2)
		sort_mid_two(a, b);
	else
		sort_mid_three(a, b);
}



