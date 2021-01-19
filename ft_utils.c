/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:37:51 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/19 04:02:41 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		ft_ret(int ret, int nb_arg, ...)
{
	va_list		args;
	void		*tmp;
	int			i;

	i = 0;
	va_start(args, nb_arg);
	while(i < nb_arg)
	{
		tmp = va_arg(args, void *);
		ft_memdel(&tmp);
		i++;
	}
	va_end(args);
	return (ret);
}

int			ft_get_index(const char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
			return (i);
		str++;
		i++;
	}
	return (i);
}

int			ft_define_type(char c)
{
	int		i;
	char	*value;

	i = 0;
	value = ft_strdup(CONVSET);
	while (value[i] && value[i] != c)
		i++;
	if (value[i])
		return (ft_exit(i, 1, value));
	return (ft_exit(-1, 1, value));
}
