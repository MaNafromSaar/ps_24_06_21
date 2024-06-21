/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:03:50 by mnaumann          #+#    #+#             */
/*   Updated: 2024/06/20 21:03:50 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*current;
	char			**args;
	int				i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		args = split(argv[1], ' ');
	else
		args = &argv[i++];
	//make extra function to get values
	
	initialize_stack(&a, args);
	current = a;
	if (stack_is_sorted(a))
		return (0);
	//check for sorted before going for cases

	//to do: shifted cases, solvable by rotating
	// find min rotate till min is on top

	if (stack_size(a) == 2)
		sa(&a);
	else if (stack_size(a) == 3)
		case_3(&a);

	//divide again where those do not need b
	else if (stack_size(a) == 4)
		case_4(&a, &b);
	else if (stack_size(a) == 5)
		case_5(&a, &b);
	else
		case_x(&a, &b);
	//case designator function

	current = a;
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
	return (0);
}
