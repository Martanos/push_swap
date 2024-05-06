/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:52:40 by malee             #+#    #+#             */
/*   Updated: 2024/05/07 02:54:42 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static ssize_t	partition(ssize_t *arr, ssize_t low, ssize_t high)
{
	ssize_t	pivot;
	ssize_t	itr;
	ssize_t	itr2;

	pivot = arr[high];
	itr = (low - 1);
	itr2 = low;
	while (itr2 <= high - 1)
	{
		if (arr[itr2] < pivot)
		{
			itr++;
			swap(&arr[itr], &arr[itr2]);
		}
		itr2++;
	}
	swap(&arr[itr + 1], &arr[high]);
	return (itr + 1);
}

static void	quicksort(ssize_t *arr, ssize_t low, ssize_t high)
{
	ssize_t	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

ssize_t	getmedian(t_stack **stack)
{
	ssize_t	*temp_array;
	size_t	i;
	t_node	*curr;
	ssize_t	median;

	if ((*stack)->length == 0)
		return (0);
	temp_array = (ssize_t *)malloc(sizeof(ssize_t) * (*stack)->length);
	if (temp_array == NULL)
		return (0);
	i = 0;
	curr = (*stack)->stack_head;
	while (curr != NULL)
	{
		temp_array[i++] = curr->value;
		curr = curr->next;
	}
	quicksort(temp_array, 0, (*stack)->length - 1);
	median = temp_array[(*stack)->length / 2];
	free(temp_array);
	return (median);
}
