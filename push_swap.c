/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:14:10 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/21 22:26:59 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *a)
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

int	*stacka_to_arr(t_stack *a, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while ((a))
	{
		arr[i] = (a)->content;
		(a) = (a)->next;
		i++;
	}
	return (arr);
}

int	*array_sorting(int *arr, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	sorting(t_stack **a, t_stack **b, int *arr, int len)
{
	if (already_sorted(*a))
	{
		free(arr);
		free_l(*a);
		return ;
	}
	else if (len == 2)
		sort_2(a);
	else if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
	else
		algo(a, b, arr, len);
	free_l(*a);
	free(arr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		len;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	parse(ac, av, &a);
	len = len_stack(a);
	arr = stacka_to_arr(a, len);
	arr = array_sorting(arr, len);
	sorting(&a, &b, arr, len);
}
