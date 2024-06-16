
#include "./push_swap_bonus.h"

t_stack_moves *ft_newmove(char *content)
{
    t_stack_moves	*head;

	head = malloc(sizeof(t_stack_moves));
	if (!head)
		return (NULL);
	head->value = content;
	head->next = NULL;
	return (head);
}

t_stack_moves	*ft_lstlast_move(t_stack_moves *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_lstadd_move(t_stack_moves **lst, t_stack_moves *new)
{
	t_stack_moves	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast_move(*lst);
		tmp->next = new;
	}
}
t_stack_node *ft_newnode(int num)
{
    t_stack_node	*head;

	head = malloc(sizeof(t_stack_node));
	if (!head)
		return (NULL);
	head->value = num;
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
