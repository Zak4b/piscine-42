#include <unistd.h>
#include <stdlib.h>
#include "dict.h"
#include "dict_parser.h"
#include "ft_putstr.h"
#include "utils.h"
#include "ft_check_char.h"

char	*read_file(char *file);
char	**ft_split(char *str, char separator);
int		ft_putnbr_char(char *num_str, t_dict dict);
void	ft_bubble_sort(t_dict *dict);

int	handle_args(int argc, char **argv, char **dict_file, char **number)
{
	if (argc == 1 || argc > 3)
		return (ft_puterror_with_return("Invalid number of arguments\n", 0));
	else if (argc == 3)
	{
		*dict_file = argv[1];
		*number = argv[2];
	}
	else
	{
		*dict_file = DEFAULT_DICT;
		*number = argv[1];
	}
	while (**number == '0' && *(*number + 1))
		*number = *number + 1;
	if (check_number(&*number))
		return (1);
	else
		return (ft_puterror_with_return("Invalid number\n", 0));
}

int	fill_dict(t_dict *dict, char *dict_file)
{
	int		i;
	char	**sp;
	char	*file_content;

	file_content = read_file(dict_file);
	if (file_content == NULL)
	{
		ft_puterror("Can't open dict file\n");
		return (0);
	}
	sp = ft_split(file_content, '\n');
	i = 0;
	init_dict(dict, 120);
	while (sp[i])
	{
		if (parse_line(sp[i], dict) == 0)
			return (0);
		free(sp[i++]);
	}
	free(sp);
	free(file_content);
	ft_bubble_sort(dict);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	*nb;
	t_dict	dict;

	if (!handle_args(argc, argv, &dict_file, &nb))
		return (1);
	if (!fill_dict(&dict, dict_file))
		return (2);
	ft_putnbr_char(nb, dict);
	kill_dict(&dict);
	ft_putstr("\n");
	return (0);
}
