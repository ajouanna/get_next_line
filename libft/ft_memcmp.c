/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 14:44:51 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  memcmp()  function compares the first n bytes (each interpreted as
** unsigned char) of the memory areas s1 and s2.
** The memcmp() function returns  an  integer  less  than,  equal  to,  or
** greater than zero if the first n bytes of s1 is found, respectively, to
** be less than, to match, or be greater than the first n bytes of s2.
** For a nonzero return value, the sign is determined by the sign  of  the
** difference  between  the  first  pair of bytes (interpreted as unsigned
** char) that differ in s1 and s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	uc_s1 = s1;
	uc_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (uc_s1[i] != uc_s2[i])
			return ((int)(uc_s1[i] - uc_s2[i]));
		i++;
	}
	return (0);
}
