#include "push_swap.h"

void	printt_stack(t_stack *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	get_nvalue(t_stack *list, size_t index)
{
	t_node	*tmp;
	size_t	i;

	tmp = NULL;
	if (index < list->size / 2)
	{
		i = 0;
		tmp = list->head;
		while (tmp && i < index)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = list->size - 1;
		tmp = list->tail;
		while (tmp && i > index)
		{
			tmp = tmp->prev;
			i--;
		}
	}
	return (tmp->value);
}

void	ft_push(t_stack *from, t_stack *to, char *s)
{
	int	tmp;

	tmp = pop_front(from);
	push_front(to, tmp);
	write(1, s, ft_strlen(s));
}
