#include <stdio.h>
//check base function
int     ft_check_base(char *base)
{
        if (*base == '\0') //base case
                return(1);
        if (*base == '+' || *base == '-' ||
                        *base <= 32 || *base == 127)// condition 2
                return 0;
        int     i;

        i = 1;
        while (*(base + i) != '\0')//comparition
        {
                if (*base == *(base + i))
                                return 0;
                i++;
        }
        return (ft_check_base(base + 1));
}

//len function
int ft_str_len(char *str)
{
	int len;
	len = 0;
	while (str[len] != '\0')
	{
		len ++;
	}
	return len;
}

//index extraction function
int ft_digit_value(char *str, char *base)
{
	int i;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == *str)
			return i;
		i ++;
	}
}
//Conversion function
int ft_atoi_transfer(char *str,char *base,int len)
{
	if(!(*str >= base[0] && *str <= base[len - 1])&&
			(*str != '-' && *str != '+' && *str != ' '))
		return 0;
	else if (*str == '-')
		return (-1*ft_atoi_transfer(str + 1,base,len));
	else if (*str == '+' || *str == ' ')
		return ft_atoi_transfer(str + 1,base,len);
	else
	{
		int result;

		result = 0;
		while (*str >= base[0] && *str <= base[len - 1])
		{
			result = (result * len) + ft_digit_value(str,base);
			str ++;
		}
		return result;

	}	
}



int	ft_atoi_base(char *str, char *base)
{
	//check the validity of base
	int	check;
	int	len;
	len = ft_str_len(base);
	if (len < 2)
		return 0;
	check = ft_check_base(base);
	if (check == 0)
		return 0;

	//convert the series to a decimal number
	return (ft_atoi_transfer(str,base,len));
}
int	main(void)
{
	int	number;
	char text[10] = "-+ +--100";
	char binery[9] = "01234567";

	number = ft_atoi_base(text,binery);
	printf ("%d",number);
	return 0;
}
