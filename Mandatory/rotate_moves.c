/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:01:57 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:04:54 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack_node **stack)
{
	ft_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **stack)
{
	ft_rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
	ft_putstr_fd("rr\n", 1);
}
