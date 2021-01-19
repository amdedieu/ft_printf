/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:38:09 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/19 05:47:37 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> // temp 
# include "../libft/libft.h"

# define LEFT 1
# define RIGHT 0
# define CONVSET "cspdiuxX%"
# define HEXA "0123456789abcdef"

typedef	struct		s_set
{
	int			conv;
	int			width;
	int			prec;
	int			justif;
	char		fill;

} 					t_set;

int			ft_hexadecimal_upper_pf(va_list arg, t_set *set);
int			ft_hexadecimal_pf(va_list arg, t_set *set);
int			ft_integer_pf(va_list args, t_set *set);
t_set		*ft_parse(const char *str, va_list arg);
int			ft_address_pf(va_list args, t_set *set);
int			ft_unsigned_pf(va_list arg, t_set *set);
int			ft_decimal_pf(va_list args, t_set *set);
char		*ft_width_right(t_set *set, char *str);
int			ft_percent_pf(va_list arg, t_set *set);
char		*ft_width_right(t_set *set, char *str);
char		*ft_width_left(t_set *set, char *str);
int			print_til_next_arg(const char  *str);
int			ft_char_pf(va_list args, t_set *set);
int			ft_str_pf(va_list args, t_set *set);
char		*ft_width_nb(t_set *set, char *str);
char		*ft_prec_nb(char *str, t_set *set);
int			ft_ret(int ret, int nb_arg, ...);
int			ft_printf(const char *str, ...);
char		*ft_prec(char *str, t_set *set);
int			ft_get_index(const char *str);
void 		ft_check_parse(t_set *set);
int			ft_define_type(char c);


#endif
