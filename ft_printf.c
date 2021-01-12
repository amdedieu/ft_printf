/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:16:24 by ameliadedie       #+#    #+#             */
/*   Updated: 2021/01/12 16:47:09 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		print_til_next_arg(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '%')
			break;
	write(1, str, i);
	return i;
}

static void		print_set(t_set  *set)
{
	printf("conv : %d\n", set->conv);
	printf("width : %d\n", set->width);
	printf("prec : %d\n", set->prec);
	printf("justif : %d\n", set->justif);
	printf("fill: %c\n", set->fill);
}

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	t_set *set;
	int		ret;
	
	va_start(arg, str);
	ret = print_til_next_arg(str);
	str += ret;
	set = ft_parse(str, arg);
	ft_check_parse(set);
	print_set(set);
	va_end(arg);
	return (0);
}

int		main(void)
{
	ft_printf("mine %.014d", 12345);
	printf("true %.014d", 12345);
	return 0;
}
