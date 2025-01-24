/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:57:01 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/24 23:04:07 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	check_output_2(t_stack **a, t_stack **b, char *mov)
{
	if (ft_strcmp("rrb\n", mov))
	{
		if (!(*b))
			return ;
		rrb(b, 1);
	}
	else if (ft_strcmp("sa\n", mov))
		sa(a, 1);
	else if (ft_strcmp("sb\n", mov))
	{
		if (!(*b))
			return ;
		sb(b, 1);
	}
	else
		error(b, a);
	return ;
}

static void	check_output_1(t_stack **a, t_stack **b, char *mov)
{
	if (ft_strcmp("rr\n", mov))
	{
		if (!(*b))
			ra(a, 1);
		else
			rr(a, b, 1);
	}
	else if (ft_strcmp("rrr\n", mov))
	{
		if (!(*b))
			rra(a, 1);
		else
			rrr(a, b, 1);
	}
	else if (ft_strcmp("rra\n", mov))
		rra(a, 1);
	else
		check_output_2(a, b, mov);
}

static void	check_output(t_stack **a, t_stack **b, char *mov)
{
	if (ft_strcmp("pb\n", mov))
	{
		pb(a, b, 1);
	}
	else if (ft_strcmp("pa\n", mov))
	{
		if (!(*b))
			return ;
		pa(a, b, 1);
	}
	else if (ft_strcmp("ra\n", mov))
		ra(a, 1);
	else if (ft_strcmp("rb\n", mov))
	{
		if (!(*b))
			return ;
		rb(b, 1);
	}
	else
		check_output_1(a, b, mov);
}

static void	b_leaks(t_stack *b)
{
	if (b)
		error_free(&b);
	ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	char	*mov;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac <= 2)
		return (1);
	if ((error_syntax(av) == 1) && (error_dup(av) == 1) && (error_int(av) == 1))
		new_node(&a, av);
	else
		return (ft_printf("Error\n"), 0);
	mov = get_next_line(STDIN_FILENO);
	while (mov)
	{
		check_output(&a, &b, mov);
		free (mov);
		mov = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		b_leaks(b);
	return (error_free(&a), 0);
}
