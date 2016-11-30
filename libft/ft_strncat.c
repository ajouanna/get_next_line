/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 13:03:45 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  strcat()  function  appends  the  src string to the dest string,
** overwriting the terminating null byte ('\0') at the end of dest,  and
** then  adds a terminating null byte.  The strings may not overlap, and
** the dest string must have enough space for the result.   If  dest  is
** not  large enough, program behavior is unpredictable
** The strncat() function is similar, except that
**  *  it will use at most n bytes from src; and
**  *  src does not need to be null-terminated if it  contains  n  or  more
**     bytes.
*/

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
