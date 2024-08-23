/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:27:09 by a████             #+#    #+#             */
/*   Updated: 2024/07/30 19:27:10 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_rev_str(char *str);

int	ft_char_pos(char *string, char element)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_get_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*sign = -*sign;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	long	result;
	int		sign;
	int		i;
	int		char_index;
	int		base_len;

	base_len = ft_strlen(base);
	result = 0;
	i = ft_atoi_get_sign(str, &sign);
	while (str[i])
	{
		char_index = ft_char_pos(base, str[i++]);
		if (char_index < 0)
			break ;
		result = result * base_len + (char_index);
	}
	return ((int)result * sign);
}

int	calc_str_len(int value, int base_len)
{
	long	nb;
	int		len;

	len = 0;
	nb = value;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / base_len;
		len++;
	}
	if (len == 0)
		len = 1;
	return (len);
}

char	*ft_string_from_base(int nbr, char *base)
{
	char	base_len;
	char	*str;
	int		str_len;
	int		char_count;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	char_count = 0;
	str_len = calc_str_len(nbr, base_len);
	str = malloc(sizeof(char) * (str_len + 1));
	str[str_len] = '\0';
	if (nb == 0)
		str[0] = base[0];
	if (nb < 0)
	{
		str[str_len - 1] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[char_count++] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (ft_rev_str(str));
}
