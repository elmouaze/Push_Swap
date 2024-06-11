/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:27:45 by ael-moua          #+#    #+#             */
/*   Updated: 2024/01/11 11:27:46 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	ft_pushto(t_stack_node **stackfrom,t_stack_node **stackto)
{
    t_stack_node	*tmp;

    tmp = (*stackfrom);
    (*stackfrom)= (*stackfrom)->next;
    tmp->next = *stackto;
    *stackto = tmp;

}
void pa(t_stack_node **stackb,t_stack_node **stacka) 
{
    ft_pushto(stackb,stacka);
    ft_putstr_fd("pa\n",1);
}
void pb(t_stack_node **stacka,t_stack_node **stackb)
{
    ft_pushto(stacka,stackb);
    ft_putstr_fd("pb\n",1);
}