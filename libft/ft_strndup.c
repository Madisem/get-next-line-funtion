/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:32:34 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 02:44:17 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strnew(n);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, s1, n);
	return (tmp);
}
