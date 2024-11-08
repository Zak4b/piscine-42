#include <stdlib.h>
#include "ft_check_char.h"
#include "ft_strings.h"
#include "dict.h"
#include "dict_parser.h"
#include "utils.h"
#include "ft_putstr.h"

char	*parse_key(char **str)
{
	char	*key_string;
	char	*start;
	int		length;

	while (ft_is_space(**str))
		(*str)++;
	start = *str;
	while (ft_is_digit(**str))
		(*str)++;
	length = *str - start;
	if (length == 0)
		return (NULL);
	key_string = ft_strndup(start, length);
	return (key_string);
}

int	skip_separator(char	**str)
{
	int	i;

	i = 0;
	while (ft_is_space((*str)[i]))
		i++;
	if ((*str)[i++] != ':')
		return (0);
	while (ft_is_space((*str)[i]))
		i++;
	*str = &(*str)[i];
	return (1);
}

char	*parse_value(char **str)
{
	char	*value_string;
	char	*start;
	int		length;

	start = *str;
	while (**str != '\0')
		(*str)++;
	length = *str - start;
	if (length == 0)
		return (NULL);
	value_string = ft_strdup(start);
	return (value_string);
}

void	trim_value(char **value)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((*value)[i++])
	{
		i++;
		len++;
	}
}

int	parse_line(char *line, t_dict *dict)
{
	char	*key;
	int		valid_separator;
	char	*value;

	key = parse_key(&line);
	valid_separator = skip_separator(&line);
	value = parse_value(&line);
	if (valid_separator == 0)
		ft_puterror("Dict Error. Invalid Format\n");
	else if (key != NULL && value != NULL && check_key(key))
	{
		ft_trim(value);
		ft_reduce_spaces(value);
		dict_add(dict, key, value);
		return (1);
	}
	free(key);
	free(value);
	ft_puterror("Dict Error. Error during parsing\n");
	return (0);
}
