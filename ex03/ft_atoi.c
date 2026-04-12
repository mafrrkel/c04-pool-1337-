#include <stdio.h>
int	ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 32) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	main(void)
{
	char text[19] ="  ---+--+1234ab567";
	int rest;
	rest =	ft_atoi(text);
	printf ("%d", rest);
	return 0;

}
