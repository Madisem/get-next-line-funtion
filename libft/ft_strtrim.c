/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:55:09 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 02:31:18 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*tmp;
	int		size;
	int		k;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s) - 1;
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (size >= 0 && (s[size] == ' ' || s[size] == '\t' || s[size] == '\n'))
		size--;
	if (size < i)
		size = i;
	tmp = ft_strnew((size + 1) - i);
	if (!tmp)
		return (NULL);
	while (i <= size)
		tmp[k++] = s[i++];
	return (tmp);
}
