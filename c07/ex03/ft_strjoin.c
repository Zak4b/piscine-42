/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:52:35 by a████             #+#    #+#             */
/*   Updated: 2024/07/30 11:52:38 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*joined_str;

	i = 0;
	total_len = 0;
	if (size > 0)
	{
		while (i < size)
			total_len += ft_strlen(strs[i++]);
		total_len += (size -1) * ft_strlen(sep);
	}
	joined_str = malloc(sizeof(char) * (total_len + 1));
	i = 0;
	while (i <= total_len)
		joined_str[i++] = '\0';
	i = 0;
	while (i < size)
	{
		if (i != 0)
			ft_strcat(joined_str, sep);
		ft_strcat(joined_str, strs[i++]);
	}
	joined_str[total_len] = '\0';
	return (joined_str);
}
