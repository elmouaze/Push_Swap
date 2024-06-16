/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:02:13 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:34:33 by ael-moua         ###   ########.fr       */
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

long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);
void			ft_putstr_fd(char *s, int fd);
void			ft_position(t_stack_node **a);
// swap
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stacka, t_stack_node **stackb);
// rotate
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stacka, t_stack_node **stackb);
// reverse rotate
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stacka, t_stack_node **stackb);
//	push to stack
void			pa(t_stack_node **stackb, t_stack_node **stacka);
void			pb(t_stack_node **stacka, t_stack_node **stackb);
//	sort
int				ft_checksort(t_stack_node *stack);
int				ft_checksmallest(t_stack_node *stack, int cond);
int				ft_checkbiggest(t_stack_node *stack, int cond);
void			ft_sort3(t_stack_node **stack);
void			ft_sort5(t_stack_node **stacka, t_stack_node **stackb);
void			ft_sortstack(t_stack_node **stacka, t_stack_node **stackb);
void			ft_sortstack2(t_stack_node **stacka, t_stack_node **stackb);
int				ft_lstsize(t_stack_node *lst);
void			ft_quick_sort(t_stack_node **sa, t_stack_node **sb);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
void			ft_sort_part2(t_stack_node **sa, t_stack_node **sb);
void			printstack(t_stack_node *sa);
//	sort
t_stack_node	*ft_newnode(int content);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_free_stack(t_stack_node **a);
void			ft_free_splited(char **splited);
void			ft_error(t_stack_node**a, char	**x);

#endif