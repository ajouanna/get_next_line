/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:57:01 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 19:11:56 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre en précisant son index pour créer une nouvelle chaine
** “fraiche” (avec malloc(3)) résultant des applications successives
** de f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	if ((res = malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		i = 0;
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
