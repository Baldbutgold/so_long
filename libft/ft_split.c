/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:34:06 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/01 11:34:10 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (s[i])
	{
		if (flag == 1 && s[i] != c)
		{
			flag = 0;
			count++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	ft_findlen(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static int	ft_strndup(char **arr, char const *s, size_t i, size_t len)
{
	arr[i] = malloc((len + 1) * sizeof(char));
	if (!arr[i])
		return (ft_free(arr, i), 0);
	ft_memcpy(arr[i], s, len + 1);
	arr[i][len] = 0;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	words_num;

	if (s == 0)
		return (0);
	words_num = ft_countwords(s, c);
	arr = malloc((words_num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words_num)
	{
		while (s[j] && s[j] == c)
			j++;
		j += ft_strndup(arr, s + j, i, ft_findlen(s + j, c));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
