/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:10 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/18 16:20:56 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_check_flag(char c);
static int	ft_check_format(char c, va_list *args, char flag);

int	ft_printf(const char *str, ...)
{
	int		count;
	char	flag;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && (str + 1))
		{
			flag = ft_check_flag(*(str + 1));
			if (flag == 0)
				str++;
			else
				str = str + 2;
			count += ft_check_format(*(str), &args, flag);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}

static char	ft_check_flag(char c)
{
	if (c == '#' || c == ' ' || c == '+')
		return (c);
	return (0);
}

static int	ft_check_format(char c, va_list *args, char flag)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*args, int), flag));
	if (c == 'u')
		return (ft_print_uns(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), flag, 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), flag, 1));
	if (c == '%')
		return (ft_print_chr('%'));
	return (0);
}
