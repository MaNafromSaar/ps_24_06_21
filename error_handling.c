/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024-05-25 12:20:21 by user              #+#    #+#             */
/*   Updated: 2024-05-25 12:20:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	input_error(char *str)
{
	int digit_found = 0;
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == '-' || *str == '+' || *str == ' '
				|| *str == '\0' || *str == '\n'))
		{
			if (digit_found && (*str == ' ' || *str == '\0' || *str == '\n'))
			{
				digit_found = 0;
			}
			else
			{
				return (1);
			}
		}
		else if (ft_isdigit(*str))
		{
			digit_found = 1;
		}
		str++;
	}
	return (0);
}

int	duplicate_error(t_stack_node *stack, int data)
{
	while (stack)
	{
		if (!stack)
			return (0);
		if (stack->data == data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	error_handling(t_stack_node **a)
{
	write(1, "Error\n", 7);
	free_stack(a);
	exit(1);
}
