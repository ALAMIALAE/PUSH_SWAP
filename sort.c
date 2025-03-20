/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:31:10 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 18:22:12 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_sa(a);
}

void	sort_3(t_stack **a)
{
	int	high;

	high = n_max(*a);
	if (high == (*a)->content)
		ft_ra(a);
	else if ((*a)->next->content == high)
		ft_rra(a);
	if ((*a)->content > (*a)->next->content)
		ft_sa(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	min;

	min = n_min(*a);
	while ((*a)->content != min)
	{
		if ((*a)->next->content == min)
			ft_sa(a);
		else
			ft_ra(a);
	}
	ft_pb(a, b);
	sort_3(a);
	ft_pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min;
	int	min_pos;

	min = n_min(*a);
	min_pos = get_index(*a, min);
	if (min_pos <= 2)
		while ((*a)->content != min)
			ft_ra(a);
	else
		while ((*a)->content != min)
			ft_rra(a);
	ft_pb(a, b);
	min = n_min(*a);
	min_pos = get_index(*a, min);
	if (min_pos <= 2)
		while ((*a)->content != min)
			ft_ra(a);
	else
		while ((*a)->content != min)
			ft_rra(a);
	ft_pb(a, b);
	sort_3(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
