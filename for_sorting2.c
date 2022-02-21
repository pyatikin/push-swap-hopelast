#include "push_swap.h"

void	sorting_if_6(t_stack *a, t_stack *b, t_node *b_tmp, int i)
{
	if (b_tmp->a_place <= (a->size / 2) && b_tmp->b_place > (b->size / 2))
	{
		i = 0;
		while (i < b->size - b_tmp->b_place)
		{
			ft_reverce_rotate(b, "rrb\n");
			a->mas++;
			i++;
		}
		i = 0;
		while (i < b_tmp->a_place)
		{
			ft_rotate(a, "ra\n");
			a->mas++;
			i++;
		}
	}
}

void	for_evaluation(t_stack *a, t_stack *b, t_node *tmp, int *min_price)
{
	while (tmp != NULL)
	{
		if (tmp->a_place > (a->size / 2) && tmp->b_place > (b->size / 2))
		{
			if (a->size - tmp->a_place > b->size - tmp->b_place)
				tmp->price = a->size - tmp->a_place;
			else
				tmp->price = b->size - tmp->b_place;
		}
		else if (tmp->a_place <= (a->size / 2) && tmp->b_place <= (b->size / 2))
		{
			if (tmp->a_place > tmp->b_place)
				tmp->price = tmp->a_place;
			else
				tmp->price = tmp->b_place;
		}
		else if (tmp->a_place > (a->size / 2) && tmp->b_place <= (b->size / 2))
			tmp->price = tmp->b_place + a->size - tmp->a_place;
		else if (tmp->a_place <= (a->size / 2) && tmp->b_place > (b->size / 2))
			tmp->price = tmp->a_place + b->size - tmp->b_place;
		if (tmp->price < *min_price)
			*min_price = tmp->price;
		tmp = tmp->next;
	}
}

void	for_parse_stack(t_stack *a, t_stack *b, t_node **tmp, t_numbers nums)
{
	while (*tmp != NULL)
	{
		if (a->size == 3)
			break ;
		if ((*tmp)->value == nums.max || (*tmp)->value == nums.min
			|| (*tmp)->value == nums.mid)
		{
			*tmp = (*tmp)->next;
			ft_rotate(a, "ra\n");
			a->mas++;
		}
		else
		{
			*tmp = (*tmp)->next;
			ft_push(a, b, "pb\n");
			a->mas++;
		}
	}
}

void	get_mid(t_node *tmp, t_numbers *nums)
{
	while (nums->mid == nums->max)
	{
		if (tmp->value != nums->max && tmp->value != nums->min)
		{
			nums->mid = tmp->value;
			break ;
		}
		tmp = tmp->prev;
	}
}

void	last_step(t_stack *a)
{
	//printf("11111111111111111111111111111111111111111\n");
	if(get_place(a, a->min) > a->size/2)
	{
		//printf("PLACE = %d", get_place(a, a->min));
		while(a->head->value > a->min)
		{
			ft_reverce_rotate(a, "rra\n");
			a->mas++;
		}
	}
	else{
		//printf("PLACE = %d", get_place(a, a->min));
		while(a->head->value > a->min)
		{
			ft_rotate(a, "rra\n");
			a->mas++;
		}
	}
}