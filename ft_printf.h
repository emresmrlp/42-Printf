/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:07:24 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/19 12:26:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# ifdef __APPLE__
#  define NULLSTRING "(null)"
#  define NULLPOINTER "0x0"
# else
#  define NULLSTRING "(null)"
#  define NULLPOINTER "(nil)"
# endif

int	ft_printf(const char *str, ...);
int	ft_print_base(unsigned long n, char *base);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int num);
int	ft_print_uns(unsigned int uns);
int	ft_print_hex(unsigned int uns, int caps);

#endif