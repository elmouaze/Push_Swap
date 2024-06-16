/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:01:01 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 13:37:11 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void ft_swap(t_stack_node **stack)
{
    t_stack_node *tmp;

    if (!*stack)
	{
		ft_putstr_fd("KO\n",1);
		exit(1);
	}
    tmp = *stack;
    *stack = tmp->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;

}
void sa(t_stack_node **stack)
{
    ft_swap(stack);
}
void sb(t_stack_node **stack)
{
    ft_swap(stack);
}
void ss(t_stack_node **stacka,t_stack_node **stackb)
{
    ft_swap(stacka);
    ft_swap(stackb);
}