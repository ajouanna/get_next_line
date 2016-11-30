/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 12:40:00 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  memmove()  function  copies n bytes from memory area src to memory
** area dest.  The memory areas may overlap: copying takes place as though
** the  bytes in src are first copied into a temporary array that does not
** overlap src or dest, and the bytes are then copied from  the  temporary
*/

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if (tmp)
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dest, tmp, n);
		free(tmp);
	}
	return (dest);
}
