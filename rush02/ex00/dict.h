#ifndef DICT_H
# define DICT_H
# define DEFAULT_DICT "numbers.dict"

typedef struct s_dict
{
	int		error;
	int		size;
	int		max_size;
	int		max_nbr_size;
	char	**keys;
	char	**values;
}	t_dict;

void	init_dict(t_dict *dict, unsigned int max_size);

void	kill_dict(t_dict *dict);

void	dict_add(t_dict *dict, char *key, char *value);

char	*dict_get(char *str, t_dict dict);

char	*dict_get_by_len(int u_index, t_dict dict);

#endif
