/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:05:36 by divalent          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:37 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	writ(char *s, int k, int *counter)
{
	ft_putstr("0x", counter);
	while (k >= 0)
	{
		write(1, s + k, 1);
		k--;
		(*counter)++;
	}
}

void	ft_puthexnbr(unsigned long n, char *base, int *counter)
{
	int		k;
	int		temp;
	char	s[22];
	int		basel;

	basel = ft_strlen(base);
	k = 0;
	if (n == 0)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	while (n != 0)
	{
		temp = base[(n % basel)];
		s[k++] = temp;
		n /= basel;
	}
	writ(s, (k - 1), counter);
}

/*
int main(void)
{
	int	n = 0;
	ft_puthexnbr(n, 1);
}
*/