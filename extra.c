#include "push_swap.h"

int	get_place(t_stack *st, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = st->head;
	while (tmp->value != value)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	find_your_place(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*a2;
	int		i;
	int		j;

	i = 0;
	tmp = b->head;
	while (tmp != NULL)
	{
		tmp->b_place = i;
		a2 = a->head;
		j = 0;
		while (tmp && a2->next && !(((a2->value - tmp->value) < 0)
				&& ((a2->next->value - tmp->value) > 0)))
		{
			a2 = a2->next;
			j++;
		}
		if (a2->next == NULL)
			tmp->a_place = 0;
		else
			tmp->a_place = j + 1;
		i++;
		tmp = tmp->next;
	}
}

t_node	*find_min_price(t_stack *b, int min_price)
{
	t_node	*tmp;

	tmp = b->head;
	while (tmp->price != min_price)
		tmp = tmp->next;
	return (tmp);
}
