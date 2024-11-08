#include <stdlib.h>
#include "dict.h"
#include "ft_strings.h"

void	init_dict(t_dict *dict, unsigned int max_size)
{
	dict->error = 0;
	dict->size = 0;
	dict->max_size = max_size;
	dict->max_nbr_size = 0;
	dict->keys = malloc(sizeof(char **) * max_size);
	dict->values = malloc(sizeof(char **) * max_size);
	if (dict->keys == NULL || dict->values == NULL)
		dict->error = 1;
}

void	kill_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		free(dict->keys[i]);
		free(dict->values[i]);
		i++;
	}
	free(dict->keys);
	free(dict->values);
}

void	dict_add(t_dict *dict, char *key, char *value)
{
	int	new_max_nb_size;

	if (dict->size >= dict->max_size)
	{
		dict->error = 1;
		return ;
	}
	dict->keys[dict->size] = key;
	dict->values[dict->size] = value;
	new_max_nb_size = ft_strlen(key) + 2;
	if (new_max_nb_size > dict->max_nbr_size)
		dict->max_nbr_size = new_max_nb_size;
	dict->size++;
}

char	*dict_get(char *str, t_dict dict)
{
	int	i;

	i = 0;
	while (i < dict.size)
	{
		if (ft_strcmp(dict.keys[i], str) == 0)
			return (dict.values[i]);
		i++;
	}
	return (NULL);
}

char	*dict_get_by_len(int u_index, t_dict dict)
{
	int	i;
	int	u_len;

	i = 0;
	u_len = u_index * 3 + 1;
	while (i < dict.size)
	{
		if (ft_strlen(dict.keys[i]) == u_len)
			return (dict.values[i]);
		i++;
	}
	return (NULL);
}
