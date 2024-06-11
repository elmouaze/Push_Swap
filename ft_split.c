/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:18:33 by ael-moua          #+#    #+#             */
/*   Updated: 2024/01/10 04:18:36 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

static int	ft_count_words(char const *s, char c)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			counter++;
		while (s[index] != c && s[index])
			index++;
	}
	return (counter);
}

static void	ft_free_memory(char **res, int max_index)
{
	while (max_index >= 0)
	{
		free(res[max_index]);
		res[max_index--] = NULL;
	}
	free(res);
	res = NULL;
}

static char	*ft_count_char(char const *s, char c)
{
	char		*str;
	int			counter;
	int			index;

	counter = 0;
	index = 0;
	while (s[counter] != c && s[counter])
		counter++;
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (!str)
		return (NULL);
	while (counter)
	{
		str[index] = s[index];
		index++;
		counter--;
	}
	str[index] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		count_w;

	if (!s)
		return (NULL);
	count_w = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count_w + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < count_w)
	{
		while (*s == c && c)
			s++;
		res[i] = ft_count_char(s, c);
		if (!res[i])
		{
			ft_free_memory(res, i);
			return (NULL);
		}
		s += ft_strlen(res[i]);
	}
	res[i] = NULL;
	return (res);
}

