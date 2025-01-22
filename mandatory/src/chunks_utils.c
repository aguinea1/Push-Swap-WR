/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:45:46 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/22 20:46:53 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static int	check_stack_reply(t_stack **a, t_chunk *chunk)
{
	t_stack	*head;

	head = ft_lastnode(*a);
	while (head)
	{
		if (chunk->mid == head)
			return (1);
		head = head->prev;
	}
	return (0);
}

void	small_sort(t_stack **a, t_stack **b, t_chunk *new, int flag)
{
	if (check_stack_reply(a, new) == 0)
	{
		if (flag == 3)
			sort_max(a, b, new);
		else if (flag == 2)
		{
			small_nbr(*b, new->mid_size);
			sort_mid(a, b, new);
		}
		else
			sort_min(b, a, new);
	}
	else
	{
		if (flag == 3)
			sort_max(a, b, new);
		else if (flag == 2)
		{
			small_nbr_reverse(new->mid, new->mid_size);
			sort_mid_bot(a, b, new);
		}
		else
			sort_min(b, a, new);
	}
}

static t_stack	*small_nbr_rev_node(t_stack *node, int *current_order, int *min)
{
	node->order = *current_order;
	*min = node->nbr;
	return (node);
}

void	small_nbr_reverse(t_stack *a, int size)
{
	t_stack	*head;
	t_stack	*node;
	int		current_order;
	int		min_processed;
	int		i;

	current_order = 1;
	min_processed = -2147483648;
	while (current_order <= size)
	{
		i = 0;
		head = a;
		node = NULL;
		while (head && i++ < size)
		{
			if ((head->nbr > min_processed) && (!node || head->nbr < node->nbr))
				node = head;
			head = head->prev;
		}
		if (node)
		{
			node = small_nbr_rev_node(node, &current_order, &min_processed);
			current_order++;
		}
	}
}

t_stack	*find_mid(t_stack *c_analyze, t_chunk *new)
{
	while (c_analyze && c_analyze->next)
	{
		if (((new->min_size + new->mid_size) >= c_analyze->order)
			&& (new->min_size <= c_analyze->order))
			break ;
		c_analyze = c_analyze->next;
	}
	return (c_analyze->prev);
}
