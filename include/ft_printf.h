/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:38:09 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/12 00:27:26 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define LEFT 1
# define RIGHT 0
# define CONVSET "cspdiuxX%"

typedef	struct		s_set
{
	int			conv;
	int			width;
	int			prec;
	int			justif;
	char		fill;

} 					t_set;

t_set				*ft_parse(const char *str, va_list arg);
int		print_til_next_arg(const char  *str);
int		ft_printf(const char *str, ...);
void 	ft_check_parse(t_set *set);

#endif
