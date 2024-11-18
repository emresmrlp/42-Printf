/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:27:11 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/18 15:58:07 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num, char flag)
{
	int	counter;

	counter = 0;
	if (num == -2147483648)
		return (ft_print_str("-2147483648"));
	if (flag != 0 && num > 0)
	{
		if (flag == ' ')
			counter += ft_print_chr(' ');
		if (flag == '+')
			counter += ft_print_chr('+');
	}
	if (num < 0)
	{
		counter += ft_print_chr('-');
		num *= -1;
	}
	if (num < 10)
		counter += ft_print_chr(num + '0');
	else
	{
		ft_print_int(num / 10, flag);
		ft_print_int(num % 10, flag);
	}
	return (counter);
}
