/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:56:17 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/16 13:09:00 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Les
** champs content et content_size du nouveau maillon sont
** initialisés par copie des paramètres de la fonction. Si le paramètre
** content est nul, le champs content est initialisé à
** NULL et le champs content_size est initialisé à 0 quelque
** soit la valeur du paramètre content_size. Le champ next
** est initialisé à NULL. Si l’allocation échoue, la fonction renvoie
** NULL.
*/

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;
	t_list *cp;

	if ((res = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	res->content = NULL;
	res->content_size = 0;
	if (content)
	{
		cp = ft_memalloc(content_size);
		if (cp)
		{
			cp = ft_memcpy(cp, content, content_size);
			res->content = cp;
			res->content_size = content_size;
		}
	}
	res->next = NULL;
	return (res);
}
