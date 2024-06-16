/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:19:58 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 11:14:32 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./push_swap_bonus.h"

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
		if ((res > INT_MAX) && sign > 0)
			exit(1);
		str++;
	}
	return (res * sign);
}
