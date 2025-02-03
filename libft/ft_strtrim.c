/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:09:55 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/11 11:20:12 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_str(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str) - 1;
	while (end && ft_strchr(set, str[end]))
		end--;
	if (start > end)
		trimmed_str = empty_str();
	else
	{
		trimmed_str = malloc(end - start + 2);
		if (!trimmed_str)
			return (NULL);
		ft_memcpy(trimmed_str, (void *)str + start, end - start + 1);
		trimmed_str[end - start + 1] = '\0';
	}
	return (trimmed_str);
}
