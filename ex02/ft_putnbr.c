#include <unistd.h>
void ft_putint_char(int n)
{
	char c;
	c = n + '0';
	write (1, &c, 1);
}
void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
	}
	if (nbr <=  9)
	{
		ft_putint_char(nbr);
		return ;
	}
	ft_putnbr(nbr/10);
	ft_putint_char(nbr % 10);

}
int	main(void)
{
	ft_putnbr(-42);
	return 0;
}
