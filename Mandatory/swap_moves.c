/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:01:01 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 04:45:55 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack_node **stack)
{
	ft_swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **stack)
{
	ft_swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **stacka, t_stack_node **stackb)
{
	ft_swap (stacka);
	ft_swap (stackb);
	ft_putstr_fd ("ss\n", 1);
}
