#include "ft_check_char.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
