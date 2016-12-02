/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:04:19 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/02 16:09:06 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** le principe de fonctionnement : je lis le fichier par blocs de taille
** BUFF_SIZE. Dans le buffer lu, je vais jusqu'au retour chariot. S'il n'y en a
** pas, je lis un nouveau bloc. S'il y en a, je garde dans une varable statique
** ou j'en suis, pour la prochaine lecture
*/

int		get_next_line(const int fd, char **line)
{
	static t_sbuf	sbuf = {.pos_in_buf = 0 };
	int				i;
	int				j;
	char			*subline;
	char			*line2;
	int				ret;
	int				found_nl;

	found_nl = 0;
	if (sbuf.pos_in_buf == 0)
	{
		sbuf.res = read(fd, sbuf.buf, BUFF_SIZE);
		if (sbuf.res == -1)
			return (-1);
		if (sbuf.res == 0)
			return (0);
		i = 0;
	}
	else
		i = sbuf.pos_in_buf;
	if (i >= sbuf.res)
		return (0);
	while (i < sbuf.res)
	{
		if (sbuf.buf[i] == '\n')
		{
			found_nl = 1;
			break ;
		}
		i++;
	}
	if ((*line = malloc(sizeof(char) * (i - sbuf.pos_in_buf + 1))) == NULL)
		return (-1);
	j = 0;
	while (j < (i - sbuf.pos_in_buf))
	{
		(*line)[j] = sbuf.buf[sbuf.pos_in_buf + j];
		j++;
	}
	(*line)[j] = 0;
	sbuf.pos_in_buf = i + 1;
	if (found_nl)
		return (1);
	if (sbuf.pos_in_buf >= sbuf.res)
	{
		sbuf.pos_in_buf = 0;
		ret = get_next_line(fd, &subline);
		if (ret == 1)
		{
			line2 = ft_strjoin(*line, subline);
			free(*line);
			free(subline);
			*line = line2;
			if (*line == NULL)
				return (-1);
		}
		if (ret == 0)
			ret = 1;
		return (ret);
	}
	return (0);
}
