/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:53:14 by a████             #+#    #+#             */
/*   Updated: 2024/07/19 11:18:35 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	ft_str_is_alpha(char c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		return (0);
	}
	return (1);
}

int	ft_is_alpha_or_numeric(char c)
{
	if (ft_str_is_alpha(c) || ('0' <= c && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			if (i == 0 || (!ft_is_alpha_or_numeric(str[i - 1])))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
