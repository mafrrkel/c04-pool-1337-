#include <stdio.h>
#include <unistd.h>

//fanction to len
int	ft_put_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len ++;
	}
	return (len);
}

// function to check base
int	ft_check_base(char *base)
{
	if (*base == '\0') //base case
		return(1);
	if (*base == '+' || *base == '-' ||
			*base <= 32 || *base == 127)// condition 2
		return 0;
	int	i;

	i = 1;
	while (*(base + i) != '\0')//comparition
	{
		if (*base == *(base + i))
				return 0;
		i++;
	}
	return (ft_check_base(base + 1));
}

//function to Transfer
void	ft_put_nbr_len_base(long n, int len, char *str)
{
	if (n == 0)
		return;
	int	i;

	i = n % len;
	n = n / len;
	ft_put_nbr_len_base(n, len, str);
	write(1, &str[i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	ret;
	long	nb;

	nb = nbr;
	//check base
	ret = ft_put_str_len(base);
	if (ret < 2)
		return;
	ret = ft_check_base(base);
	if (ret == 0)
		return;
	//ckeck for negative numbers
	if (nb < 0)
        {
                nb = -nb;
                write (1, "-", 1);
        }

	//Transfer
	ret = ft_put_str_len(base);
	if (nb > ret)
		ft_put_nbr_len_base(nb,ret,base);
	else
		write (1, &base[nb], 1);
}

int	main(void)
{
	char	HX[17] = "0123456789ABCDEF";
	ft_putnbr_base(-91, HX);
	return (0);
}
