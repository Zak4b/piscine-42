#include <stdlib.h>
#include "ft_strings.h"
#include "dict.h"
#include "ft_putstr.h"

void	ft_putstr(char *str);

void	print_from_dict(char *char_3, t_dict dict);

char	*build_string(char *dest, char c1, char c2, char c3)
{
	dest[0] = c1;
	dest[1] = c2;
	dest[2] = c3;
	dest[3] = '\0';
	return (dest);
}

char	*trim_zero(char	*char_3)
{
	int	i;

	i = 0;
	while (char_3[i] == '0')
		i++;
	if (ft_strlen(char_3) == i)
		return (char_3);
	return (char_3 + i);
}

void	calc_num_data(char *num_str, int *num_len, int *units, int *part_len)
{
	*num_len = ft_strlen(num_str);
	*part_len = *num_len % 3;
	*units = *num_len / 3;
	if (*num_len % 3 > 0)
		*units = *units + 1;
	if (*part_len == 0)
		*part_len = 3;
}

int	ft_putnbr_char(char *num_str, t_dict dict)
{
	char	char_3[4];
	int		i;
	int		units;
	int		num_len;
	int		part_len;

	calc_num_data(num_str, &num_len, &units, &part_len);
	if (num_len > dict.max_nbr_size)
		return (ft_puterror_with_return("Dict error. Number is too big", 0));
	i = 0;
	while (i < num_len)
	{
		ft_strncpy(char_3, &num_str[i], part_len);
		print_from_dict(trim_zero(char_3), dict);
		if (--units > 0 && ft_strcmp(char_3, "000") != 0)
		{
			ft_putstr(" ");
			ft_putstr(dict_get_by_len(units, dict));
			if (units > 0)
				ft_putstr(" ");
		}
		i += part_len;
		part_len = 3;
	}
	return (1);
}
