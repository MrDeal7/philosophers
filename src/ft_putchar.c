/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:51 by divalent          #+#    #+#             */
/*   Updated: 2023/11/06 15:35:32 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

/*
int	main(void)
{
	char c = 'O';
	ft_putchar_fd(c, 0);
}
*/