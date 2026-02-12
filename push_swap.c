#include "utils.h"


int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = 0;
		while (args[i])
		{
			if (is_number(args[i]))
			{
				dlstadd_back(&stack_a, dlstnew(ft_atoi(args[i])));
				// test stack b
				dlstadd_back(&stack_b, dlstnew(4 + i));
			}
			i++;
		}
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (is_number(argv[i]))
				dlstadd_back(&stack_a, dlstnew(ft_atoi(argv[i])));
			i++;
		}
	}
	printf("stack a:\n");
	dlstiter(stack_a, print_node);
	is_sort(stack_a);
	printf("stack b:\n");
	dlstiter(stack_b, print_node);
	pb(&stack_a, &stack_b);
	printf("\n\n");
	dlstiter(stack_a, print_node);
	printf("\n\n");
	dlstiter(stack_b, print_node);

	dlstclear(&stack_a);
	dlstclear(&stack_b);
	return (0);
}
