#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		i;
	char	flag;
	int		width;
	int		star;
	int		point;
	int		accuracy;
	char	type;
}	t_list;

int		ft_printf(const char *str, ...);
int		parser(char *str, va_list arg);
int		print_certain(t_list *fmt, va_list arg);
void	print_char(t_list *format, va_list arg);
void	print_percent(t_list *format);

void	init_fmt_vals(t_list *format);
int		define_specif(t_list *fmt_spec, char *str);
int		parse_accuracy(t_list *format, char *str, va_list arg);
int		parse_width(t_list *format, char *str, va_list arg);
int		parse_flag(t_list *format, char *str);

void	print_string(t_list *fmt_spec, va_list arg);
void	print_nums(t_list *format, va_list arg);
void	print_positive(char *str, t_list *fmt, int len, int dif);
void	print_negative(char *str, t_list *fmt, int len, int dif);
void	write_num(t_list *format, int len, int tmp, char *num);

void	print_un_nums(t_list *format, va_list arg);
void	print_uns_flag(char *str, t_list *fmt_spec, int len);

void	print_hex(t_list *format, va_list arg);
void	hex_flag(t_list *format, unsigned int num, int dif, int mod);
void	simple_write(int len, t_list *format, unsigned int num);
void	hex_write(t_list *format, int len, unsigned int num, int mod);
void	print_point(t_list *format, va_list arg);

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_iter(char c, t_list *format);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr(char *s, t_list *format);
void	print_with_flag(char *str, t_list *fmt_spec, int len);
char	*ft_itoa_uns(unsigned int n);
int		countbase(unsigned long num);
void	ft_putnbr_base(t_list *fmt, unsigned long nbr, int base, char *alph);
void	print_16(t_list *format, unsigned long num);

#endif