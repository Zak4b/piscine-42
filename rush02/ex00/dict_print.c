#include "ft_strings.h"
#include "dict.h"
#include "stdlib.h"

void	ft_putstr(char *str);

void	print_from_dict(char *char_3, t_dict dict);
char	*build_string(char *dest, char c1, char c2, char c3);

void	print_hundreds(char	*char_3, t_dict dict)
{
	char	cmp_string[4];

	if (ft_strcmp(char_3, "000") == 0)
		return ;
	if (char_3[0] != 1)
		ft_putstr(dict_get(ft_strncpy(cmp_string, char_3, 1), dict));
	else
		ft_putstr(dict_get("1", dict));
	ft_putstr(" ");
	ft_putstr(dict_get("100", dict));
	if (char_3[1] != '0' || char_3[2] != '0')
	{
		ft_putstr(" ");
		if (char_3[1] != '0')
			print_from_dict(ft_strncpy(cmp_string, &char_3[1], 2), dict);
		else if (char_3[2] != '0')
			print_from_dict(ft_strncpy(cmp_string, &char_3[2], 1), dict);
	}
}

void	print_from_dict(char *char_3, t_dict dict)
{
	int		num_len;
	char	cmp_string[4];

	num_len = ft_strlen(char_3);
	if (num_len == 1)
	{
		ft_putstr(dict_get(char_3, dict));
		return ;
	}
	else if (num_len == 3)
	{
		print_hundreds(char_3, dict);
		return ;
	}
	if (char_3[0] == '1')
	{
		ft_putstr(dict_get(char_3, dict));
		return ;
	}
	ft_putstr(dict_get(build_string(cmp_string, char_3[0], '0', '\0'), dict));
	if (char_3[1] != '0')
	{
		ft_putstr(" ");
		ft_putstr(dict_get(ft_strncpy(cmp_string, &char_3[1], 1), dict));
	}
}
