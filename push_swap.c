#include "utils.h"

void	print_bin(int nb)
{
	int	i;
	int	bit;

	i = 31;
	while (i >= 0)
	{
		bit = (nb >> i) & 1;
		printf("%b", bit);
		if (i % 8 == 0 && i != 0)
			printf(" ");
		i--;
	}
	printf("\n");
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	
	(void)stack_a;
	(void)stack_b;

}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

static int	find_min_pos(t_node *stack)
{
	int		min;
	int		pos;
	int		i;
	t_node	*current;

	min = stack->value;
	pos = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static void	push_min_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	pos;

	pos = find_min_pos(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b, int size)
{
	int	to_push;

	to_push = size - 3;
	while (to_push > 0)
	{
		push_min_to_b(stack_a, stack_b, size);
		size--;
		to_push--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_two(t_node **stack_a)
{
	t_node	*head;

	head = *stack_a;
	if (head->value > head->next->value)
		ra(stack_a);	
}

static void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	parse_args(t_node **stack_a, char *str)
{
	char	**args;
	int		i;
	int		count;

	args = ft_split(str, ' ');
	if (!args)
		return (0);
	i = 0;
	count = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
		{
			free_split(args);
			return (-1);
		}
		dlstadd_back(stack_a, dlstnew(ft_atoi(args[i])));
		count++;
		i++;
	}
	free_split(args);
	return (count);
}

static int	parse_argv(t_node **stack_a, int argc, char *argv[])
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (-1);
		dlstadd_back(stack_a, dlstnew(ft_atoi(argv[i])));
		count++;
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		size = parse_args(&stack_a, argv[1]);
	else
		size = parse_argv(&stack_a, argc, argv);
	if (size <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		dlstclear(&stack_a);
		return (1);
	}
	if (!is_sort(stack_a))
	{
		if (size == 2)
			sa(&stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size <= 5)
			sort_five(&stack_a, &stack_b, size);
		else
			radix_sort(&stack_a, &stack_b);
	}
	printf("final \n\n");
	dlstiter(stack_a, print_node);
	dlstiter(stack_a, print_bin);
	dlstclear(&stack_a);
	dlstclear(&stack_b);
	return (0);
}
