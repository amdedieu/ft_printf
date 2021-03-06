/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 04:45:18 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/25 17:45:49 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int					ft_unsigned(va_list args, t_set *set)
{
	unsigned int	i;
	char			*nb;

	i = va_arg(args, unsigned int);
	nb = ft_itoa_unsigned(i);
	if (!i && !set->prec)
		nb = ft_strdup("");
	else if (!i)
		nb = ft_itoa(0);
	if (set->prec != -1)
	{
		nb = ft_prec(nb, set);
		set->fill = ' ';
	}
	nb = ft_width_nb(set, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, set));
}

int					ft_hexadecimal(va_list args, t_set *set)
{
	int				i;
	char			*nb;

	if ((i = va_arg(args, int)))
		nb = ft_itoa_base(i, HEXA);
	else if (!i && !set->prec)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (set->prec != -1)
	{
		nb = ft_prec(nb, set);
		set->fill = ' ';
	}
	if (set->width)
	{
		if (set->justif == LEFT)
			nb = ft_width_left(set, nb);
		else
			nb = ft_width_right(set, nb);
	}
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, set));
}

int					ft_hexadecimal_upper(va_list args, t_set *set)
{
	int				i;
	char			*nb;

	if ((i = va_arg(args, int)))
		nb = ft_str_toupper(ft_itoa_base(i, HEXA));
	else if (!i && !set->prec)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (set->prec != -1)
	{
		nb = ft_prec(nb, set);
		set->fill = ' ';
	}
	if (set->width)
	{
		if (set->justif == LEFT)
			nb = ft_width_left(set, nb);
		else
			nb = ft_width_right(set, nb);
	}
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, set));
}

int					ft_percent(va_list args, t_set *set)
{
	char			*tmp;

	(void)args;
	if (!(tmp = ft_strdup("%")))
		return (ft_ret(-1, 1, set));
	if (set->width)
	{
		if (set->justif == LEFT)
			tmp = ft_width_left(set, tmp);
		else
			tmp = ft_width_right(set, tmp);
	}
	ft_putstr_fd(tmp, 1);
	return (ft_ret(ft_strlen(tmp), 2, tmp, set));
}
