/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 19:28:08 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans les espaces blancs au debut et à la
** fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
** blancs au début ou à la fin, la fonction renvoie une copie de
** s. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strtrim(char const *s)
{
	size_t len_s;
	size_t prem;
	size_t der;

	if (s == NULL)
	{
		return (NULL);
	}
	len_s = ft_strlen(s);
	prem = 0;
	while (s[prem] && (s[prem] == ' ' || s[prem] == '\t' || s[prem] == '\n'))
	{
		prem++;
	}
	der = len_s - 1;
	while (s[der] && (der >= prem) &&
			(s[der] == ' ' || s[der] == '\t' || s[der] == '\n'))
	{
		der--;
	}
	return (ft_strsub(s, prem, der - prem + 1));
}
