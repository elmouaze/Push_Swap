#include "push_swap.h"

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

void ft_sort2(t_stack_node **stack)
{
    if (ft_checksort(*stack))
        sa(stack);
}
void ft_sort3(t_stack_node **stack)
{
    int minp;
    int maxp;

    (1) && (minp = ft_checksmallest(*stack, 0)) , (maxp = ft_checkbiggest(*stack, 0));
    if (minp == 1 && maxp == 2)
        sa(stack);
    else if (minp == 2 && maxp == 0)
    {
        sa(stack);
        rra(stack);
    }
    else if (minp == 1 && maxp == 0)
        ra(stack);
    else if (minp == 0 && maxp == 1)
    {
        sa(stack);
        ra(stack);
    }
    else if (minp == 2 && maxp == 1)
        rra(stack);
}
void ft_sort5(t_stack_node **stacka, t_stack_node **stackb)
{
    int minp;

    while (ft_lstsize(*stacka) > 3)
    {
        minp = ft_checksmallest(*stacka, 0);
        while (minp != 0)
        {
            if (2 > minp)
                sa(stacka);
            else 
                rra(stacka);
            minp = ft_checksmallest(*stacka, 0);
        }
        pb(stacka,stackb);
    }
    ft_sort3(stacka);
    pa(stackb,stacka);
    pa(stackb,stacka);
}

int indexnextnum(t_stack_node **stack, int value)
{
    t_stack_node *curr;
    int i = 0;
    curr = *stack;
    while(curr && curr->index != value)
    {
        curr = curr->next;
        i++;
    }
    return i;
}
int	ft_isprime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int checknextpush(t_stack_node *stack, int p1)
{
 
    while (stack)
    {
        if(stack->index < p1)
            return 1;
        stack = stack->next;   
         }
    return (0);
}
void ft_sortstack(t_stack_node **stacka, t_stack_node **stackb)
{
    int lp1;
    int p1;
    int p2;


    (1) && (lp1 = -1),(p1 = ft_lstsize(*stacka) / 3),(p2 = ft_lstsize(*stacka) / 6);
    while (ft_lstsize(*stacka) > 3)
    {
        if ((*stacka)->index  < p1)
            pb(stacka,stackb);
         else
            ra(stacka);
      
        if ((ft_lstsize(*stackb) > 1) && ((*stackb)->index >= lp1 && p2 <= (*stackb)->index))
            rb(stackb);
        if ((ft_lstsize(*stackb) == p1))
            {
                lp1 = p1;
                p1 += (ft_lstsize(*stacka) / 3);
                p2 = (ft_lstsize(*stackb) / 6) + lp1;
            }
        }
        if (checknextpush(*stacka,p1) == 0 )
          return ;
        ft_sort3(stacka);
        ft_sortstack2(stacka, stackb);
}

void ft_sortstack2(t_stack_node **stacka, t_stack_node **stackb)
{
    int biggestnumbervalue;
    int bottomavalue ;

    biggestnumbervalue = ft_lstlast(*stacka)->index;
    bottomavalue = ft_lstlast(*stacka)->index;
    while(ft_lstsize(*stackb) > 0)
    {
        while ((*stackb) && (*stackb)->index + 1 != (*stacka)->index)
        {
            if((indexnextnum(stackb, (*stacka)->index - 1)) >= ft_lstsize(*stackb) / 2)
            {
                if ((bottomavalue < (*stackb)->index) || biggestnumbervalue == bottomavalue)
                {
                    pa(stackb, stacka);
                    ra(stacka);
                    bottomavalue = (ft_lstlast(*stacka))->index;
                }
                else
                    rrb(stackb);
            }
            else
            {
                if ((bottomavalue < (*stackb)->index) || biggestnumbervalue == bottomavalue)
                {
                    pa(stackb, stacka);
                    ra(stacka);
                    bottomavalue = (ft_lstlast(*stacka))->index;
                }
                else
                    rb(stackb);
            }
        }
        while(*stackb && ((*stacka)->index) - 1 == (*stackb)-> index)
            pa(stackb, stacka);
        if (ft_lstlast(*stacka)->index  == ((*stacka)->index) - 1 )
        {
            while(bottomavalue  == (((*stacka)->index) - 1 ))
            {
                rra(stacka);
                bottomavalue = (ft_lstlast(*stacka))->index;
            }
        }
        if (ft_checksort(*stacka) && *stackb == NULL)
            break;
    }
}