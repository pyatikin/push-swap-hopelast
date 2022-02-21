#include "push_swap.h"

void	ft_swap(t_stack *st, char *s)
{
	t_node	*tmp;

	tmp = st->head->next;
	st->head->next = tmp->next;
	tmp->next->prev = st->head;
	tmp->next = st->head;
	st->head->prev = tmp;
	tmp->prev = NULL;
	st->head = tmp;
	write(1, s, ft_strlen(s));
	st->mas++;
}

void	ft_rotate(t_stack *st, char *s)
{
	t_node	*tmp;

	tmp = st->head;
	st->head->next->prev = NULL;
	st->head = st->head->next;
	tmp->next = NULL;
	tmp->prev = st->tail;
	st->tail->next = tmp;
	st->tail = tmp;
	write(1, s, ft_strlen(s));
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a, "");
	ft_rotate(b, "rr\n");
	a->mas++;
}

void	ft_reverce_rotate(t_stack *st, char *s)
{
	t_node	*tmp;

	tmp = st->tail;
	st->tail = st->tail->prev;
	st->tail->next = NULL;
	st->head->prev = tmp;
	tmp->prev = NULL;
	tmp->next = st->head;
	st->head = tmp;
	write(1, s, ft_strlen(s));
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverce_rotate(a, "");
	ft_reverce_rotate(b, "rrr\n");
	a->mas++;
}
