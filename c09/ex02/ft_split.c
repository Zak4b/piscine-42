/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:39:51 by a████             #+#    #+#             */
/*   Updated: 2024/07/31 13:39:52 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i])
			wc++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	return (wc);
}

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (src[i] && i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i++] = '\0';
	return (dup);
}

void	build_split_array(char *str, char *charset, char **array)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_separator(str[i], charset))
			i++;
		if (i > start)
			array[j++] = ft_strndup(&str[start], (i - start));
	}
	array[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		start;
	char	**split_array;

	split_array = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_separator(str[i], charset))
			i++;
		if (i > start)
			split_array[j++] = ft_strndup(&str[start], (i - start));
	}
	split_array[j] = 0;
	return (split_array);
}
