/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:14:30 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/03 11:45:32 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_print_char(int c);
int		find_format(va_list ptr, char format);
int		ft_print_str(char *s);
int		ft_print_ptr(unsigned long int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_hexadecimal(unsigned int n, char format);
int		ft_printf(const char *str, ...);

#endif