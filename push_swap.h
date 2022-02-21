#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct _t_node {
	int				price;
	int				value;
	int				a_place;
	int				b_place;
	struct _t_node	*next;
	struct _t_node	*prev;
}	t_node;

typedef struct stack {
	size_t	size;
	t_node	*head;
	t_node	*tail;
	int		mas;
}	t_stack;

int		ft_isdigit(int c);
t_stack	*createt_stack(void);
void	deletet_stack(t_stack **list);
void	push_front(t_stack *list, int data);
void	push_back(t_stack *list, int value);
int		ft_atoi(const char *s);
void	printt_stack(t_stack *list);
int		get_nvalue(t_stack *list, size_t index);
void	ft_swap(t_stack *st, char *s);
void	triple_sort(t_stack *st);
void	ft_rotate(t_stack *st, char *s);
void	ft_reverce_rotate(t_stack *st, char *s);
void	ft_push(t_stack *from, t_stack *to, char *s);
void	parse_stack(t_stack *a, t_stack *b);
size_t	ft_strlen(const char *s);
void	find_your_place(t_stack *a, t_stack *b);
int		evaluation(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	sorting(t_stack *a, t_stack *b, int min_price);
int		pop_front(t_stack *list);

#endif