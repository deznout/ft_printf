#include "libftprintf.h"

void	print_with_flag(char *str, t_list *fmt_spec, int len)
{
	int	mod;

	mod = fmt_spec->width - len;
	if (fmt_spec->flag == '-')
	{
		while (*str)
			ft_putchar_iter(*str++, fmt_spec);
		while (0 < mod--)
			ft_putchar_iter(' ', fmt_spec);
	}
	else
	{
		while (0 < mod--)
			ft_putchar_iter(' ', fmt_spec);
		while (*str)
			ft_putchar_iter(*str++, fmt_spec);
	}
}

void	print_uns_flag(char *str, t_list *fmt_spec, int len)
{
	int	mod;

	mod = fmt_spec->width - len;
	if (fmt_spec->flag == '-')
	{
		while (*str)
			ft_putchar_iter(*str++, fmt_spec);
		while (0 < mod--)
			ft_putchar_iter(' ', fmt_spec);
	}
	else if (fmt_spec->flag == '0')
	{
		while (0 < mod--)
			ft_putchar_iter('0', fmt_spec);
		while (*str)
			ft_putchar_iter(*str++, fmt_spec);
	}
	else
	{
		while (0 < mod--)
			ft_putchar_iter(' ', fmt_spec);
		while (*str)
			ft_putchar_iter(*str++, fmt_spec);
	}
}

static void	help_un_nums(t_list *format, int len, char *num, unsigned int tmp)
{
	if ((format->accuracy >= 0 && format->accuracy <= len) \
	 && format->point == 0)
	{
		if (tmp == 0 && format->width == 0 && format->accuracy == 0)
			return ;
		if (tmp != 0 && format->width == 0)
			ft_putstr(num, format);
		else if (tmp == 0 && format->width != 0 && format->accuracy == 0)
			print_with_flag("", format, len - 1);
		else if (format->width <= len)
			ft_putstr(num, format);
		else
			print_with_flag(num, format, len);
	}
	if (format->point == -1)
	{
		if (format->width > len)
			print_uns_flag(num, format, len);
		else
			ft_putstr(num, format);
	}
}

void	print_un_nums(t_list *format, va_list arg)
{
	char			*num;
	unsigned int	tmp;
	int				len;

	tmp = va_arg(arg, unsigned int);
	num = ft_itoa_uns(tmp);
	len = (int)ft_strlen(num);
	if (format->accuracy < 0)
	{
		format->accuracy = 0;
		format->point = -1;
	}
	if (format->accuracy > len)
		print_positive(num, format, len, format->width - format->accuracy);
	help_un_nums(format, len, num, tmp);
	free(num);
}
