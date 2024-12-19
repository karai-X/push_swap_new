/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_cord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:21:57 by karai             #+#    #+#             */
/*   Updated: 2024/12/19 23:19:24 by karai            ###   ########.fr       */
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
	if (ft_comp_cord(array, argc - 1) == NULL)
	{
		write(2, "Error\n", 6);
		free(array);
		return (NULL);
	}
	if (already_sort(array, argc - 1) == true)
	{
		free(array);
		exit(0);
	}
	return (array);
}

int	*ft_comp_cord_for_split(int *argc, char ***argv, int *split_flag)
{
	int	*array;

	if (*argc < 2)
		return (print_error());
	if (*argc == 2)
	{
		*split_flag = 1;
		*argv = ft_split((*argv)[1], ' ');
		if (*argv == NULL)
			return (print_error());
		*argc = 0;
		while ((*argv)[*argc])
			*argc += 1;
		*argc = *argc + 1;
	}
	else
		*argv = &(*argv)[1];
	array = malloc(sizeof(int) * (*argc - 1));
	if (array == NULL)
	{
		if (split_flag)
			free2dim(*argv);
		return (print_error());
	}
	return (array);
}

int	*ft_comp_cord_main(int *argc, char *argv[])
{
	int	i;
	int	*array;
	int	split_flag;

	split_flag = 0;
	array = ft_comp_cord_for_split(argc, &argv, &split_flag);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < *argc - 1)
	{
		if (ft_atoi_for_ps(argv[i], &(array[i])) == false)
		{
			if (split_flag)
				free2dim(argv);
			free(array);
			write(2, "Error\n", 6);
			return (NULL);
		}
		i += 1;
	}
	if (split_flag)
		free2dim(argv);
	return (ft_comp_cord_main_part(*argc, array));
}
