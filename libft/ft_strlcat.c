/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 18:18:03 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends src to string dst of size size (unlike strncat, size is the
** full size of dst, not space left).  At most size-1 characters
** will be copied.  Always NUL terminates (unless size <= strlen(dst)).
** Returns strlen(src) + MIN(size, strlen(initial dst)).
** If retval >= size, truncation occurred.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dest_len;
	size_t i;

	dest_len = 0;
	while (dst[dest_len])
		dest_len++;
	i = 0;
	while (((i + dest_len + 1) < size) && src[i] != '\0')
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (dest_len < size)
		dst[dest_len + i] = '\0';
	return (((dest_len < size) ? dest_len : size) + ft_strlen(src));
}
