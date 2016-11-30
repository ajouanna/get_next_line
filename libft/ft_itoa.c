/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:57:15 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/16 12:41:27 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** add char c at beginning of string str
** allocates needed memory and releases memory used by str
*/

static char	*prependchar(char c, char *str)
{
	char	*res;
	int		len;

	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (res == NULL)
		return (NULL);
	res[0] = c;
	ft_strcpy(res + 1, str);
	free(str);
	return (res);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	char			*res;

	if ((res = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	res[0] = 0;
	if (n == 0)
	{
		res = prependchar('0', res);
		return (res);
	}
	nb = n;
	if (n < 0)
	{
		nb = -n;
	}
	while (nb)
	{
		res = prependchar(nb % 10 + '0', res);
		nb /= 10;
	}
	if (n < 0)
		res = prependchar('-', res);
	return (res);
}
