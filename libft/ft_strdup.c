/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:13:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:37 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*s_cpy;

	str_len = ft_strlen(s);
	s_cpy = malloc(str_len + 1 * sizeof(char));
	if (!s_cpy)
		return (0);
	ft_memcpy(s_cpy, s, str_len + 1);
	return (s_cpy);
}
