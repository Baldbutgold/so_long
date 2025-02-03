/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:33:18 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/17 11:33:19 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_string_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_handle_num(int n, char *num, int len)
{
	int	is_negative;
	int	str_index;

	str_index = len - 1;
	is_negative = 0;
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	while (n)
	{
		num[str_index--] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_negative == 1)
		num[0] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*int_str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = calc_string_len(n);
	int_str = (char *)malloc((len + 1) * sizeof(char));
	if (!int_str)
		return (NULL);
	if (n == 0)
		int_str[0] = '0';
	else
		ft_handle_num(n, int_str, len);
	int_str[len] = '\0';
	return (int_str);
}
