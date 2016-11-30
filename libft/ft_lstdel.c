/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:56:17 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/15 11:37:13 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et
** libère la mémoire de ce maillon et celle de tous ses successeurs
** l’un après l’autre avec del et free(3). Pour terminer,
** le pointeur sur le premier maillon maintenant libéré doit être
** mis à NULL (de manière similaire à la fonction ft_memdel de
** la partie obligatoire).
*/

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *pt;

	if (alst)
	{
		pt = *alst;
		if (pt->next)
		{
			ft_lstdel(&(pt->next), del);
		}
		del(pt->content, pt->content_size);
		free(pt);
		*alst = NULL;
	}
}
