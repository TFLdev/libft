/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fertorok <fertorok@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:36:48 by fertorok          #+#    #+#             */
/*   Updated: 2023/11/09 15:29:56 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr_in_str(const char *s, char c)
{
	int		i;
	size_t	countsubstr;

	i = 0;
	countsubstr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			countsubstr++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (countsubstr);
}

static void	*arrays_freedom(char **ptr, int m)
{
	while (m > 0)
	{
		m--;
		free (ptr[m]);
	}
	free (ptr);
	return (NULL);
}

static char	**auxiliary_strsplit(char **aux_strsplit, char *s, \
		char c, size_t aux_countsubstr)
{
	int		j;
	int		x;
	size_t	len;

	j = 0;
	x = 0;
	while (j < (int)aux_countsubstr)
	{
		len = 0;
		while (s[x] == c)
			x++;
		while (s[x + len] != '\0' && s[x + len] != c)
			len++;
		aux_strsplit[j] = ft_substr(&s[x], 0, len);
		if (!aux_strsplit[j])
			return (arrays_freedom(aux_strsplit, j));
		x += len;
		j++;
	}
	aux_strsplit[j] = NULL;
	return (aux_strsplit);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	size_t	countsubstr;
	char	**strsplit;
	char	**result;

	j = 0;
	countsubstr = count_substr_in_str(s, c);
	strsplit = (char **)malloc((countsubstr + 1) * sizeof(char *));
	if (!strsplit)
		return (NULL);
	result = auxiliary_strsplit(strsplit, (char *)s, c, countsubstr);
	return (result);
}
