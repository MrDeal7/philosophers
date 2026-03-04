/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:16 by divalent          #+#    #+#             */
/*   Updated: 2023/11/06 13:46:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

/*
int main(void)
{
	char str[] = "abc 3";
	printf("%d", ft_strlen(str));
}
*/