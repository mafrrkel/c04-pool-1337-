#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}
int main(void)
{
	char st[8] ="mohamde";
	ft_putstr(st);
	return 0;
}
