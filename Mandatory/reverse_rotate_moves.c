/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:15:32 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:06:29 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*pos;

	pos = *stack;
	tmp = *stack;
	while (pos->next->next != NULL)
		pos = pos->next;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	pos->next = NULL;
}

void	rra(t_stack_node **stack)
{
	ft_reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **stack)
{
	ft_reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
	ft_putstr_fd("rrr\n", 1);
}
