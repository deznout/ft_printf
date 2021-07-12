#include "libftprintf.h"

static void	point_flag(t_list *format, int mod, unsigned long num)
{
	if (format->flag == '-')
	{
		ft_putchar_iter('0', format);
		ft_putchar_iter('x', format);
		if (num)
			print_16(format, num);
		if (format->point == -1 && !num)
			ft_putchar_iter('0', format);
		while (0 < mod--)
			ft_putchar_iter(' ', format);
	}
	else
	{
		while (0 < mod--)
			ft_putchar_iter(' ', format);
		ft_putchar_iter('0', format);
		ft_putchar_iter('x', format);
		if (num)
			print_16(format, num);
		if (format->point == -1 && !num)
			ft_putchar_iter('0', format);
	}
}

int	countbase(unsigned long num)
{
	int	i;

	i = 0;
	if (!num)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

void	print_point(t_list *format, va_list arg)
{
	unsigned long	num;
	int				len;
	int				mod;

	num = va_arg(arg, unsigned long);
	if (num)
		len = countbase(num) + 2;
	else if (format->point == -1)
		len = 3;
	else
		len = 2;
	mod = format->width - len;
	point_flag(format, mod, num);
}
