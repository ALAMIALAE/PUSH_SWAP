/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:42:26 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 18:22:32 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_min(t_stack *a)
{
	int	min;

	if (!a)
		return (0);
	min = INT_MAX;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int	n_max(t_stack *a)
{
	int	max;

	if (!a)
		return (0);
	max = INT_MIN;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
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

void	range_algo(int *start, int *end, int size)
{
	(*start)++;
	(*end)++;
	if (*end == size)
		*end = size - 1;
}
