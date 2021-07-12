#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_iter(char c, t_list *format)
{
	write(1, &c, 1);
	format->i++;
}

static int	ft_count_uns(unsigned int n)
{
	int	j;

	j = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa_uns(unsigned int n)
{
	char	*dst;
	int		k;
	int		i;
	char	s[12];

	k = 0;
	i = 0;
	dst = (char *)malloc(sizeof(char) * ft_count_uns(n) + 1);
	if (!dst)
		return (NULL);
	if (n == 0)
		dst[k++] = '0';
	while (n > 0)
	{
		s[i++] = n % 10 + 48;
		n = n / 10;
	}
	i--;
	while (i >= 0)
		dst[k++] = s[i--];
	dst[k] = '\0';
	return (dst);
}

void	ft_putstr(char *s, t_list *format)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_iter(s[i++], format);
}
