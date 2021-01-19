/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:44:09 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/19 04:03:15 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_width_right(t_set *set, char *str)
{
	char		*tmp;
	
	if ((int)ft_strlen(str) > set->width)
			return (str);
	tmp = malloc(sizeof(char) * (set->width - ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, set->fill, set->width - ft_strlen(str));
	tmp[set->width - ft_strlen(str)] = '\0';
	return(ft_strjoin_free(tmp, str));
}

char		*ft_width_left(t_set *set, char *str)
{
	char		*tmp;
	
	if ((int)ft_strlen(str) > set->width)
		return (str);
	tmp = malloc(sizeof(char) * (set->width - ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, set->fill, set->width - ft_strlen(str));
	tmp[set->width - ft_strlen(str)] = '\0';
	return(ft_strjoin_free(str, tmp));
}

char		*ft_width_nb(t_set *set, char *str)
{

	char	*tmp;

	if (!set->width)
		return (str);
	if (set->width)
	{
		if (str[0] == '-' && set->fill == '0')
		{
			tmp = ft_strdup(str + 1);
			free(str);
			set->width--;
			if (set->justif == LEFT)
				str = ft_strjoin_free2("-", ft_width_left(set, tmp));
			else
				str = ft_strjoin_free2("-", ft_width_right(set, tmp));
			return (str);
		}
		tmp = ft_strdup(str);
		free(str);
		if (set->justif == LEFT)
			str = ft_width_left(set, tmp);
		else
				str = ft_width_right(set, tmp);
	}
	return (str);
}
