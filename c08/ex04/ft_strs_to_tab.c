/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:38:17 by a████             #+#    #+#             */
/*   Updated: 2024/08/01 19:38:18 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*list;

	list = malloc(sizeof(t_stock_str) * (ac + 1));
	if (list == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		list[i].size = ft_strlen(av[i]);
		list[i].str = av[i];
		list[i].copy = ft_strdup(av[i]);
		if (list[i].copy == NULL)
		{
			while (i > 0)
				free(list[i--].copy);
			free(list);
			return (NULL);
		}
		i++;
	}
	list[ac].str = 0;
	list[ac].copy = 0;
	list[ac].size = 0;
	return (list);
}
