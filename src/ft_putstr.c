/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:53:22 by divalent          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:50 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *counter)
{
	if (s == NULL)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, counter);
		s++;
	}
}

/*
int main(void)
{
	char s[] = "Ola";
	ft_putstr_fd(s, 1);
}
*/