/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:04:19 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/07 12:03:09 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** creer un element de liste chainee contenant fd
*/

t_list		*create_elem(const int fd)
{
	t_list *elem;
	t_sbuf *psbuf;

	psbuf = malloc(sizeof(t_sbuf));
	if (psbuf == NULL)
		return (NULL);
	psbuf->fd = fd;
	psbuf->pos_in_buf = 0;
	elem = ft_lstnew(psbuf, sizeof(t_sbuf));
	if (elem == NULL)
		return (NULL);
	return (elem);
}

/*
** si la list chainee est vide, creer le 1er element
** sinon chercher l'element correspondant a fd
** s'il n'existe pas, le creer
*/

t_sbuf		*get_sbuf(const int fd)
{
	static t_list	*plist = NULL;
	t_list			*pt;
	t_sbuf			*psbuf;

	if (plist == NULL)
	{
		plist = create_elem(fd);
		if (plist == NULL)
			return (NULL);
		return (plist->content);
	}
	pt = plist;
	while (pt)
	{
		psbuf = pt->content;
		if (psbuf->fd == fd)
			return (psbuf);
		pt = pt->next;
	}
	pt = create_elem(fd);
	if (pt == NULL)
		return (NULL);
	psbuf = pt->content;
	ft_lstadd(&plist, pt);
	return (psbuf);
}

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

/*
** cherche un /n dans buf et copie la sous-chaine de buf
** dans line
** Egalement, positionne pos_in_buf apres \n
** Renvoie 1 si \n a ete trouve, 0 si non, -1 en cas d'erreur
*/

int			join(char **line, t_sbuf *sbuf)
{
	char	*pos_nl;
	char	*joined;
	int		len;

	if ((pos_nl = ft_strchr(sbuf->buf + sbuf->pos_in_buf, '\n')) != NULL)
	{
		len = pos_nl - (sbuf->buf + sbuf->pos_in_buf);
		joined = ft_strnjoin(*line, sbuf->buf + sbuf->pos_in_buf, len);
		if (joined == NULL)
			return (-1);
		sbuf->pos_in_buf += len + 1;
		if (sbuf->pos_in_buf >= (int)ft_strlen(sbuf->buf))
			sbuf->pos_in_buf = 0;
		free(*line);
		*line = joined;
		return (1);
	}
	joined = ft_strjoin(*line, sbuf->buf + sbuf->pos_in_buf);
	if (joined == NULL)
		return (-1);
	sbuf->pos_in_buf = 0;
	free(*line);
	*line = joined;
	return (0);
}

/*
** le principe de fonctionnement : je lis le fichier par blocs de taille
** BUFF_SIZE. Dans le buffer lu, je vais jusqu'au retour chariot. S'il n'y en a
** pas, je lis en boucle un nouveau bloc.
** Entre 2 appels a get_next_line, les infos sont stockees dans un t_sbuf
*/

int			get_next_line(const int fd, char **line)
{
	t_sbuf	*sbuf;
	int		res;
	int		resjoin;

	if ((sbuf = get_sbuf(fd)) == NULL)
		return (-1);
	if (sbuf->pos_in_buf == 0)
	{
		if ((res = read(fd, sbuf->buf, BUFF_SIZE)) == -1 || res == 0)
			return (res);
		sbuf->buf[res] = 0;
	}
	if ((*line = ft_memalloc(sizeof(char) * (1))) == NULL)
		return (-1);
	if ((res = join(line, sbuf)))
		return (res);
	while ((res = read(fd, sbuf->buf, BUFF_SIZE)) > 0)
	{
		sbuf->buf[res] = 0;
		if ((resjoin = join(line, sbuf)) != 0)
			return (resjoin);
	}
	return ((res == 0) ? 1 : res);
}
