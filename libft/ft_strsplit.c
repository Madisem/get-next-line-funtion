/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 01:25:59 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/10 02:17:23 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_create_arr(const char *s, char c)
{
	char	**arr;
	int		i;
	int		k;
	int		count_w;

	k = 0;
	i = 0;
	arr = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		count_w = 0;
		while (s[i] != c && s[i])
		{
			count_w++;
			i++;
		}
		while (s[i] == c)
			i++;
		arr[k++] = ft_strnew(count_w);
	}
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	arr = ft_create_arr(s, c);
	if (!arr)
		return (NULL);
	while (s[j] == c)
		j++;
	while (s[j])
	{
		k = 0;
		while (s[j] != c && s[j])
			arr[i][k++] = s[j++];
		while (s[j] == c)
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
