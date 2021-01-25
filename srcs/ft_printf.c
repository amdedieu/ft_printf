/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 04:44:44 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/25 17:46:29 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

const char			*ft_refresh_str(const char *str)
{
	int				next_arg;

	next_arg = ft_get_index(str);
	if (str[next_arg] == '%')
	{
		next_arg++;
		while (str[next_arg] && ft_define_type(str[next_arg]) == -1)
			next_arg++;
		next_arg++;
	}
	return (str + next_arg);
}

int					print_till_next_arg(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		if (str[i] == '%')
			break ;
	write(1, str, i);
	return (i);
}

int					ft_func_array(va_list args, t_set *set)
{
	int				(*function_ptr[9])(va_list, t_set *);

	if (!set)
		return (ft_ret(-1, 0));
	if (set->conv < 0)
		return (ft_ret(-1, 1, set));
	function_ptr[0] = &ft_char;
	function_ptr[1] = &ft_str;
	function_ptr[2] = &ft_address;
	function_ptr[3] = &ft_decimal;
	function_ptr[4] = &ft_integer;
	function_ptr[5] = &ft_unsigned;
	function_ptr[6] = &ft_hexadecimal;
	function_ptr[7] = &ft_hexadecimal_upper;
	function_ptr[8] = &ft_percent;
	return ((*function_ptr[set->conv])(args, set));
}

int					ft_print_str(const char *str, int i)
{
	char			*output;

	output = ft_substr(str, 0, ft_get_index(str));
	if (!output)
		return (ft_ret(-1, 0));
	ft_putstr_fd(output, 1);
	return (ft_ret(i + ft_strlen(output), 1, output));
}

int					ft_printf(const char *str, ...)
{
	va_list		args;
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if ((i = ft_print_str(str, i)) == -1)
			break ;
		if (str[ft_get_index(str)] == '%')
		{
			if ((ret = ft_func_array(args, ft_parse(str +
				ft_get_index(str), args))) == -1)
			{
				i = -1;
				break ;
			}
			i = i + ret;
		}
		str = ft_refresh_str(str);
	}
	va_end(args);
	return (ft_ret(i, 0));
}
