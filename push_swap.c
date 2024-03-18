/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/18 23:49:12 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
			break ;
		s1++;
		s2++;
	}
	return(*s1-*s2);
}
int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;

	if (argc > 1)
	{

		while (i < argc)
		{

			j = i + 1;
			while (j < argc)
			{

				// if (ft_strcmp(argv[i], argv[j])< 0)
				// {
				// 	printf("str");
				// 	printf("%d", i);
				// }

				j++;
			}
			i++;
		}
	}
}