/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:42:16 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/19 03:35:26 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_prec(char *str, t_set *set)
{
	char	*tmp;

	if ((int)ft_strlen(str) >= set->prec)
		return (str);
	tmp = malloc(sizeof(char) * (set->prec - ft_strlen(str)));
	if (!str)
		return (NULL);
	ft_memset(tmp, '0', set->prec - ft_strlen(str));
	tmp[set->prec - ft_strlen(str)] = '\0';
	return (ft_strjoin_free(tmp, str));
}

char		*ft_prec_nb(char *str, t_set *set)
{
	char	*tmp;
	
	tmp = NULL;
	if (set->prec != -1)
	{
		if (str[0] == '-')
		{
			tmp = ft_strdup(str + 1);
			free(str);
			str = ft_strjoin_free2("-", ft_prec(tmp, set));
		}
		else
			str = ft_prec(str, set);
	}
	return (str);
}
