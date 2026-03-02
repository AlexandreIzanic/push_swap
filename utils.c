#include "utils.h"

void	print_node(int value)
{
	printf("%d\n", value);
}

int	is_number(char *str)
{
	int	i;
	
	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))	
			i++;
		if (str[i] < '0' || str[i] > '9')
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
	printf(GREEN "already sorted\n" RESET);
	return (1);
}
