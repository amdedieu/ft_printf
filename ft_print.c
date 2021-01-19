/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:17:25 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/19 03:59:18 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int			ft_char_pf(va_list args, t_set *set)
{
	char	c;
	char	*tmp;

	c = va_arg(args, int);
	tmp = ft_calloc(1, 1);
	if (!tmp)
		return (ft_ret(-1, 1, set));
	if (set->width)
	{
		set->width--;
		if (set->justif == LEFT)
		{
			tmp = ft_width_left(set, tmp);
			ft_putchar_fd(c, 1);
			ft_putstr_fd(tmp, 1);
		}
		else
		{
			tmp = ft_width_right(set, tmp);
			ft_putstr_fd(tmp, 1);
			ft_putchar_fd(c, 1);
		}
	}
	else 
		ft_putchar_fd(c, 1);
	return (ft_ret(set->width + 1, 2, tmp, set));
}

int			ft_str_pf(va_list args, t_set *set)
{ 
	char	*str;
	char	*tmp;

	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else 
		str = ft_strdup(str);
	if (set->prec != -1 && set->prec < (int)ft_strlen(str))
		tmp = ft_substr(str, 0, set->prec);
	else if (!set->prec)
		tmp = ft_strdup("");
	else
		tmp = ft_strdup(str);
	if (set->width)
	{
		if (set->justif == LEFT)
			tmp = ft_width_left(set, tmp);
		else
			tmp = ft_width_right(set, tmp);
	}
	ft_putstr_fd(tmp, 1);
	return (ft_ret(ft_strlen(tmp), 3, str, tmp, set));
}

int				ft_address_pf(va_list args, t_set *set)
{
	void	*ptr;
	char	*result;

	ptr = va_arg(args, void *);
	if (!set->prec)
		result = ft_strdup("");
	else if (!ptr)
		result = ft_strdup("0");
	else
		result = ft_itoa_address((unsigned long long int)ptr);
	if (set->prec != -1 && set->prec)
	{
		result = ft_prec(result, set);
		set->fill = ' ';
	}
	result = ft_strjoin_free2("0x", result);
	result = ft_width_nb(set, result);
	ft_putstr_fd(result, 1);
	return (ft_ret(ft_strlen(result), 2, result, set));
} 

int			ft_decimal_pf(va_list args, t_set *set)
{
	int		i;
	char	*nb;
	
	i = va_arg(args, int);
	nb = ft_itoa(i);
	 if (!i && !set->prec)
		nb = ft_strdup("");
	else if (!i)
		nb = ft_itoa(0);
	if (set->prec != -1)
	{
		nb = ft_prec_nb(nb, set);
		set->fill = ' ';              // possiblement a remettre -- regarder comportement avec .014
	}
	nb = ft_width_nb(set, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, set));
}

int				ft_integer_pf(va_list args, t_set *set)
{
	int		i;
	char	*nb;

	if ((i = va_arg(args, int)))
		nb = ft_itoa(i);
	else if (!i && !set->prec)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (set->prec != -1)
	{
		nb = ft_prec_nb(nb, set);
		set->fill = ' ';
	}
	nb = ft_width_nb(set, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, set));
}
