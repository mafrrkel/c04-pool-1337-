#include <unistd.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (((9 <= base[i] && base[i] <= 13) || base[i] == 32)
			|| (base[i] == '-' || base[i] == '+'))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (ft_strlen(base));
}

void	ft_print_nbr(long n, char *base, int len)
{
	if (n == 0)
		return ;
	ft_print_nbr(n / len, base, len);
	write (1, &base[n % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long		n;

	n = nbr;
	len = ft_check_base(base);
	if (len == 0)
		return ;
	if (n == 0)
	{
		write (1, &base[0], 1);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	ft_print_nbr(n, base, len);
}
