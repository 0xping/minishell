/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:11:24 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/23 12:55:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		if (dst || src)
		{
			while (len)
			{
				((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len
					- 1];
				len--;
			}
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
