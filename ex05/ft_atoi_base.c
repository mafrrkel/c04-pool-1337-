#include <stdio.h>

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
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_get_index(char *str, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == *str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		len;
	int		result;

	result = 0;
	sign = 1;
	len = ft_check_base(base);
	if (len == 0)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (ft_get_index(str, base) != -1)
	{
		result = result * len + ft_get_index(str, base);
		str++;
	}
	return (result * sign);
}
