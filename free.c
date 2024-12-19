/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:50:19 by karai             #+#    #+#             */
/*   Updated: 2024/12/19 23:01:50 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free2dim(char **array_2d)
{
	size_t	i;

	i = 0;
	if (array_2d == NULL)
		return (NULL);
	while (array_2d[i])
	{
		free(array_2d[i]);
		i += 1;
	}
	free(array_2d);
	return (NULL);
}

void	*print_error(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}
