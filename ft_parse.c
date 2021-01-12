/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:37:53 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/12 16:50:58 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void			ft_fill_struct(t_set *stock)
{
	stock->conv = -1; // si 0 déja use
	stock->width = 0;  
	stock->prec = -1;
	stock->justif = RIGHT; 
	stock->fill = ' ';
}

static int			ft_get_conv(char c)
{
	int				i;
	char			*charset;

	
	i = -1;
	charset = ft_strdup(CONVSET);
	while (charset[++i])
	{
		if (charset[i] == c)
		{
			free(charset);
			return i;
		}
	}
	free(charset);
	return -1;
}

static void		ft_init_parse(const char *str, t_set *set, va_list arg)
{
	int			i;
	
	i = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			set->justif = LEFT;
		else if (str[i] =='.')
		{
			i++;
			if (str[i] == '0')
			{
				set->prec = 0;
				i--;
			} 
			else if (str[i] == '*')
				set->prec = va_arg(arg, int);
			else
				set->prec = ft_atoi(str + i);
			while (str[i] != '.' && str[i + 1] && ft_isdigit(str[i + 1]))
				i++;
		}
		else if (str[i] == '*')
			set->width = va_arg(arg, int);
		else if (str[i] == '0')
			set->fill = '0';
		else if (ft_isdigit(str[i]))
		{
			set->width = ft_atoi(str + i);
			while (str[i + 1] && ft_isdigit(str[i + 1]))
				i++;
		}
		else 
		{
			set->conv = ft_get_conv(str[i]);
			break ;
		}
	}
}

void 	ft_check_parse(t_set *set)
{
	if (set->width < 0)
		set->width *= -1;
	if (set->justif == LEFT && set->fill == '0')
			set->fill = ' ';
}

t_set			*ft_parse(const char *str, va_list arg)
{
	t_set			*set;

	set = malloc(sizeof(t_set) * 1);
	if (!set)
		return  NULL;
	ft_fill_struct(set);
	ft_init_parse(str, set, arg);
	return (set);
}
