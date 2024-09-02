/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:23:25 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:51:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# define DECIMAL 10
# define HEXA 16
# define DECIMAL_BASE "0123456789"
# define HEXA_BASE "0123456789abcdef"
# define HEXA_U_BASE "0123456789ABCDEF"
# define SPECIFIER "cdip%suxX"
# define FLAGS " #0+-"
# define SPEC_COUNT 9
# define FLAGS_COUNT 5
# define S_NULL "(null)"
# define ZEROX "0x"
# define ZEROXU "0X"

enum {
	SPACE = 0,
	SHARP,
	ZERO,
	PLUS,
	REVERSE
};

enum {
	ERROR = -1,
	FALSE,
	TRUE,
};

typedef struct s_options {
	char	s;
	int		w;
	int		p;
	int		f[5];
}	t_o;

int		ft_printf(const char *formats, ...);
int		read_formats(char *formats, va_list args);
int		decode_format(char *f, int n, va_list args);
int		decode_flags(char *f, size_t c, int n, t_o *op);
int		decode_width(char *f, size_t c, int n, t_o *op);
int		decode_precision(char *f, size_t c, int n, t_o *op);
int		print_format(t_o op, va_list args);
int		print_sharp(size_t *count, t_o op);
int		print_width(size_t *count, int len, t_o *op);
int		print_precision(size_t *count, int len, t_o *op);
int		print_format_c(char c, t_o op);
int		print_format_s(char *arg, t_o op);
int		print_format_p(void *p, t_o op);
int		print_format_di(int n, t_o op);
int		print_format_u(unsigned int n, t_o op);
int		print_format_xux(unsigned int x, t_o op);
int		print_format_per(t_o op);
int		print_without_format(char c);

int		is_num(char c);
int		measure_len(int len, t_o op);
int		base_len(unsigned long n, int base, t_o op);
int		print_nbr_base(size_t *count, unsigned long n, int base, t_o op);

#endif