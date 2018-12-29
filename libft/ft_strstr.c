/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:57:19 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/09 17:56:21 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] && s2[j])
		{
			i++;
			j++;
		}
		if (j == n)
			return ((char *)s1 + (i - j));
		else
			i = i - j;
		i++;
	}
	return (NULL);
}
