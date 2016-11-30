/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 18:37:01 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function finds the first occurrence of the substring needle in
** the string haystack, where not more than len
** characters are searched.  Characters that appear after a `\0' character
** are not searched.
** The  function returns a pointer to the beginning of the located substring, or
** NULL if the substring is not found.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		l_needle;
	int		l_haystack;

	l_needle = ft_strlen(needle);
	if (l_needle == 0)
		return ((char *)haystack);
	l_haystack = ft_strlen(haystack);
	if (l_haystack == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && ((i + l_needle) <= len))
	{
		if (ft_strncmp(haystack + i, needle, l_needle) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
