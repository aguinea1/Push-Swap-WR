/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:09:32 by aguinea           #+#    #+#             */
/*   Updated: 2024/12/07 13:10:01 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	error(t_stack **b, t_stack **a)
{
	error_free(b);
	error_free(a);
	ft_printf("Error\n");
	exit (1);
}

bool	ft_strcmp(char	*s1, char *output)
{
	int	i;

	i = -1;
	while (s1[++i] != '\0' && output[i] != '\0')
	{
		if (s1[i] - output[i] != 0)
			return (false);
	}
	return (true);
}
