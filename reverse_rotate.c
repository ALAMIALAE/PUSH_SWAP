/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:53:57 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 18:23:02 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	ft_rev_rot(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rot(a);
	ft_rev_rot(b);
	write(1, "rrr\n", 4);
}
