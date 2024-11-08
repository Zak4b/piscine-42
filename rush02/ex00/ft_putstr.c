#include <unistd.h>
#include "ft_putstr.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_puterror_with_return(char *str, int return_value)
{
	ft_puterror(str);
	return (return_value);
}
