/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024-05-14 14:23:40 by user              #+#    #+#             */
/*   Updated: 2024-05-14 14:23:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*tmp_a;
	t_stack_node	*target_a;
	long			match_index;

	while (b)
	{
		tmp_a = a;
		match_index = LONG_MAX;
		while (tmp_a)
		{
			if (tmp_a->data == b->data)
			{
				match_index = tmp_a->index;
				target_a = tmp_a;
				break ;
			}
			tmp_a = tmp_a->next;
		}
		if (match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_a;
		b->index = match_index;
		b = b->next;
	}
}

void	b_to_a(t_stack_node *a, t_stack_node *b)
{
	indexing(a);
	indexing(b);
	set_target_b(b, a);
}

t_stack_node	*get_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}
