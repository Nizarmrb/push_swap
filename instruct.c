/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:46:16 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/15 15:45:27 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->tab[0];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
}


void	swap_stack(t_stack *stack)
{
	int tmp;

	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
}

void	reverse_rotate_stack(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->size - 1;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp;
}

void	push_from_stack_to_stack(t_stack *stack1, t_stack *stack2)
{
	int i;

	i = stack2->size;
	while (i > 0)
	{
		stack2->tab[i] = stack2->tab[i - 1];
		i--;
	}
	stack2->tab[0] = stack1->tab[0];
	i = 0;
	while (i < stack1->size - 1)
	{
		stack1->tab[i] = stack1->tab[i + 1];
		i++;
	}
	stack1->size--;
	stack2->size++;
}
// void swap_both(t_stack *a, t_stack *b)
// {
// 	swap_stack(a);
// 	swap_stack(b);
// }
// void	rotate_both(t_stack *a, t_stack *b)
// {
// 	rotate_stack(a);
// 	rotate_stack(b);
// }
// void	reverse_rotate_both(t_stack *a, t_stack *b)
// {
// 	reverse_rotate_stack(a);
// 	reverse_rotate_stack(b);
// }