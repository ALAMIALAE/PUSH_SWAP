/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:17:40 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/20 23:38:56 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	msg_error(char *err, t_stack **a, t_stack **b)
{
	write(1, "error\n", 6);
	if (err)
	{
		free(err);
		err = NULL;
	}
	free_l(*a);
	free_l(*b);
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
	{
		free(line);
		msg_error(line, a, b);
	}
}

int	already_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
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
	while (line)
	{
		ft_checker(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (already_sorted(a) && b == NULL)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	free_l(a);
	free_l(b);
}
