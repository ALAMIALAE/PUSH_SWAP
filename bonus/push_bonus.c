/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:26:29 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/04 00:37:09 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pushing_a(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (!b || !*b)
		return ;
	top_b = *b;
	*b = top_b->next;
	top_b->next = *a;
	*a = top_b;
}

void	ft_pushing_b(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (!a || !*a)
		return ;
	top_a = *a;
	*a = top_a->next;
	top_a->next = *b;
	*b = top_a;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_pushing_a(a, b);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_pushing_b(a, b);
}