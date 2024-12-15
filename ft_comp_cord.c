/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_cord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:21:57 by karai             #+#    #+#             */
/*   Updated: 2024/12/15 16:06:30 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_comp_cord(int *array, int length)
{
	int	*temp_array;
	int	i;

	temp_array = (int *)malloc(sizeof(int) * length);
	if (temp_array == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		temp_array[i] = array[i];
	ft_sort_upper(temp_array, length);
	if (ft_is_duplicate(temp_array, length))
	{
		free(temp_array);
		return (NULL);
	}
	ft_comp_cord_part(temp_array, array, length);
	free(temp_array);
	return (array);
}

void	ft_comp_cord_part(int *temp_array, int *array, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
			if (temp_array[j++] == array[i])
				break ;
		array[i++] = j;
	}
}

int	*ft_comp_cord_main_part(int argc, int *array)
{
	if (already_sort(array, argc - 1) == true)
	{
		free(array);
		return (NULL);
	}
	if (ft_comp_cord(array, argc - 1) == NULL)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	*ft_comp_cord_main(int argc, char *argv[])
{
	int	i;
	int	*array;

	if (argc <= 2)
		return (NULL);
	array = malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_for_ps(argv[i], &(array[i - 1])) == false)
		{
			free(array);
			return (NULL);
		}
		i += 1;
	}
	return (ft_comp_cord_main_part(argc, array));
}
