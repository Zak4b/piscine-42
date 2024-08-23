/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rs██████ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:52:36 by rs██████          #+#    #+#             */
/*   Updated: 2024/07/21 22:22:13 by rs██████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush00(int xlen, int ylen);

void	rush01(int xlen, int ylen);

void	rush02(int xlen, int ylen);

void	rush03(int xlen, int ylen);

void	rush04(int xlen, int ylen);

void	ft_display_error(char *str);

int	ft_atoi(char *string)
{
	long	result;
	int		i;
	int		negatif;

	negatif = 0;
	result = 0;
	i = 0;
	if (string[i] == '-')
		negatif = ++i;
	while (string[i] >= '0' && string[i] <= '9')
	{
		if (i > 10)
			break ;
		result = result * 10 + (string[i++] - '0');
	}
	if (negatif)
		result = result * -1;
	if (result < -2147483648 || result > 2147483647)
	{
		ft_display_error("Value out of integer bounds\n");
		result = 0;
	}
	return ((int)result);
}
#include <stdio.h>
#include <unistd.h>
int	main(int philipe, char *argv[])
{
	int	x;
	int	y;

	int i =1;

	while (argv[0][i] != '\0')
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	return (1);

















	if (argc == 1)
	{
		x = 10;
		y = 10;
	}
	else if (argc == 3)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
	}
	else
	{
		ft_display_error("Invalid number of arguments\n");
		return (1);
	}
	if (x <= 0 || y <= 0)
	{
		ft_display_error("x and y must be greater than 0\n");
		return (1);
	}
	rush03(x, y);
	return (0);
}
