/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:42:14 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/19 02:25:00 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	ft_check_swap(t_stack **a, t_stack **b)
{ 
	if ((a && b && (*a)->next->order < (*a)->order) && 
		((*b)->next->order > (*b)->order))
		ss(a, b, 2);
	else if (a && (*a)->next->order < (*a)->order)
		sa(a, 2);
	else if (b && (*b)->next->order > (*b)->order)
		sb(b, 2);
}

void small_nbr(t_stack *a, int size)
{
    t_stack *head;
    t_stack *node;
    int current_order;
    int min_processed;
	int		i;

	i = 0;
    current_order = 1;
    min_processed = -2147483648;
    while (current_order <= size)
    {
		i = 0;
        head = a;
        node = NULL;
        while (head && i < size)
        {
            if ((head->nbr > min_processed) && (!node || head->nbr < node->nbr))
                node = head;
            head = head->next;
			i++;
        }
        if (node)
        {
            node->order = current_order;
            min_processed = node->nbr; 
            current_order++;
        }
    }
}

int	ft_is_bottom(t_stack *check, t_stack *list)
{
	if (ft_lastnode(list) == check)
		return (1);
	return (0);
}

int	ft_lonely(t_stack *check, int size, t_stack *list)
{
	int i;

	i = 0;
	while (i++ < size)
		list = list->next;
	if (check == list)
		return (1);
	return (0);
}
int	where_is_mid(t_stack *mid, t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp == mid)
			return (1);
		if (!(temp->next))
			break ;
		temp = temp->next;
	}
	return (0);
}
