#include <stdio.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (1 <= *str && *str <= 32)
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str ++;
	}
	return (result * sign);
}
