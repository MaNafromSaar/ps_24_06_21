/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024-05-13 18:40:22 by user              #+#    #+#             */
/*   Updated: 2024-05-13 18:40:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	case_3(t_stack_node **a)
{
	t_stack_node *max;

	if (stack_is_sorted(*a))
		return ;
	max = find_max(*a);
	if ((*a)->data == max->data)
		ra(a);
	else if ((*a)->next->data == max->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	case_4(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	if (stack_is_sorted(*a))
		return ;
	indexing(*a);
	min = find_min(*a);
	if (min->above_median)
	{
		while ((*a)->data != min->data)
			rra(a);
	}
	else
	{
		while ((*a)->data != min->data)
			ra(a);
	}
	if (stack_is_sorted(*a))
		return ;
	pb(a, b);
	case_3(a);
	pa(b, a);
	indexing(*a);
}

void	case_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	indexing(*a);
	min = find_min(*a);
	if ((*a)->data != min->data)
	{
		if (min->above_median)
		{
			while ((*a)->data != min->data)
				rra(a);
		}
		else
		{
			while ((*a)->data != min->data)
				ra(a);
		}
	}
	if (stack_is_sorted(*a))
		return ;	
	pb(a, b);
	case_4(a, b);
	pa(b, a);
	indexing(*a);
}
