/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:17:40 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/23 17:34:59 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	msg_error(char *err, t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free(err);
	free_l(a);
	free_l(b);
	get_next_line(-1);
	exit(1);
}

void	ft_checker(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(a, b);
	else
		msg_error(line, *a, *b);
}

int	already_sorted(t_stack *a)
{
	while (!a)
		return (0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	last_check(t_stack *a, t_stack *b)
{
	if (already_sorted(a) && b == NULL)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	free_l(a);
	free_l(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	parse(ac, av, &a);
	line = get_next_line(0);
	if (!line)
	{
		write(2, "Error\n", 6);
		return (free_l(a), free(b), 0);
	}
	while (line)
	{
		ft_checker(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	get_next_line(-1);
	last_check(a, b);
	return (0);
}
