/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_cord2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:28:46 by karai             #+#    #+#             */
/*   Updated: 2024/12/19 22:31:17 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_duplicate(int *array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (array[i] == array[i + 1])
		{
			return (true);
		}
		i += 1;
	}
	return (false);
}

void	ft_sort_upper(int *array, int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j += 1;
		}
		i += 1;
	}
}

bool	already_sort(int *array, int num)
{
	int	i;

	i = 0;
	while (i < num - 1)
	{
		if (array[i] > array[i + 1])
			return (false);
		i += 1;
	}
	return (true);
}

bool	ft_atoi_for_ps(char *np, int *val)
{
	long	a;
	int		pm;

	a = 0;
	pm = 1;
	while (*np == '\f' || *np == '\n' || *np == '\r' || *np == '\t'
		|| *np == '\v' || *np == ' ')
		np += 1;
	if (*np == '-')
		pm = -1;
	if (*np == '-' || *np == '+')
		np += 1;
	while (*np != '\0')
	{
		if (!(*np <= '9' && *np >= '0'))
			return (false);
		if (pm == 1 && (a > INT_MAX / 10 || ((INT_MAX - a * 10) < (*np - '0'))))
			return (false);
		if (a != 0 && pm == -1 && ((a > -1 * (INT_MIN / 10)) || (-1 * (INT_MIN
						+ a * 10)) < (*np - '0')))
			return (false);
		a = a * 10 + (*np++ - '0');
	}
	*val = a * pm;
	return (true);
}
