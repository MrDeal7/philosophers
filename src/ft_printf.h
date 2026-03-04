/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:59:06 by divalent          #+#    #+#             */
/*   Updated: 2023/11/07 13:59:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr(long n, char *base, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putchar(char c, int *counter);
size_t	ft_strlen(const char *str);
void	ft_puthexnbr(unsigned long n, char *base, int *counter);

#endif