/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:23:25 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:50:35 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DECIMAL 10
# define HEXA 16
# define DECIMAL_BASE "0123456789"
# define HEXA_BASE "0123456789abcdef"
# define HEXA_U_BASE "0123456789ABCDEF"
# define SPECIFIER "cdip%suxX"
# define SPEC_COUNT 9
# define S_NULL "(null)"
# define ZEROX "0x"

int	ft_printf(const char *formats, ...);
int	read_formats(char *f, va_list args);
int	print_format(char s, va_list args);
int	print_format_c(char c);
int	print_format_s(char *s);
int	print_format_p(void *p);
int	print_format_di(long n);
int	print_format_u(unsigned int n);
int	print_format_xux(char s, unsigned int x);
int	print_format_per(void);
int	print_without_format(char c);

int	print_nbr_base(size_t *count, unsigned long n, int base, char *base_form);

#endif