 /*  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:47:41 by ael-moua          #+#    #+#             */
/*   Updated: 2024/04/22 11:41:56 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack_node *ft_newnode(int content)
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
	while (lst->next)
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
int ft_check(char *arg, t_stack_node *a, long num)
{
    int j;

    j = 0;
    while (arg[j])
    {
        if ((arg[j] =='-' || arg[j] == '+' ) && j == 0)
                j++;
        if (arg[j] == '\0' || (arg[j] < 48 || arg[j] > 57))
            return (1);
        j++;
    }
    while (a)
    {
        if (a->value == num)
            return (1);
        a = a->next; 
    }
	return (0);
}

void ft_free_stack(t_stack_node **a)
{
    t_stack_node *tmp;
    int i;

    i = 0;
    while(*a)
    {
        tmp = (*a);
        *a = (*a)->next;
        free(tmp);
        tmp = NULL;
    }
}
void ft_free_splited(char **splited)
{
    int i;

    i = 0;
    while (splited[i])
    {
        free(splited[i]);
        i++;
    }
    free(splited);
}
void    ff(void)
{
    system("leaks a.out");
}
void	ft_position(t_stack_node **stacka)
{
	t_stack_node	*curr;
	t_stack_node	*tmp;

	curr = *stacka;
	while (curr)
	{
		tmp = *stacka;
		while (tmp)
		{
			if (curr->value > tmp->value)
				curr->index++;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}
int main(int ac, char **av)
{
    t_stack_node	*a;
	t_stack_node	*b;
    int             i;
    int j;
    char            **x;
    long            num;

    //atexit(ff);
	(1) && (a = NULL), (b = NULL), (j = 0), (i = 1);
    if (ac == 1 || (2 == ac && !av[1][0]))
        return(0);
    while(av[i] != NULL)
    {
        x = ft_split(av[i],' ');
        if (!(*x))
            return (printf("Error"),ft_free_stack(&a),
                        ft_free_splited(x),1);
        while (x[j])
        {
            num = ft_atol(x[j]);
            if ((num > INT_MAX || num < INT_MIN) || (ft_check(x[j], a, num))|| !x[j])
                return (printf("Error"),ft_free_stack(&a),
                        ft_free_splited(x),1);
            ft_lstadd_back(&a, ft_newnode(num));
            j++;
        }
        j = 0;
        ft_free_splited(x);
        x = NULL;
        i++;
    }
    if (ft_lstsize(a) == 5)
        ft_sort5(&a,&b);
    else 
    {
        ft_position(&a);
        ft_sortstack(&a, &b);
    }
    ft_free_stack(&a);
}

