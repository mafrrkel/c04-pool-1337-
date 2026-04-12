#include <unistd.h>

void	ft_put_int_to_char(int n)
{
	char	c;

	c = n + '0';
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	if (n <= 9)
	{
		ft_put_int_to_char(n);
		return ;
	}
	ft_putnbr(n / 10);
	ft_put_int_to_char(n % 10);
}
