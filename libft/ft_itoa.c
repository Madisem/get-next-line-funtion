/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:44:32 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/08 18:55:40 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		size;
	long	na;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		size++;
	}
	na = num;
	while (na /= 10)
		size++;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	str[--size] = num % 10 + '0';
	while (num /= 10)
		str[--size] = (num % 10) + '0';
	if (str[0] == '\0')
		str[0] = '-';
	return (str);
}
