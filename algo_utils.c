/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:08:36 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 14:48:23 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getting_max(t_stack *b)
{
	int		max_value;
	t_stack	*a;

	max_value = b->content;
	a = b;
	while (a)
	{
		if (a->content > max_value)
			max_value = a->content;
		a = a->next;
	}
	return (max_value);
}

int	index_max(t_stack *b, int max_value)
{
	int		index_max;
	t_stack	*a;

	index_max = 0;
	a = b;
	while (b)
	{
		if (a->content == max_value)
			break ;
		index_max++;
		a = a->next;
	}
	return (index_max);
}

int	list_len(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	rotating_stack(t_stack **b, int max_value, int half, int max_index)
{
	if (max_index <= half)
	{
		while ((*b)->content != max_value)
			ft_rb(b);
	}
	else
	{
		while ((*b)->content != max_value)
			ft_rrb(b);
	}
}
int	get_index(t_stack *a, int value)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a->content == value)
			return (index);
		index++;
		a = a->next;
	}
	return (-1);
}
