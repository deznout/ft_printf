#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		lenth;

	va_start(argptr, str);
	lenth = parser((char *)str, argptr);
	va_end(argptr);
	return (lenth);
}

int	parser(char *str, va_list arg)
{
	t_list	format;

	format.i = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar_iter(*str++, &format);
		else if (*str++ == '%')
		{
			init_fmt_vals(&format);
			str += parse_flag(&format, str);
			str += parse_width(&format, str, arg);
			str += parse_accuracy(&format, str, arg);
			str += define_specif(&format, str);
			print_certain(&format, arg);
		}
	}
	return (format.i);
}

int	print_certain(t_list *fmt, va_list arg)
{
	if (fmt->type == 'i' || fmt->type == 'd')
		print_nums(fmt, arg);
	if (fmt->type == 'c')
		print_char(fmt, arg);
	if (fmt->type == 's')
		print_string(fmt, arg);
	if (fmt->type == 'u')
		print_un_nums(fmt, arg);
	if (fmt->type == 'x' || fmt->type == 'X')
		print_hex(fmt, arg);
	if (fmt->type == 'p')
		print_point(fmt, arg);
	if (fmt->type == '%')
		print_percent(fmt);
	return (0);
}

void	print_char(t_list *format, va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	if ((format->width))
	{
		format->width--;
		if (format->flag == '-')
		{
			ft_putchar_iter(c, format);
			while (0 < format->width--)
				ft_putchar_iter(' ', format);
		}
		else if (format->flag == 0)
		{
			while (0 < format->width--)
				ft_putchar_iter(' ', format);
			ft_putchar_iter(c, format);
		}
	}
	else
		ft_putchar_iter(c, format);
}

void	print_percent(t_list *format)
{
	format->width--;
	if (!format->flag)
	{
		while (0 < format->width--)
			ft_putchar_iter(' ', format);
		ft_putchar_iter('%', format);
	}
	if (format->flag == '0')
	{
		while (0 < format->width--)
			ft_putchar_iter('0', format);
		ft_putchar_iter('%', format);
	}
	if (format->flag == '-')
	{
		ft_putchar_iter('%', format);
		while (0 < format->width--)
			ft_putchar_iter(' ', format);
	}
}
