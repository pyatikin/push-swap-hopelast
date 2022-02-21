#include "push_swap.h"

void	sorting(t_stack *a, t_stack *b, int min_price)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	int		i;

	a_tmp = a->head;
	b_tmp = find_min_price(b, min_price);
	if (b_tmp->a_place > (a->size / 2) && b_tmp->b_place > (b->size / 2))
	{
		sorting_if_1(a, b, b_tmp, i);
		sorting_if_2(a, b, b_tmp, i);
	}
	else if (b_tmp->a_place <= (a->size / 2) && b_tmp->b_place <= (b->size / 2))
	{
		sorting_if_3(a, b, b_tmp, i);
		sorting_if_4(a, b, b_tmp, i);
	}
	sorting_if_5(a, b, b_tmp, i);
	sorting_if_6(a, b, b_tmp, i);
	ft_push(b, a, "pa\n");
	a->mas++;
}

int	evaluation(t_stack *a, t_stack *b)
{
	int		min_price;
	t_node	*tmp;

	tmp = b->head;
	min_price = MAX_INT;
	for_evaluation(a, b, tmp, &min_price);
	return (min_price);
}

void	triple_sort(t_stack *st)
{
	int	first;
	int	second;
	int	third;

	first = st->head->value;
	second = st->head->next->value;
	third = st->head->next->next->value;
	if (first < second && first < third && second > third)
		ft_swap(st, "sa\n");
	else if (first > second && first < third && second < third)
		ft_swap(st, "sa\n");
	else if (first > second && first > third && second > third)
		ft_swap(st, "sa\n");
}

void	parse_stack(t_stack *a, t_stack *b)
{
	t_numbers	nums;
	t_node		*tmp;

	tmp = a->head;
	nums.max = -2147483648;
	nums.min = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->value > nums.max)
			nums.max = tmp->value;
		if (tmp->value < nums.min)
			nums.min = tmp->value;
		tmp = tmp->next;
	}
	a->min = nums.min;
	tmp = a->tail;
	nums.mid = nums.max;
	get_mid(tmp, &nums);
	tmp = a->head;
	for_parse_stack(a, b, &tmp, nums);
}
