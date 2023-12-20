/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fertorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:39:30 by fertorok          #+#    #+#             */
/*   Updated: 2023/11/09 13:21:22 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	src_index;
	size_t	dst_index;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	src_index = 0;
	dst_index = dst_len;
	if (!dst && size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	while (src[src_index] && dst_index + 1 < size)
	{
		dst[dst_index] = src[src_index];
		src_index++;
		dst_index++;
	}
	dst[dst_index] = '\0';
	return (dst_len + src_len);
}
