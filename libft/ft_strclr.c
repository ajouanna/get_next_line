/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/14 19:08:21 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assigne la valeur ’\0’ à tous les caractères de la chaine passée
** en paramètre
*/

void	ft_strclr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			s[i] = 0;
			i++;
		}
	}
}
