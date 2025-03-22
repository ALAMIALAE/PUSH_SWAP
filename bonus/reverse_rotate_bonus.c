/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:27:20 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/20 23:38:00 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rev_rot(t_stack **lst)
{
	t_stack	*prev;
	t_stack	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	ft_rra(t_stack **a)
{
	ft_rev_rot(a);
}

void	ft_rrb(t_stack **b)
{
	ft_rev_rot(b);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rot(a);
	ft_rev_rot(b);
}
