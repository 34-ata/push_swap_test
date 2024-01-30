/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:50 by faata             #+#    #+#             */
/*   Updated: 2024/01/30 15:43:33 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_qs3(t_stack *stack, int len)
{
	if (len == 3 && stack->sizea == 3)
		ft_sort3(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			printf("fata %i - %i\n",len, stack->sizea);
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2] > stack->a[1])
				ft_sa(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 'b');
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (len++)
				ft_pa(stack);
		}
	}
}

int	ft_sortsb(t_stack *s, int len)
{
	if (len == 1)
		ft_pa(s);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s);
		while (len--)
			ft_pa(s);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				ft_sa(s);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 'a');
			else
				ft_sb(s);
		}
	}
	return (0);
}

int	ft_get_mid(int *midvalue, int *stack, int size)
{
	int		*tmps;
	int		i;

	tmps = (int *)malloc(size * sizeof(int));
	if (!tmps)
		return (0);
	i = 0;
	while (i < size)
	{
		tmps[i] = stack[i];
		i++;
	}
	ft_sort_tmp(tmps, size);
	*midvalue = tmps[size / 2];
	printf("Midvalue = %d\n", *midvalue);
	free(tmps);
	return (1);
}

int	ft_qsa(t_stack *stack, int len, int cs)
{
	int	midvalue;
	int	size;

	midvalue = 0;
	printf("A_len = %d\n", len);
	if (ft_checks(stack->a, len, 0) == 1)
		return (1);
	size = len;
	if (len <= 3)
	{
		ft_qs3(stack, len);
		printf("qs3\n");
		print_stack(stack, 'a');
		print_stack(stack, 'b');
		return (1);
	}
	if (!ft_get_mid(&midvalue, stack->a, len))
		return (0);
	while (len != size / 2 + size % 2)
	{
		if (stack->a[0] < midvalue && (len--))
			ft_pb(stack);
		else if (++cs)
			ft_ra(stack);
	}
	while (size / 2 + size % 2 != stack->sizea && cs--)
	{
		printf("deneme\n");
		ft_rra(stack);
	}
	printf("qsa\n");
	printf("size = %d\n", size);
	printf("size / 2 + size %% 2 = %d\n", size / 2 + size % 2);
	print_stack(stack, 'a');
	print_stack(stack, 'b');
	return (ft_qsa(stack, size / 2 + size % 2, 0)
		&& ft_qsb(stack, size / 2, 0));
}

int	ft_qsb(t_stack *stack, int len, int cs)
{
	int	midvalue;
	int	size;

	printf("blen = %d\n", len);
	if (ft_checks(stack->b, len, 1) == 1)
		while (len--)
			ft_pa(stack);
	if (len <= 3)
	{
		ft_sortsb(stack, len);
		printf("sortsb\n");
		printf("%d\n", len);
		print_stack(stack, 'a');
		print_stack(stack, 'b');
		return (1);
	}
	size = len;
	if (!ft_get_mid(&midvalue, stack->b, len))
		return (0);
	while (len != size / 2)
	{
		if (stack->b[0] >= midvalue && len--)
			ft_pa(stack);
		else if (++cs)
			ft_rb(stack);
	}
	while (size / 2 != stack->sizeb && cs--)
		ft_rrb(stack);
	printf("qsb\n");
	print_stack(stack, 'a');
	print_stack(stack, 'b');
	return (ft_qsa(stack, size / 2 + size % 2, 0)
		&& ft_qsb(stack, size / 2, 0));
}

void print_stack(t_stack *stack, char c)
{
	int i;

	i = 0;
	if (c == 'a')
	{
		printf("A = ");
		while (i < stack->sizea)
			printf("%d, ", stack->a[i++]);
		printf("\n");
	}
	else
	{
		printf("B = ");
		while (i < stack->sizeb)
			printf("%d, ", stack->b[i++]);
		printf("\n");
	}
}
