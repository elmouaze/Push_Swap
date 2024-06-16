/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:28:41 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 11:29:58 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int		index;
	char	*res;

	index = 0;
	if (!str)
		return (NULL);
	res = malloc (ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[index] != '\0')
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		size;
	int		index;

	index = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	res = (char *) malloc(size + 1);
	if (!res)
		return (NULL);
	while (*s1 != '\0' && index < size)
		res[index++] = *s1++;
	while (*s2 != '\0' && index < size)
		res[index++] = *s2++;
	res[index] = '\0';
	return (res);
}

int	ft_checknl(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (1);
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}
