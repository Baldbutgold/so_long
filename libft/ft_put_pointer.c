/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:36:13 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/04 10:36:13 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_pointer(unsigned long pointer)
{
	int	count;

	if (!pointer)
		return (ft_putstr("(nil)"));
	count = 2;
	ft_putstr("0x");
	count += ft_treat_pointer(pointer);
	return (count);
}
