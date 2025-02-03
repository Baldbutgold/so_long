/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:04:54 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/10 22:04:55 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total_size;

	total_size = nmemb * size;
	s = malloc(total_size);
	if (!s)
		return (NULL);
	ft_bzero(s, total_size);
	return (s);
}
