/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:40:28 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/20 16:37:17 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*tabint(char **av, t_stacks stacks)
{
	char	**spl_args;
	int		*tab;
	int		i;

	i = 0;
	spl_args = splitit(av);
	stacks.a->size = tablen(spl_args);
	tab = malloc(sizeof(int) * stacks.a->size);
	while (spl_args[i])
	{
		if (ft_atoi(spl_args[i]) < INT_MIN || ft_atoi(spl_args[i]) > INT_MAX)
			ft_error();
		tab[i] = ft_atoi(spl_args[i]);
		i++;
	}
	free_array(spl_args);
	return (tab);
}

void	check_rep(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->tab[i] == a->tab[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->tab[i] > a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_array(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
