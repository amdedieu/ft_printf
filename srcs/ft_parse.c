/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:33:39 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/21 23:38:41 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_set		*ft_init_set(void)
{
	t_set *set;

	if (!(set = malloc(sizeof(t_set))))
		return (NULL);
	set->conv = 0;
	set->prec = -1;
	set->width = 0;
	set->justif = RIGHT;
	set->fill = ' ';
	return (set);
}

int			get_value(va_list args)
{
	int		value;

	value = va_arg(args, int);
	return (value);
}

void		ft_init_parse(const char *str, t_set *set, va_list args)
{
	while (ft_strchr(FLAGS, *str) || ft_isdigit(*str))
	{
		if (*str == '-')
			set->justif = LEFT;
		else if (*str == '.')
		{
			if (*(str + 1) == '*')
				set->prec = get_value(args);
			else
				set->prec = ft_atoi(str + 1);
			while (ft_isdigit(*(str + 1)) || (*(str + 1)) == '*')
				str++;
		}
		else if (*str == '0' && !set->width)
			set->fill = '0';
		else if (*str == '*' && !set->width)
			set->width = get_value(args);
		else if (!set->width)
			set->width = ft_atoi(str);
		str++;
	}
	set->conv = ft_define_type(*str);
}

void		ft_check_parse(t_set *set)
{
	if (set->width < 0)
	{
		set->width *= -1;
		set->justif = LEFT;
	}
	if (set->prec < 0)
		set->prec = -1;
	if (set->fill == '0' && set->justif == LEFT)
		set->fill = ' ';
}

t_set		*ft_parse(const char *str, va_list args)
{
	t_set	*set;

	if (*str != '%')
		return (NULL);
	if (!(set = ft_init_set()))
		return (NULL);
	str++;
	ft_init_parse(str, set, args);
	ft_check_parse(set);
	return (set);
}
