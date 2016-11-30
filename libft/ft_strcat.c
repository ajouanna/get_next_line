/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 12:40:41 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strcat()  function  appends  the  src string to the dest string,
** overwriting the terminating null byte ('\0') at the end of dest,  and
** then  adds a terminating null byte.  The strings may not overlap, and
** the dest string must have enough space for the result.   If  dest  is
** not  large enough, program behavior is unpredictable
*/

char			*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}
