/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:02:13 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/28 12:03:46 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}				t_stack_node;	

long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void	ft_putstr_fd(char *s, int fd);
void ft_position(t_stack_node **a);
// swap
void	sa(t_stack_node **stack);
void sb(t_stack_node **stack);
void ss(t_stack_node **stacka,t_stack_node **stackb);
// rotate
void ra(t_stack_node **stack);
void rb(t_stack_node **stack);
void rr(t_stack_node **stacka,t_stack_node **stackb);
// reverse rotate
void rra(t_stack_node **stack);
void rrb(t_stack_node **stack);
void rrr(t_stack_node **stacka,t_stack_node **stackb);
//	push to stack
void pa(t_stack_node **stackb,t_stack_node **stacka);
void pb(t_stack_node **stacka,t_stack_node **stackb);
//	sort
int ft_checksort(t_stack_node *stack);
void ft_sort2(t_stack_node **stack);
int ft_checksmallest(t_stack_node *stack, int cond);
int ft_checkbiggest(t_stack_node *stack, int cond);
void ft_sort3(t_stack_node **stack);
void ft_sort5(t_stack_node **stacka, t_stack_node **stackb);
void ft_sortstack(t_stack_node **stacka, t_stack_node **stackb);
void ft_sortstack2(t_stack_node **stacka, t_stack_node **stackb);
int	ft_lstsize(t_stack_node *lst);
#endif