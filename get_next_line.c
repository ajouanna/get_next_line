/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:04:19 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/07 17:31:48 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** creer un element de liste chainee contenant fd
** Remarque : ne pas oublier de liberer psbuf car ft_lstnew fait une copie
** profonde
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
	free(psbuf);
	if (elem == NULL)
		return (NULL);
	return (elem);
}

/*
** si la list chainee est vide, creer le 1er element
** sinon chercher l'element correspondant a fd
** s'il n'existe pas, le creer
*/

t_sbuf		*get_sbuf(const int fd, t_list **pplist)
{
	t_list			*pt;
	t_sbuf			*psbuf;

	if (*pplist == NULL)
	{
		*pplist = create_elem(fd);
		if (*pplist == NULL)
			return (NULL);
		return ((*pplist)->content);
	}
	pt = *pplist;
	while (pt)
	{
		psbuf = pt->content;
		if (psbuf->fd == fd)
			return (psbuf);
		pt = pt->next;
	}
	if ((pt = create_elem(fd)) == NULL)
		return (NULL);
	psbuf = pt->content;
	ft_lstadd(pplist, pt);
	return (psbuf);
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
** Lit dans un fichier en terminant la chaine lue par un 0.
** En cas d'erreur ou de fin de fichier, repositionne le buffer a 0
** pour le cas ou on rappellerai get_next_line avec un fd deja utilise
** Renvoit le code d'erreur de read
*/

int			read_in_elem(t_sbuf *sbuf)
{
	int			res;

	res = read(sbuf->fd, sbuf->buf, BUFF_SIZE);
	if (res > 0)
	{
		sbuf->buf[res] = 0;
		return (res);
	}
	sbuf->pos_in_buf = 0;
	return (res);
}

/*
** le principe de fonctionnement : je lis le fichier par blocs de taille
** BUFF_SIZE. Dans le buffer lu, je vais jusqu'au retour chariot. S'il n'y en a
** pas, je lis en boucle un nouveau bloc.
** Entre 2 appels a get_next_line, les infos sont stockees dans un t_sbuf
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*plist = NULL;
	t_sbuf			*sbuf;
	int				res;
	int				resjoin;

	if ((sbuf = get_sbuf(fd, &plist)) == NULL)
		return (-1);
	if (sbuf->pos_in_buf == 0)
	{
		if ((res = read_in_elem(sbuf)) == -1 || res == 0)
			return (res);
	}
	if ((*line = ft_memalloc(sizeof(char) * (1))) == NULL)
		return (-1);
	if ((res = join(line, sbuf)))
		return (res);
	while ((res = read_in_elem(sbuf)) > 0)
	{
		if ((resjoin = join(line, sbuf)) != 0)
			return (resjoin);
	}
	return ((res == 0) ? 1 : res);
}
