/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:55:43 by muhaoz            #+#    #+#             */
/*   Updated: 2025/02/28 23:49:45 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char a)
{
	return (a == 'c' || a == 'd' || a == 'i' || a == 'u' || a == '%' || a == 's'
		|| a == 'x' || a == 'X' || a == 'p' || a == '\0');
}

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

static int	ft_format(va_list ag, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(ag, int)));
	else if (a == 'd' || a == 'i')
		return (ft_int(va_arg(ag, int)));
	else if (a == 'u')
		return (ft_unsigned(va_arg(ag, unsigned int)));
	else if (a == 's')
		return (ft_string(va_arg(ag, char *)));
	else if (a == '%')
		return (ft_putchar(a));
	else if (a == 'x' || a == 'X')
		return (ft_hex(va_arg(ag, unsigned int), a));
	else if (a == 'p')
		return (ft_point(va_arg(ag, unsigned long), 1));
	else if (a == '\0')
		return (-1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ag;
	int		emp;
	int		i;
	int		lenght;

	if (str == NULL)
		return (-1);
	va_start(ag, str);
	lenght = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
		{
			emp = ft_format(ag, str[++i]);
			if (emp == -1)
				return (va_end(ag), -1);
			lenght += emp - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (va_end(ag), -1);
		lenght++;
	}
	return (va_end(ag), lenght);
}
