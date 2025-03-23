/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:57:21 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/23 17:36:37 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add(t_stack **a, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	current = *a;
	while (current->next)
		current = current->next;
	current->next = new;
}

int	ft_dup(t_stack *a, int o)
{
	while (a)
	{
		if (a->content == o)
			return (0);
		else
			a = a->next;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (2147483648);
		i++;
	}
	return (result * sign);
}

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
