/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:19:58 by ael-moua          #+#    #+#             */
/*   Updated: 2024/01/10 03:20:00 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
		if (*(str++) == '-')
			sign *= -1;
	while (*str == '0' && *str != '\0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		count++;
		res = (res * 10) + (*str - '0');
		if (res  > INT_MAX)
			return (res );
		str++;
	}
	return (res * sign);
}
