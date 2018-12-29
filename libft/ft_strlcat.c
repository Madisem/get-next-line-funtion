/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:10:09 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 01:15:23 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(dst);
	i = k;
	j = 0;
	if (i < dstsize)
	{
		while (src[j] && (i < dstsize - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	else if (k > dstsize)
		return (dstsize + ft_strlen(src));
	return (k + ft_strlen(src));
}
