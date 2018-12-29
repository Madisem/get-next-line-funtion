/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 01:28:02 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/11 18:08:30 by maseidua         ###   ########.fr       */
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
		while (s[i] == c && s[i])
			i++;
		arr[k++] = ft_strnew(count_w);
	}
	return (arr);
}

t_list			*ft_lststrsplit(char const *s, char c)
{
	char	**arr;
	t_list	*temp;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	arr = ft_create_arr(s, c);
	while (s[j] == c)
		j++;
	while (s[j])
	{
		++i;
		k = 0;
		temp = temp->next;
		while (s[j] != c && s[j] != '\0')
			arr[i][k++] = s[j++];
		while (s[j] == c)
			j++;
		temp = ft_lstnew(arr[i], ft_strlen(arr[i]));
	}
	arr[i] = 0;
	return (temp);
}
