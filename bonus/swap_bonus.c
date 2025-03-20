/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:25:41 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/04 00:36:26 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swaping(t_stack **l)
{
	t_stack	*first;
	t_stack	*second;

	if (!l || !*l || !(*l)->next)
		return ;
	first = *l;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*l = second;
}

void	ft_sa(t_stack **l)
{
	ft_swaping(l);
}

void	ft_sb(t_stack **l)
{
	ft_swaping(l);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swaping(a);
	ft_swaping(b);
}