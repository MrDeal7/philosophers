/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:01:42 by divalent          #+#    #+#             */
/*   Updated: 2023/11/07 14:07:17 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ff(va_list va, const char *str, int *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_puthexnbr(va_arg(va, unsigned long), "0123456789abcdef", counter);
	else if (*str == 'd')
		ft_putnbr(va_arg(va, int), "0123456789", counter);
	else if (*str == 'i')
		ft_putnbr(va_arg(va, int), "0123456789", counter);
	else if (*str == 'u')
		ft_putnbr(va_arg(va, unsigned int), "0123456789", counter);
	else if (*str == 'x')
		ft_putnbr(va_arg(va, unsigned int), "0123456789abcdef", counter);
	else if (*str == 'X')
		ft_putnbr(va_arg(va, unsigned int), "0123456789ABCDEF", counter);
	else if (*str == '%')
		ft_putchar('%', counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		va;
	int			counter;

	counter = 0;
	if (str == NULL)
		return (-1);
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
			ff(va, ++str, &counter);
		else
			ft_putchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}

/*
int main(void)
{
	printf("%d\n", ft_printf("%s"));
	printf("%s");
}
*/