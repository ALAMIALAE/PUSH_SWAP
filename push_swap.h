/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:02 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/21 16:14:03 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
int					is_digit(char *res);
void				free_s(char **res);
t_stack				*ft_lstnew(int content);
void				ft_sa(t_stack **l);
void				ft_sb(t_stack **l);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				sorting(t_stack **a, t_stack **b, int *arr, int len);
void				sort_5(t_stack **a, t_stack **b);
void				sort_4(t_stack **a, t_stack **b);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_end(t_stack **a, t_stack **b);
int					already_sorted(t_stack *a);
int					n_min(t_stack *a);
int					n_max(t_stack *a);
void				algo(t_stack **a, t_stack **b, int *arr, int len);
int					len_stack(t_stack *a);
int					*stacka_to_arr(t_stack *a, int len);
int					*array_sorting(int *arr, int len);
int					index_max(t_stack *b, int max_value);
int					getting_max(t_stack *b);
int					list_len(t_stack *a);
void				rotating_stack(t_stack **b, int max_value, int half,
						int max_index);
void				parse(int ac, char **av, t_stack **a);
void				range_algo(int *start, int *end, int size);
void				free_l(t_stack *a);
int					limit_int(char *str);
int					get_index(t_stack *a, int value);
void				stack_add(t_stack **a, t_stack *new);
int					ft_dup(t_stack *a, int o);
#endif