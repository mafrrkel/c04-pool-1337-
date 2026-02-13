#include <stdio.h>
int	ft_atoi(char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-' )
			return (-1 * ft_atoi(str + 1));
		else
			return (ft_atoi(str + 1));
	}
	else if ( *str == ' ')
		return(ft_atoi(str +1));
	else if (*str >= '0' && *str <= '9')
	{
		int rest;
		rest = 0;
		while (*str >= '0' && *str <= '9')
		{
			rest = 10 * rest + (*str - '0');
			str++;
		}
		return rest;
	}
	else 
		return 0;
}
int	main(void)
{
	char text[19] ="  ---+--+1234ab567";
	int rest;
	rest =	ft_atoi(text);
	printf ("%d", rest);
	return 0;

}
