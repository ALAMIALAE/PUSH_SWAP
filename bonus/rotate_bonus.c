/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:24:22 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/04 00:36:40 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*last;

	if (!lst || !(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	while (last->next)
		last = last->next;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}