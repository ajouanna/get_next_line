/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 19:21:07 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strstr() function finds the first occurrence of the substring needle in
** the string haystack.  The terminating null bytes ('\0') are not compared.
** The  strchr() function returns a pointer to the beginning of the located
** substring, or NULL if the substring is not found.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		l_needle;
	int		l_haystack;

	i = 0;
	l_needle = ft_strlen(needle);
	if (l_needle == 0)
		return ((char *)haystack);
	l_haystack = ft_strlen(haystack);
	if (l_haystack == 0)
		return (NULL);
	while (haystack[i])
	{
		if (ft_strncmp(haystack + i, needle, l_needle) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
