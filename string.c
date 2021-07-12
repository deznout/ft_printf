#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = ((char *)s)[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			k;
	char			*sub;
	unsigned int	strlen;

	k = 0;
	if (!s)
		return (NULL);
	strlen = (int)ft_strlen(s);
	if (start >= strlen)
	{
		sub = (char *)malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (start + len >= strlen)
		sub = (char *)malloc(sizeof(char) * (strlen - start));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (k < len && start < strlen)
		sub[k++] = s[start++];
	sub[k] = '\0';
	return (sub);
}

static void	help_string(t_list *fmt_spec, int len, char *str)
{
	if (fmt_spec->accuracy > len || \
	(fmt_spec->accuracy == 0 && fmt_spec->point == -1) \
	|| (fmt_spec->accuracy < 0 && fmt_spec->star == 1))
	{
		if (fmt_spec->width == 0 || fmt_spec->width <= len)
			ft_putstr(str, fmt_spec);
		if (fmt_spec->width > len)
			print_with_flag(str, fmt_spec, len);
	}
	else if (fmt_spec->accuracy <= len && fmt_spec->accuracy != 0)
	{
		str = ft_substr(str, 0, fmt_spec->accuracy);
		len = (int)ft_strlen(str);
		if (fmt_spec->width == 0)
			ft_putstr(str, fmt_spec);
		else if (fmt_spec->width > 0)
			print_with_flag(str, fmt_spec, len);
		free(str);
	}
}

static void	check_accuracy(t_list *format)
{
	if (format->accuracy == 0 && format->point == 0)
	{
		if (!format->width)
			return ;
		else
			while (0 < format->width--)
				ft_putchar_iter(' ', format);
	}
}

void	print_string(t_list *fmt_spec, va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	help_string(fmt_spec, len, str);
	check_accuracy(fmt_spec);
}
