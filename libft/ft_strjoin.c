/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:13:37 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 02:19:40 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!tmp)
		return (NULL);
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[++j])
		tmp[i++] = s2[j];
	return (tmp);
}
