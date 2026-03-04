/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:49:35 by divalent          #+#    #+#             */
/*   Updated: 2023/11/07 12:21:54 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	writ(char *s, long k, int *counter)
{
	while (k >= 0)
	{
		write(1, s + k, 1);
		k--;
		(*counter)++;
	}
}

void	ft_putnbr(long n, char *base, int *counter)
{
	int		k;
	int		temp;
	char	s[22];
	int		basel;

	basel = ft_strlen(base);
	k = 0;
	if (n <= 0)
	{
		if (n < 0)
			s[0] = '-';
		if (n == 0)
			s[0] = '0';
		ft_putchar(*s, counter);
	}
	while (n != 0)
	{
		if (n >= 0)
			temp = base[(n % basel)];
		else
			temp = base[((n % basel) * -1)];
		s[k++] = temp;
		n /= basel;
	}
	writ(s, (k - 1), counter);
}

/*
int main(void)
{
	int	n = 0;
	ft_putnbr_fd(n, 1);
}
*/