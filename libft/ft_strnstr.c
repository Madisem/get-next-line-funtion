/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:39:33 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 01:05:38 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	if (s2[i] == '\0' || s2 == NULL)
		return ((char *)s1);
	n = ft_strlen(s2);
	while (i < len && s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] && s2[j] && i < len)
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
