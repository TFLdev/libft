/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fertorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:54 by fertorok          #+#    #+#             */
/*   Updated: 2023/10/03 17:04:03 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (last != NULL && *last == (char)c)
		return ((char *)last);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
