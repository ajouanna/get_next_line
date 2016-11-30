/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 12:50:13 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  strrchr() function returns a pointer to the last occurrence of the
** character c in the string s.
** The  strrchr() function returns a pointer to the matched character
** or NULL if the character is not found.  The terminating null byte is
** considered part of the string, so that if c is specified as '\0', these
** functions return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		last_pos;

	i = 0;
	last_pos = -1;
	while (s[i])
	{
		if (s[i] == c)
			last_pos = i;
		i++;
	}
	if (last_pos >= 0)
		return ((char *)(s + last_pos));
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}
