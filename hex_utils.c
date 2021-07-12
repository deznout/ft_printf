#include "libftprintf.h"

void	hex_flag(t_list *format, unsigned int num, int dif, int mod)
{
	if (format->flag == '-')
	{
		while (0 < mod--)
			ft_putchar_iter('0', format);
		print_16(format, num);
		while (0 < dif--)
			ft_putchar_iter(' ', format);
	}
	else
	{
		while (0 < dif--)
			ft_putchar_iter(' ', format);
		while (0 < mod--)
			ft_putchar_iter('0', format);
		print_16(format, num);
	}
}

void	hex_write(t_list *format, int len, unsigned int num, int mod)
{
	if (format->width > len)
	{
		if (format->flag == '-')
		{
			print_16(format, num);
			while (0 < mod--)
				ft_putchar_iter(' ', format);
		}
		else if (format->flag == '0')
		{
			while (0 < mod--)
				ft_putchar_iter('0', format);
			print_16(format, num);
		}
		else
		{
			while (0 < mod--)
				ft_putchar_iter(' ', format);
			print_16(format, num);
		}
	}
	else
		print_16(format, num);
}

void	simple_write(int len, t_list *format, unsigned int num)
{
	int	mod;

	mod = format->width - len;
	if (format->width <= len)
		print_16(format, num);
	else
	{
		if (format->flag == '-')
		{
			print_16(format, num);
			while (0 < mod--)
				ft_putchar_iter(' ', format);
		}
		else
		{
			while (0 < mod--)
				ft_putchar_iter(' ', format);
			print_16(format, num);
		}
	}
}

void	print_16(t_list *format, unsigned long num)
{
	if ((format->type == 'x' || format->type == 'p'))
		ft_putnbr_base(format, num, 16, "0123456789abcdef");
	else
		ft_putnbr_base(format, num, 16, "0123456789ABCDEF");
}

void	ft_putnbr_base(t_list *fmt, unsigned long nbr, int base, char *alph)
{
	if (nbr < (unsigned long)base)
		fmt->i += write(1, alph + nbr, 1);
	else
	{
		ft_putnbr_base(fmt, nbr / base, base, alph);
		ft_putnbr_base(fmt, nbr % base, base, alph);
	}
}
