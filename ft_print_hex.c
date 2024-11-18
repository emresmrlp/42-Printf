/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:32 by ysumeral          #+#    #+#             */
/*   Updated: 2024/11/18 16:04:35 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int uns, char flag, int caps)
{
	char	*base;
	int		counter;

	counter = 0;
	if (flag == '#')
	{
		if (caps == 0)
			counter += ft_print_str("0x");
		else
			counter += ft_print_str("0X");
	}
	if (caps == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	counter += ft_print_base(uns, base);
	return (counter);
}
