/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:18:10 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 12:17:21 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}				t_stack_node;	

typedef struct s_stack_moves
{
	char				*value;
	struct s_stack_moves	*next;
}				t_stack_moves;	

// get_next_line func
char	*get_next_line(int fd);
int		ft_checknl(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

t_stack_moves *ft_newmove(char *content);
t_stack_moves	*ft_lstlast_move(t_stack_moves *lst);
void	ft_lstadd_move(t_stack_moves **lst, t_stack_moves *new);
int ft_checksort(t_stack_node *stack);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node *ft_newnode(int num);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
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
#endif
