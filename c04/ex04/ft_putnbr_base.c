/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:26:19 by a████             #+#    #+#             */
/*   Updated: 2024/07/23 14:26:21 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

// Return 0 if the base contains a char at least twice
int	ft_check_duplicate_chars(const char *str)
{
	int				i;
	unsigned char	char_count[256];

	i = 0;
	while (i < 256)
		char_count[i++] = 0;
	i = 0;
	while (str[i] != '\0')
	{
		char_count[(unsigned char)str[i]]++;
		if (char_count[(unsigned char)str[i]] > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;

	if (ft_strlen(base) < 2 || ft_check_duplicate_chars(base))
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	char	base_len;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (!ft_check_base(base))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	c = base[nb % base_len];
	write(1, &c, 1);
}
