/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:27:45 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 13:36:21 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	ft_pushto(t_stack_node **stackfrom,t_stack_node **stackto)
{
    t_stack_node	*tmp;
	
	if (!*stackfrom)
	{
		ft_putstr_fd("KO\n",1);
		exit(1);
	}
    tmp = (*stackfrom);
    (*stackfrom)= (*stackfrom)->next;
    tmp->next = *stackto;
    *stackto = tmp;

}
void pa(t_stack_node **stackb,t_stack_node **stacka) 
{
    ft_pushto(stackb,stacka);
}
void pb(t_stack_node **stacka,t_stack_node **stackb)
{
    ft_pushto(stacka,stackb);
}