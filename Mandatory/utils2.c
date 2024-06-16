/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:19:58 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 05:29:13 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

long	ft_atol(const char *str)
{
	int					sign;
	unsigned long long	res;
	int					count;

	res = 0;
	count = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0' && *str != '\0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		count++;
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_free_stack(t_stack_node **a)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	while (*a)
	{
		tmp = (*a);
		*a = (*a)->next;
		free (tmp);
		tmp = NULL;
	}
}

void	ft_free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free (splited[i]);
		i++;
	}
	free (splited);
}

void	ft_error(t_stack_node**a, char	**x)
{
	ft_putstr_fd ("Error\n", 2);
	if (*a)
		ft_free_stack(a);
	if (*x)
		ft_free_splited(x);
	exit (1);
}
