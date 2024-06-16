/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:36:16 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:03:09 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_node *lst)
{
	int				count;
	t_stack_node	*p;

	p = lst;
	count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return (count);
}

void	ft_sort3(t_stack_node **stack)
{
	int	minp;
	int	maxp;

	minp = ft_checksmallest(*stack, 0);
	maxp = ft_checkbiggest(*stack, 0);
	if (minp == 1 && maxp == 2)
		sa(stack);
	else if (minp == 2 && maxp == 0)
	{
		sa(stack);
		rra(stack);
	}
	else if (minp == 1 && maxp == 0)
		ra(stack);
	else if (minp == 0 && maxp == 1)
	{
		sa(stack);
		ra(stack);
	}
	else if (minp == 2 && maxp == 1)
		rra(stack);
}

void	ft_sort5(t_stack_node **stacka, t_stack_node **stackb)
{
	int	minp;

	while (ft_lstsize(*stacka) > 3)
	{
		minp = ft_checksmallest(*stacka, 0);
		while (minp != 0)
		{
			if (2 > minp)
				sa(stacka);
			else
				rra(stacka);
			minp = ft_checksmallest(*stacka, 0);
		}
		pb(stacka, stackb);
	}
	ft_sort3(stacka);
	while (*stackb)
		pa(stackb, stacka);
}
