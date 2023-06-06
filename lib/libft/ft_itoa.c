/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:20:48 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/20 14:36:29 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	digits;

	digits = 0;
	if (n >= -9 && n <= 9)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		negative;
	int		i;

	negative = n < 0;
	if (n <= 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		if (n == 0)
			return (ft_strdup("0"));
		n *= -1;
	}
	result = ft_calloc(digits(n) + negative + 1, 1);
	if (result)
	{
		i = digits(n) + negative - 1;
		negative && (result[0] = '-');
		while (n)
		{
			result[i--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (result);
}
