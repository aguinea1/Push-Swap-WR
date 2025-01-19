/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_min_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:28 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/17 18:43:38 by aguinea          ###   ########.fr       */
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
	{
		pa(a, b, 2);
		rrb(b, 2);
		if((*b)->order == 4)
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
}
static void	min_top_3(t_stack **a, t_stack **b)
{
	if ((*b)->order == 3)
	{
		pa(a, b, 2);
		pa(a, b, 2);
		pa(a, b, 2);
		ft_check_swap(a, NULL);;
	}
	else if  ((*b)->next->order == 3)
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

void	min_is_top(t_stack **a, t_stack **b, t_chunk *chunk)
{
	if (chunk->min_size == 2)
	{
		ft_check_swap(NULL, b);
		pa(a, b, 2);
		pa(a, b, 2);
	}
	else if(chunk->min_size == 3)
		min_top_3(a, b);
	else 
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
}



		
