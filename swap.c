/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:01:29 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 18:21:37 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **l)
{
	ft_swaping(l);
	write(1, "sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swaping(a);
	ft_swaping(b);
	write(1, "ss\n", 3);
}
