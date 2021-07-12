#include "libftprintf.h"

void	init_fmt_vals(t_list *format)
{
	format->flag = 0;
	format->width = 0;
	format->star = 0;
	format->point = -1;
	format->accuracy = 0;
	format->type = 0;
}

int	define_specif(t_list *fmt_spec, char *str)
{
	char	*spec;

	spec = "cspdiuxX%e";
	while (*spec)
	{
		if (*str == *spec)
		{
			fmt_spec->type = *spec;
			return (1);
		}
		spec++;
	}
	return (0);
}

int	parse_accuracy(t_list *format, char *str, va_list arg)
{
	int	j;

	j = 1;
	if (str[0] != '.')
		return (0);
	else
		format->point = 0;
	if (str[j] == '*')
	{
		format->star = 1;
		format->accuracy = va_arg(arg, int);
		return (2);
	}
	while (str[j] >= 48 && str[j] <= 57)
		format->accuracy = (format->accuracy * 10) + (str[j++] - 48);
	return (j);
}

int	parse_width(t_list *format, char *str, va_list arg)
{
	int	j;

	j = 0;
	if (str[j] == '*')
	{
		format->width = va_arg(arg, int);
		if (format->width < 0)
		{
			format->flag = '-';
			format->width = -format->width;
		}
		return (1);
	}
	while (str[j] >= 48 && str[j] <= 57)
		format->width = (format->width * 10) + (str[j++] - 48);
	return (j);
}

int	parse_flag(t_list *format, char *str)
{
	int	j;

	j = 0;
	if (str[j] == ' ')
		j++;
	while (str[j] == '-' || str[j] == '0')
	{
		if (str[j] == '0' && !format->flag)
			format->flag = '0';
		else if (str[j] == '-')
			format->flag = '-';
		j++;
	}
	return (j);
}
