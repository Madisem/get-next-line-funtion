/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:31:43 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/07 18:54:46 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstr_c(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	int		count;

	i = 0;
	count = 0;
	n = ft_strlen(s2);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (j == n)
			count++;
		i++;
	}
	return (count);
}
