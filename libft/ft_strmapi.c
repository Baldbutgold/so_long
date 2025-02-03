/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:40:45 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/14 20:43:53 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_cpy;

	if (!s)
		return (NULL);
	s_cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s_cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_cpy[i] = f(i, s[i]);
		i++;
	}
	s_cpy[i] = 0;
	return (s_cpy);
}
