/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:47:44 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/20 13:01:25 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	sort_max(t_stack **a, t_stack **b, t_chunk *chunk)
{
	t_stack	*head;

	head = *a;
	if (check_max(*a, chunk->top))
	{
		small_nbr(*a, chunk->top_size);
		sort_max_top(a, b, chunk);
	}
	else
	{
		small_nbr_reverse(ft_lastnode(*a), chunk->top_size);
		sort_max_bot(a, b, chunk);
	}
}


int	check_max(t_stack *a, t_stack *last_max)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (a == last_max)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

int	lonely_max(t_stack **a, t_chunk *chunk)
{
	t_stack *head;
	int		i;

	i = 1;
	head = *a;
	while (i++ != chunk->top_size)
		head = head->next;
	if (head->next == NULL)
		return (1);
	return (0);
}
