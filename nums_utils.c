#include "libftprintf.h"

static void	positive_help(t_list *fmt, int mod, int dif, char *str)
{
	if (fmt->flag == '-')
	{
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		while (*str)
			ft_putchar_iter(*str++, fmt);
		while (0 < dif--)
			ft_putchar_iter(' ', fmt);
	}
	else
	{
		while (0 < dif--)
			ft_putchar_iter(' ', fmt);
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		while (*str)
			ft_putchar_iter(*str++, fmt);
	}
}

void	print_positive(char *str, t_list *fmt, int len, int dif)
{
	int	mod;

	mod = fmt->accuracy - len;
	if (fmt->width > len)
		positive_help(fmt, mod, dif, str);
	else
	{
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		while (*str)
			ft_putchar_iter(*str++, fmt);
	}
}

static void	negative_flag(t_list *fmt, int mod, int dif, char *str)
{
	if (fmt->flag == '-')
	{
		ft_putchar_iter('-', fmt);
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		str++;
		while (*str)
			ft_putchar_iter(*str++, fmt);
		while (0 < dif--)
			ft_putchar_iter(' ', fmt);
	}
	else
	{
		while (0 < dif--)
			ft_putchar_iter(' ', fmt);
		ft_putchar_iter('-', fmt);
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		str++;
		while (*str)
			ft_putchar_iter(*str++, fmt);
	}
}

void	print_negative(char *str, t_list *fmt, int len, int dif)
{
	int	mod;

	mod = fmt->accuracy - len + 1;
	if (fmt->width >= 0 && fmt->width <= (fmt->accuracy + 1))
	{
		ft_putchar_iter('-', fmt);
		while (0 < mod--)
			ft_putchar_iter('0', fmt);
		str++;
		while (*str)
			ft_putchar_iter(*str++, fmt);
	}
	if (fmt->width >= fmt->accuracy + 2)
		negative_flag(fmt, mod, dif, str);
}

void	write_num(t_list *format, int len, int tmp, char *num)
{
	if ((format->accuracy < len && tmp < 0) \
	|| (format->accuracy <= len && tmp >= 0))
	{
		if (format->width > len && format->accuracy >= 0)
			print_with_flag(num, format, len);
		else
			ft_putstr(num, format);
	}
}
