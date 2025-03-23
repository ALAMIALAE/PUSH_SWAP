/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:45:28 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/22 16:55:07 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handling_errors(char **res, t_stack **a)
{
	if (res)
		free_s(res);
	if (a && *a)
		free_l(*a);
	write(2, "Error\n", 6);
	exit(1);
}

long	validating_converting(char *str, t_stack **a, char **res)
{
	long	num;

	if (!is_digit(str))
		handling_errors(res, a);
	num = ft_atoi(str);
	if (num == 2147483648)
		handling_errors(res, a);
	if (num > INT_MAX || num < INT_MIN)
		handling_errors(res, a);
	if (!ft_dup(*a, num))
		handling_errors(res, a);
	return (num);
}

void	process(char *element, t_stack **a, char **res)
{
	long	num;
	t_stack	*tmp;

	num = validating_converting(element, a, res);
	tmp = ft_lstnew((int)num);
	if (!tmp)
		handling_errors(res, a);
	stack_add(a, tmp);
}

void	parse(int ac, char **av, t_stack **a)
{
	char	**res;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		res = ft_split(av[i], ' ');
		if (!res || !*res)
		{
			if (res)
				free_s(res);
			handling_errors(NULL, a);
		}
		j = 0;
		while (res[j])
			process(res[j++], a, res);
		free_s(res);
		i++;
	}
}
