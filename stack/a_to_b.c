/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:11:30 by mnaumann          #+#    #+#             */
/*   Updated: 2024/06/21 17:11:30 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack || stack_size(stack) == 0)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp_b;
	t_stack_node	*target_b;
	long			match_index;

	while (a)
	{
		tmp_b = b;
		match_index = LONG_MIN;
		while (tmp_b)
		{
			if (tmp_b->data < a->data && tmp_b->index > a->index)
			{
				match_index = tmp_b->data;
				target_b = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_b;
		a = a->next;
	}
}

static void	get_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest_tmp;
	long			cheapest_cost;

	cheapest_cost = LONG_MAX;
	while (a)
	{
		if (a->cost < cheapest_cost)
		{
			cheapest_cost = a->cost;
			cheapest_tmp = a;
		}
		a = a->next;
	}
	cheapest_tmp->cheapest = true;
}

void	prep_cheapest(t_stack_node *a, t_stack_node *b)
{
	indexing(a);
	indexing(b);
	set_target_a(a, b);
	get_cost(a, b);
	set_cheapest(a);
}
