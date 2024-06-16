/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:50:17 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 04:59:48 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_stack_node **sa, t_stack_node **sb)
{
	int	lastp1;
	int	p1;
	int	p2;

	(1) && (lastp1 = -1), (p1 = ft_lstsize(*sa) / 3);
	p2 = ft_lstsize(*sa) / 6;
	while (ft_lstsize(*sa) > 3)
	{
		if ((*sa)->index < p1)
			pb (sa, sb);
		else
			ra (sa);
		if (ft_lstsize(*sb) > 1)
			if (((*sb)->index >= lastp1 && (*sb)->index <= p2))
				rb (sb);
		if (ft_lstsize (*sb) == p1)
		{
			lastp1 = p1;
			p1 += ft_lstsize(*sa) / 3;
			p2 = (ft_lstsize(*sa) / 6) + lastp1;
		}
	}
	ft_sort3(sa);
	ft_sort_part2(sa, sb);
}

int	indexnextnum(t_stack_node **stack, int value)
{
	t_stack_node	*curr;
	int				i;

	i = 0;
	curr = *stack;
	while (curr && curr->index != value)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	parrb(t_stack_node **sa, t_stack_node **sb, int Lindex, int index2)
{
	int	cond;

	cond = 0;
	Lindex = (ft_lstlast(*sa))->index;
	if (indexnextnum(sb, (*sa)->index - 1) >= ft_lstsize(*sb) / 2)
		cond = 0;
	else
		cond = 1;
	if ((Lindex < (*sb)->index || Lindex == index2) && *sb)
	{
		pa(sb, sa);
		ra(sa);
		Lindex = (ft_lstlast(*sa))->index;
	}
	else if (ft_lstsize(*sb) > 1 && cond == 0)
		rrb(sb);
	else if (ft_lstsize(*sb) > 1 && cond == 1)
		rb(sb);
}

void	ft_sort_part2(t_stack_node **sa, t_stack_node **sb)
{
	int	bottomtindex;
	int	bottom_node;

	bottom_node = ft_lstlast(*sa)->index;
	bottomtindex = ft_lstlast(*sa)->index;
	while (ft_lstsize(*sb) > 0)
	{
		while ((*sb) && (*sb)->index + 1 != (*sa)->index)
			parrb(sa, sb, bottom_node, bottomtindex);
		bottom_node = (ft_lstlast(*sa))->index;
		while ((*sb) && (*sa)->index - 1 == (*sb)->index)
			pa(sb, sa);
		while (((*sa)->index) - 1 == bottom_node)
		{
			rra(sa);
			bottom_node = ft_lstlast(*sa)->index;
		}
		if (ft_checksort(*sa) == 0 && ft_lstsize(*sb) == 0)
			break ;
	}
}
