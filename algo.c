/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:01:20 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/23 01:22:41 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_values(int len, int *end)
{
	if (len > 5 && len <= 100)
		*end = len / 6;
	else
		*end = 35;
}

void	sorting_helper(t_stack **a, t_stack **b, int len, int *arr)
{
	int	start;
	int	end;

	start = 0;
	range_values(len, &end);
	while (*a)
	{
		if ((*a)->content >= arr[start] && (*a)->content <= arr[end])
		{
			ft_pb(a, b);
			range_algo(&start, &end, len);
		}
		else if ((*a)->content < arr[start])
		{
			ft_pb(a, b);
			ft_rb(b);
			range_algo(&start, &end, len);
		}
		else
			ft_ra(a);
	}
}

void	sort_end(t_stack **a, t_stack **b)
{
	int	max_value;
	int	half;
	int	max_index;

	while (*b)
	{
		max_value = getting_max(*b);
		half = list_len(*b) / 2;
		max_index = index_max(*b, max_value);
		rotating_stack(b, max_value, half, max_index);
		ft_pa(a, b);
	}
}

void	algo(t_stack **a, t_stack **b, int *arr, int len)
{
	sorting_helper(a, b, len, arr);
	sort_end(a, b);
}
