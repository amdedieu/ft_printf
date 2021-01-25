/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 04:45:02 by amdedieu          #+#    #+#             */
/*   Updated: 2021/01/22 03:16:04 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_prec(char *str, t_set *settings)
{
	char	*tmp;

	if ((int)ft_strlen(str) >= settings->prec)
		return (str);
	tmp = malloc(sizeof(char) * (settings->prec - ft_strlen(str)));
	if (!str)
		return (NULL);
	ft_memset(tmp, '0', settings->prec - ft_strlen(str));
	tmp[settings->prec - ft_strlen(str)] = '\0';
	return (ft_strjoin_free(tmp, str));
}

char		*ft_prec_nb(char *str, t_set *settings)
{
	char	*tmp;

	tmp = NULL;
	if (settings->prec != -1)
	{
		if (str[0] == '-')
		{
			tmp = ft_strdup(str + 1);
			free(str);
			str = ft_strjoin_free2("-", ft_prec(tmp, settings));
		}
		else
			str = ft_prec(str, settings);
	}
	return (str);
}
