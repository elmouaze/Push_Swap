/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:01:57 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 13:37:14 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"


static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!*stack)
	{
		ft_putstr_fd("KO\n",1);
		exit(1);
	}
    tmp = *stack;
    *stack = (*stack)->next;
    ft_lstlast(*stack)->next = tmp;
    tmp->next = NULL;

}

void ra(t_stack_node **stack)
{
    ft_rotate(stack);
}
void rb(t_stack_node **stack)
{
    ft_rotate(stack);
}
void rr(t_stack_node **stacka,t_stack_node **stackb)
{
    ft_rotate(stacka);
    ft_rotate(stackb);
}
