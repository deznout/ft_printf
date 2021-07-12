#include "libftprintf.h"

static void	help_hex(int len, t_list *format, int dif, unsigned int num)
{
	int	mod;

	mod = format->accuracy - len;
	if (format->width > len)
		hex_flag(format, num, dif, mod);
	else
	{
		while (0 < mod--)
			ft_putchar_iter('0', format);
		print_16(format, num);
	}
}

static void	output_hex(unsigned int num, t_list *format)
{
	int	len;
	int	mod;

	len = countbase(num);
	if (format->accuracy > len)
	{
		help_hex(len, format, format->width - format->accuracy, num);
	}
	else if ((format->accuracy >= 0 && format->accuracy <= len) \
	 && format->point == 0)
		simple_write(len, format, num);
	if (format->point == -1)
	{
		mod = format->width - len;
		hex_write(format, len, num, mod);
	}
}

static void	print_null(t_list *fmt_spec)
{
	int	mod;

	if (fmt_spec->accuracy != 0)
		while (0 < fmt_spec->accuracy--)
			ft_putchar_iter('0', fmt_spec);
	else if (fmt_spec->accuracy == 0 && fmt_spec->point == 0)
	{
		if (fmt_spec->width == 0)
			return ;
		else
			while (0 < fmt_spec->width--)
				ft_putchar_iter(' ', fmt_spec);
	}
	else if (fmt_spec->flag)
		print_uns_flag("0", fmt_spec, 1);
	else
	{
		mod = fmt_spec->width - 1;
		while (0 < mod--)
			ft_putchar_iter(' ', fmt_spec);
		ft_putchar_iter('0', fmt_spec);
	}
}

static void	print_zero(t_list *fmt_spec)
{
	int	mod;

	if (fmt_spec->width > fmt_spec->accuracy && fmt_spec->accuracy)
	{
		mod = fmt_spec->width - fmt_spec->accuracy;
		if (fmt_spec->flag == '-')
		{
			while (0 < fmt_spec->accuracy--)
				ft_putchar_iter('0', fmt_spec);
			while (0 < mod--)
				ft_putchar_iter(' ', fmt_spec);
		}
		else
		{
			while (0 < mod--)
				ft_putchar_iter(' ', fmt_spec);
			while (0 < fmt_spec->accuracy--)
				ft_putchar_iter('0', fmt_spec);
		}
	}
	else
		print_null(fmt_spec);
}

void	print_hex(t_list *format, va_list arg)
{
	unsigned int	num;

	num = va_arg(arg, unsigned int);
	if (format->accuracy < 0)
	{
		format->accuracy = 0;
		format->point = -1;
	}
	if (num == 0)
	{
		print_zero(format);
		return ;
	}
	output_hex(num, format);
}
