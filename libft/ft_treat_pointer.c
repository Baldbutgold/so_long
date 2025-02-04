/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:23:32 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/03 17:23:40 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_treat_pointer(unsigned long pointer)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (pointer > 9)
		count += ft_treat_pointer(pointer / 16);
	if (pointer != 0)
		count += ft_putchar(hex[pointer % 16]);
	return (count);
}
