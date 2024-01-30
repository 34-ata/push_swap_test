/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:30:01 by faata             #+#    #+#             */
/*   Updated: 2024/01/30 13:13:34 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **av)
{
	t_stack	stack;
	int			size;
	int			i;

	i = -1;
	size = ft_ps_strlen(av, 0);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.sizea = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.sizeb = 0;
	while (++i < size)
		stack.a[i] = ft_atoips(av[i], stack.a, 0, 1);
	ft_checkdup(stack.a, size, 0, 1);
	printf("size = %d\n", size);
	ft_sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int argc, char **av)
{
	if (argc > 1)
	{
		av++;
		if (argc == 2)
			av = ft_split(*av, ' ');
		ft_push_swap(av);
		return (0);
	}
	return (0);
}
