/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:25:17 by a████             #+#    #+#             */
/*   Updated: 2024/07/23 18:25:18 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_check_base(char *base)
{
	int				i;
	unsigned char	char_count[256];

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
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
	if (!ft_check_base(base))
		return (0);
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
