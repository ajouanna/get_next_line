/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:56:17 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/16 12:38:53 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f et crée une nouvelle liste “fraiche” avec malloc(3) ré-
** sultant des applications successives. Si une allocation échoue,
** la fonction renvoie NULL.
** NB : ma comprehension est que c est la fonction f qui fait un malloc
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *pt_next;
	t_list *result;

	if (!lst)
		return (NULL);
	if (lst->next)
	{
		pt_next = ft_lstmap(lst->next, f);
	}
	else
		pt_next = NULL;
	result = f(lst);
	if (result)
		result->next = pt_next;
	return (result);
}
