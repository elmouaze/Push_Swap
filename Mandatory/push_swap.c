/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:47:41 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:48:28 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char *arg, t_stack_node *a, long num)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if ((arg[j] == '-' || arg[j] == '+' ) && j == 0)
			j++;
		if (arg[j] == '\0' || (arg[j] < 48 || arg[j] > 57))
			return (1);
		j++;
	}
	while (a != NULL)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_position(t_stack_node **stacka)
{
	t_stack_node	*current;
	t_stack_node	*temp;
	int				index;

	current = *stacka;
	while (current != NULL)
	{
		temp = *stacka;
		index = 0;
		while (temp != NULL)
		{
			if (temp->value < current->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_sort(t_stack_node *stacka, t_stack_node *stackb, int size)
{
	if (size > 5)
	{
		ft_position(&stacka);
		ft_quick_sort(&stacka, &stackb);
	}
	else if (size == 5 || size == 4)
		ft_sort5(&stacka, &stackb);
	else if (size == 3)
		ft_sort3(&stacka);
	else
		sa(&stacka);
}

void	fill_stack(char **av, t_stack_node **a)
{
	int		j;
	char	**x;
	long	num;
	int		i;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		x = ft_split(av[i], ' ');
		if (!(*x))
			ft_error(a, x);
		while (x[j])
		{
			num = ft_atol(x[j]);
			if ((num > INT_MAX || num < INT_MIN) || (ft_check(x[j], *a, num)))
				ft_error(a, x);
			ft_lstadd_back(a, ft_newnode(num));
			j++;
		}
		ft_free_splited(x);
		x = NULL;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	(1) && (a = NULL), (b = NULL);
	if (ac < 3 || (2 == ac && !av[1][0]))
		return (ft_putstr_fd("Error\n", 2), 1);
	fill_stack(av, &a);
	if (ft_checksort(a) == 0)
		return (1);
	ft_sort(a, b, ft_lstsize(a));
	ft_free_stack(&a);
}
