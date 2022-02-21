#include "push_swap.h"

int	parse_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || (argv[i][0] == '-'
				&& (ft_isdigit(argv[i][1]))) || argv[i][j] == ','))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*translate(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = createt_stack();
	while (i < argc)
	{
		if (argv[i][0] == '0' && argv[i][1] == '\0')
			push_back(a, 0);
		else if (ft_atoi(argv[i]) == 0)
		{
			write(1, "Wrong num\n", 10);
			exit(4);
		}
		else
			push_back(a, ft_atoi(argv[i]));
		i++;
	}
	return (a);
}

void	duplicates(t_stack *st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st->size - 1)
	{
		j = i + 1;
		while (j < st->size)
		{
			if (get_nvalue(st, i) == get_nvalue(st, j))
			{
				write (1, "Duplicates", 11);
				exit(2);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char**argv)
{
	t_stack	*st;
	t_stack	*b;
	int		min_price;

	if (argc <= 2)
		return (0);
	else
	{
		if (parse_argv(argc, argv))
		{
			write(1, "NOT NUM\n", 9);
			exit (1);
		}
		st = translate(argc, argv);
		duplicates(st);
		if (argc == 3)
		{
			if (st->head->value > st->tail->value)
				write(1, "sa\n", 3);
			return (0);
		}
		b = createt_stack();
		st->mas = 0;
		parse_stack(st, b);
		triple_sort(st);
		while (b->size > 0)
		{
			find_your_place(st, b);
			min_price = evaluation(st, b);
			sorting(st, b, min_price);
		}
		last_step(st);
		//printt_stack(st); printf("MOVING = %d\n", st->mas);
		deletet_stack(&st);
		deletet_stack(&b);
	}
}
