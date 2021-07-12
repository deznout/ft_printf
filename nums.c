#include "libftprintf.h"

static void	zero_presicion(t_list *fmt, char *num, int len, int tmp)
{
	if (tmp == 0 && fmt->width == 0)
		return ;
	if (tmp != 0 && fmt->width == 0)
		ft_putstr(num, fmt);
	else if (tmp == 0 && fmt->width != 0)
		print_with_flag("", fmt, len - 1);
	else if (fmt->width > len)
		print_with_flag(num, fmt, len);
	else
		ft_putstr(num, fmt);
}

static void	negative_accuracy(t_list *format)
{
	if (format->accuracy < 0)
	{
		format->accuracy = 0;
		format->point = -1;
	}
}

static int	just_help(int tmp, t_list *format, int mod, char *num)
{
	if (tmp < 0)
	{
		if (format->flag == '0')
		{
			ft_putchar_iter('-', format);
			while (0 < mod--)
				ft_putchar_iter('0', format);
			num++;
			while (*num)
				ft_putchar_iter(*num++, format);
			return (1);
		}
	}
	if (tmp >= 0)
	{
		if (format->flag == '0')
		{
			while (0 < mod--)
				ft_putchar_iter('0', format);
			while (*num)
				ft_putchar_iter(*num++, format);
			return (1);
		}
	}
	return (0);
}

static void	just_print_num(t_list *format, int len, char *num, int tmp)
{
	int	mod;

	mod = format->width - len;
	if (format->width <= len)
		ft_putstr(num, format);
	else if (format->width > len)
	{
		if (just_help(tmp, format, mod, num))
			return ;
		print_with_flag(num, format, len);
	}
}

void	print_nums(t_list *format, va_list arg)
{
	char	*num;
	int		tmp;
	int		len;

	tmp = va_arg(arg, int);
	num = ft_itoa(tmp);
	len = (int)ft_strlen(num);
	negative_accuracy(format);
	if (format->accuracy == 0 && format->point == -1)
		just_print_num(format, len, num, tmp);
	else if (format->accuracy == 0 && format->point == 0)
		zero_presicion(format, num, len, tmp);
	else if (format->accuracy > len && tmp >= 0)
		print_positive(num, format, len, format->width - format->accuracy);
	else if (format->accuracy >= len && tmp < 0)
		print_negative(num, format, len, \
		format->width - (format->accuracy + 1));
	else
		write_num(format, len, tmp, num);
	free(num);
}
