#include "utils.h"

void	print_node(int value)
{
	ft_putnbr_fd(value, 1);
	ft_putchar_fd('\n', 1);
}

int	is_number(char *str)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if (sign == 1 && nb > 2147483647)
			return (0);
		if (sign == -1 && nb > 2147483648L)
			return (0);
		i++;
	}
	return (1);
}

int	is_sort(t_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;	
	}
	return (1);
}
