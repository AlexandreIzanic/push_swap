#include "utils.h"

// SWAP

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_node **head_a)
{
	swap(head_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **head_b)
{
	swap(head_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **head_a, t_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_putstr_fd("ss\n", 1);
}

// ROTATE
void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*head)->prev = NULL;
}

void	ra(t_node **head_a)
{
	printf("ra \n");
	rotate(head_a);
}

void	rb(t_node **head_b)
{
	printf("rb \n");
	rotate(head_b);
}

void	rr(t_node **head_a, t_node **head_b)
{
	printf("rr");
	rotate(head_a);
	rotate(head_b);
}
// REVERSE ROTATE
void	reverse_rotate(t_node	**head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	*head = last;
}

void	rra(t_node **head_a)
{
	printf("rra \n");
	reverse_rotate(head_a);
}

void	rrb(t_node **head_b)
{
	printf("rrb \n");
	reverse_rotate(head_b);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	printf("rrr \n");
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}


// PUSH

void	push(t_node **src, t_node **dst)
{
	t_node	*first;

	if (!src || !*src || !dst)
		return ;
	first = *src;
	*src = first->next;
	if (*src)
		(*src)->prev = NULL;
	first->next = *dst;
	if (*dst)
		(*dst)->prev = first;
	first->prev = NULL;
	*dst = first;
}

void	pa(t_node **head_a, t_node **head_b)
{
	printf("pa \n");
	push(head_b, head_a);
}

void	pb(t_node **head_a, t_node **head_b)
{
	printf("pb \n");
	push(head_a, head_b);
}


t_node	*dlstnew(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*dlstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	dlstadd_back(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = dlstlast(*lst);
	last->next = new_node;
	new_node->prev = last;
}

void	dlstadd_front(t_node **lst, t_node *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	if (*lst)
		(*lst)->prev = new_node;
	new_node->prev = NULL;
	*lst = new_node;
}

int	dlstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	dlstiter(t_node *lst, void (*f)(int))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}

void	dlstclear(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
