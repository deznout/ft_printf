#include "libftprintf.h"

static int	ft_count(int n)
{
	int	j;

	j = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

static char	*ft_set(int n)
{
	char	*res;

	if (n < 0)
		res = (char *)malloc(sizeof(char) * ft_count(n) + 2);
	else
		res = (char *)malloc(sizeof(char) * ft_count(n) + 1);
	return (res);
}

static char	*ft_fill(int n, int k, char *res)
{
	int		i;
	char	s[12];

	i = 0;
	if (n == 0)
		res[k++] = '0';
	while (n > 0)
	{
		s[i++] = n % 10 + 48;
		n = n / 10;
	}
	i--;
	while (i >= 0)
		res[k++] = s[i--];
	res[k] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		k;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dst = ft_set(n);
	if (!dst)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		k = 1;
		dst[0] = '-';
		return (ft_fill(n, k, dst));
	}
	else
		return (ft_fill(n, k, dst));
}
