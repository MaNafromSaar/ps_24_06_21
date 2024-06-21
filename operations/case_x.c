/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:00:35 by mnaumann          #+#    #+#             */
/*   Updated: 2024/06/20 21:00:35 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_stacks(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b != cheapest->target && *a != cheapest) && (cheapest->above_median
		&& cheapest->target->above_median))
		rr(a, b);
	while ((*b != cheapest->target && *a != cheapest) && (!(cheapest->above_median)
		&& !(cheapest->target->above_median)))
		rrr(a, b);
	indexing(*a);
	indexing(*b);
}

static void	move_a_to_b(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*cheapest;

	if (stack_size(*b) == 0)
		pb(a, b);
	cheapest = get_cheapest(*a);
	if (cheapest == NULL)
		return ;
	if (cheapest->target == NULL)
		return ;
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_stacks(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rotate_stacks(a, b, cheapest);
	else if (cheapest->above_median && !cheapest->target->above_median)
		rb(a);
	else if (!cheapest->above_median && cheapest->target->above_median)
		rrb(a);
	prep_push(a, cheapest, 'a');
	prep_push(b, cheapest->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(b, a);
}

static void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while ((*a) != min)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	case_x(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (stack_is_sorted(*a))
		return ;
	pb(a, b);
	if (len_a - 1 > 3)
		pb(a, b);
	while (len_a - 2 > 3)
	{
		prep_cheapest(*a, *b);
		move_a_to_b(b, a);
	}
	case_3(a);
	indexing(*b);
	indexing(*a);
	while (*b)
	{
		b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}
