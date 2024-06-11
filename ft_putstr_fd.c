#include "push_swap.h"

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
