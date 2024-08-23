/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:29:41 by a████             #+#    #+#             */
/*   Updated: 2024/07/30 15:29:47 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

char	*ft_string_from_base(int nbr, char *base);

int		calc_str_len(int value, int base_len);

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

char	*ft_rev_str(char *str)
{
	char	tmp;
	int		i;
	int		oposite_i;
	int		size;

	size = ft_strlen(str);
	oposite_i = size - 1;
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[oposite_i];
		str[oposite_i] = tmp;
		i++;
		oposite_i--;
	}
	return (str);
}

int	ft_check_base(char *base)
{
	int				i;
	unsigned char	char_count[256];

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	i = 0;
	while (i < 256)
		char_count[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		char_count[(unsigned char)base[i]]++;
		if (char_count[(unsigned char)base[i]] > 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	int_value;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (NULL);
	int_value = ft_atoi_base(nbr, base_from);
	return (ft_string_from_base(int_value, base_to));
}