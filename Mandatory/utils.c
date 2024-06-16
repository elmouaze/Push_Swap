/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 04:34:45 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/16 04:35:41 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack_node	*ft_newnode(int content)
{
	t_stack_node	*head;

	head = malloc(sizeof(t_stack_node));
	if (!head)
		return (NULL);
	head->value = content;
	head->next = NULL;
	return (head);
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (fd < 0 || !s)
		return ;
	while (s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
}
