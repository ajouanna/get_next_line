/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:56:17 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/16 12:38:07 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et
** libère la mémoire du contenu de ce maillon avec la fonction
** del passée en paramètre puis libère la mémoire du maillon
** en lui même avec free(3). La mémoire du champ next ne
** doit en aucun cas être libérée. Pour terminer, le pointeur sur
** le maillon maintenant libéré doit être mis à NULL (de manière
** similaire à la fonction ft_memdel de la partie obligatoire).
*/

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *pt;

	if (alst)
	{
		pt = *alst;
		del(pt->content, pt->content_size);
		free(pt);
		*alst = NULL;
	}
}
