/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 18:52:59 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string src to string dst.  If the
** character c (as converted to an unsigned char) occurs in the string src,
** the copy stops and a pointer to the byte after the copy of c in the string
** dst is returned.  Otherwise, n bytes are copied, and a NULL pointer is
** returned.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_src;
	unsigned char		*uc_dest;
	unsigned char		uc;

	uc_src = src;
	uc_dest = dest;
	uc = c;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		if (uc_src[i] == uc)
			return (uc_dest + i + 1);
		i++;
	}
	return (NULL);
}
