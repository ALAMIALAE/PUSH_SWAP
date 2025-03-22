/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:15:31 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/21 21:42:33 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	limit_int(char *str)
{
	long	result;

	result = ft_atoi(str);
	if (result < INT_MIN || result > INT_MAX)
		return (1);
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-')))
		return (0);
	return (1);
}

void	free_s(char **res)
{
	int	i;

	if (!res)
		return;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}


void	free_l(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
