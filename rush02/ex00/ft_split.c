#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_strings.h"

char	*ft_strncpy(char *s1, char *s2, int n);
char	*ft_strndup(char *src, int size);

char	*read_file(char *file)
{
	char			c;
	char			*result;
	int				fd;
	unsigned int	file_len;

	file_len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &c, 1))
		file_len++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = malloc(sizeof(char) * (file_len + 1));
	read(fd, result, file_len);
	result[file_len] = '\0';
	return (result);
}

char	**ft_split_malloc(char *str, char separator)
{
	int		i;
	int		wc;
	char	**split_array;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != separator)
			i++;
	}
	split_array = malloc(sizeof(char *) * (wc + 1));
	return (split_array);
}

char	**ft_split(char *str, char separator)
{
	int		i;
	int		j;
	int		start;
	char	**out;

	out = ft_split_malloc(str, separator);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		start = i;
		while (str[i] && str[i] != separator)
			i++;
		if (i > start)
		{
			out[j] = malloc(sizeof(char) * ((i - start) + 1));
			ft_strncpy(out[j++], &str[start], i - start);
		}
	}
	out[j] = NULL;
	return (out);
}
