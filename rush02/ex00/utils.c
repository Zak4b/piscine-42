#include "ft_strings.h"
#include "ft_check_char.h"

int	ft_atoi(char *str);

int	check_number(char **num_str)
{
	int	i;

	i = 0;
	while (ft_is_digit((*num_str)[i]))
		i++;
	if ((*num_str)[i] != '\0')
		return (0);
	return (1);
}

int	check_key(char *key)
{
	int	len;
	int	val;

	len = ft_strlen(key);
	if (len <= 2)
	{
		val = ft_atoi(key);
		if (val < 20)
			return (1);
		else
			return (val % 10 == 0);
	}
	if (key[0] != '1')
		return (0);
	key++;
	while (*key && *key == '0')
		key++;
	return (*key == '\0');
}

void	ft_trim(char *value)
{
	int	i;

	i = ft_strlen(value) - 1;
	while (i >= 0 && ft_is_space(value[i]))
		value[i--] = '\0';
}

void	ft_reduce_spaces(char *str)
{
	int	i;
	int	j;
	int	space_found;

	i = 0;
	j = 0;
	space_found = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_space(str[i]))
		{
			str[j++] = str[i];
			space_found = 0;
		}
		else if (!space_found)
		{
			str[j++] = ' ';
			space_found = 1;
		}
		i++;
	}
	str[j] = '\0';
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return ((int)result * sign);
}
