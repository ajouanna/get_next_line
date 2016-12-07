/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:37:14 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/07 13:37:59 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère
** “fraiche” terminée par un ’\0’ résultant de la concaténation
** de s1 et s2, sur une longueur max de size
** Si l’allocation echoue, la fonction renvoie NULL.
*/

char		*ft_strnjoin(char const *s1, char const *s2, size_t size)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] && i < size)
	{
		res[i + j] = s2[i];
		i++;
	}
	res[i + j] = 0;
	return (res);
}
