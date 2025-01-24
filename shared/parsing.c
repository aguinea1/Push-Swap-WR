/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:20:00 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 22:07:42 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/include/push_swap.h"
#include "../mandatory/libft/libft.h"

int	error_syntax(char **arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[i] != NULL)
	{
		if (arr[i][0] == '\0')
			return (0);
		if ((arr[i][j] == '-' ) || (arr[i][j] == '+'))
			j++;
		while (ft_isdigit(arr[i][j]))
			j++;
		if (arr[i][j] != '\0')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	error_dup(char **arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_int(char **arr)
{
	int		i;
	long	nbr;

	i = 1;
	while (arr[i])
	{
		nbr = ft_atol(arr[i]);
		if (nbr > 2147483647 || nbr < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	error_free(t_stack **a)
{
	t_stack	*first;
	t_stack	*temp;

	first = *a;
	temp = first;
	while (first && first->next != NULL)
	{
		temp = first->next;
		free(first);
		first = temp;
	}
	free(first);
	a = NULL;
}

//One utils function because i don't have enough space

t_stack	*find_first(t_stack *last)
{
	if (!last)
		return (last);
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}
