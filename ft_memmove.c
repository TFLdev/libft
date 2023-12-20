/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fertorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:01:15 by fertorok          #+#    #+#             */
/*   Updated: 2023/10/02 11:54:58 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned const char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
		{
			*(ptr_dst++) = *(ptr_src++);
		}
	}
	else
	{
		ptr_dst += len;
		ptr_src += len;
		while (len--)
		{
			*(--ptr_dst) = *(--ptr_src);
		}
	}
	return (dst);
}
