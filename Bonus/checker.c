/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:13:15 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 13:27:56 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

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
    while (a != NULL)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (tmp1[i] || tmp2[i])
	{
		if (tmp1[i] != tmp2[i])
			return (-1);
		i++;
	}
	return (1);
}

void ft_error(t_stack_node **a, char    **x)
{
    ft_putstr_fd("Error\n",2);
    if (*a)
        ft_free_stack(a);
    if (*x)
        ft_free_splited(x);
    exit (1);
}

void fill_stack(char **av,t_stack_node **a)
{
    int     j;
    char    **x;
    long    num;
    int     i;

    i = 1;
    while(av[i] != NULL)
    {
        j = 0;
        x = ft_split(av[i],' ');
        if (!(*x))
            ft_error(a, x);
        while (x[j])
        {
            num = ft_atol(x[j]);
            if ((num > INT_MAX || num < INT_MIN) || (ft_check(x[j], *a, num)) || !x[j])
                ft_error(a, x);
            ft_lstadd_back(a, ft_newnode(num));
            j++;
        }
        ft_free_splited(x);
        x = NULL;
        i++;
    }
}

int check_move(char *str)
{
	if (ft_strcmp(str, "sa\n") == 1 || ft_strcmp(str, "sb\n") == 1)
    	return (0);
    else if (ft_strcmp(str, "ss\n") == 1 || ft_strcmp(str, "pa\n") == 1)
        return (0);
    else if (ft_strcmp(str, "pb\n") == 1 || ft_strcmp(str, "ra\n") == 1)
        return (0);
    else if (ft_strcmp(str, "rb\n") == 1 || ft_strcmp(str, "rr\n") == 1)
        return (0);
    else if (ft_strcmp(str, "rra\n") == 1  || ft_strcmp(str, "rrb\n") == 1)
        return (0);
    else if (ft_strcmp(str, "rrr\n") == 1 )
        return (0);
    return (1);
}
int ft_checksort(t_stack_node *stack)
{
    t_stack_node *tmp;
    
    while(stack)
    {
        tmp = stack->next;
        if (tmp == NULL)
            return 0;
        if ((stack->value) > (tmp->value))
            return 1;
        stack = stack->next;
    }
    return 0;
}
int	ft_lstsize(t_stack_node *lst)
{
	int		count;
	t_stack_node	*p;

	p = lst;
	count = 0;
	while (p)
	{
		p = p -> next;
		count++;
	}
	return (count);
}
void ft_sort(t_stack_node **a, t_stack_node **b,char *move)
{
	if (ft_strcmp(move, "sa\n") == 1 )
		sa(a);
	else if (ft_strcmp(move, "sb\n") == 1)
		sb(b);
    else if (ft_strcmp(move, "ss\n") == 1)
		ss(a,b);
	else if(ft_strcmp(move, "pa\n") == 1)
		pa(b,a);
    else if (ft_strcmp(move, "pb\n") == 1 )
		pb(a,b);
	else if (ft_strcmp(move, "ra\n") == 1)
		ra(a);
    else if (ft_strcmp(move, "rb\n") == 1 )
		rb(b);
	else if (ft_strcmp(move, "rr\n") == 1)
		rr(a,b);
    else if (ft_strcmp(move, "rra\n") == 1)
		rra(a);
	else if (ft_strcmp(move, "rrb\n") == 1)
		rrb(b);
    else if (ft_strcmp(move, "rrr\n") == 1)
		rrr(a,b);
	
}
int main(int ac,char **av)
{
    t_stack_node	*a;
	t_stack_node	*b;
    t_stack_moves   *moves;
    char            *tmp;
	
    tmp = NULL;
    if (ac < 3 || (2 == ac && !av[1][0]))
        return(ft_putstr_fd("Error\n",2),1);
    fill_stack(av, &a);
    while (1)
    {
        tmp = get_next_line(0);
        if (!tmp)
            break;
        if (check_move(tmp) == 1)
            return(ft_putstr_fd("Error\n",2),1);
        ft_lstadd_move(&moves, ft_newmove(tmp));
    }
	while(moves)
	{
		ft_sort(&a,&b,moves->value);
		moves = moves->next;
	}
	if (ft_checksort(a) == 0)
		return(ft_putstr_fd("OK\n",1),1);
	else
		return(ft_putstr_fd("KO\n",1),1);
		
}