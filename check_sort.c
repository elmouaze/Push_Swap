/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:42:45 by ael-moua          #+#    #+#             */
/*   Updated: 2024/01/11 11:42:47 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_checksort(t_stack_node *stack)
{
    t_stack_node *tmp;
    
    while(stack)
    {
        tmp = stack->next;
        if (tmp == NULL)
            return 0;
        if ((stack->value) < (tmp->value))
            return 1;
        stack = stack->next;
    }
    return 0;
}
int ft_checksmallest(t_stack_node *stack, int cond)
{
    int min;
    int position;
    int i;

    (1) && (position = 0), (i = 0);
    if (stack)
        min = stack->value;    
    while(stack)
    {
        if (stack->value < min) 
        { 
            position = i;
            min = stack->value;
        }
        stack = stack->next;
        i++;
    }
    if (cond == 1)
        return (min);
    return position;
}
int ft_checkbiggest(t_stack_node *stack,int cond)
{
    int max;
    int position;
    int i;
    
    (1) && (position = 0), (i = 0);
    if (stack)
        max = stack->value;
    while(stack)
    {
       if(stack->value > max) 
       {
            position = i;
            max = stack->value;
       }
        stack = stack->next;
        i++;
    }
    if (cond == 1)
        return (max);
    return position;
}