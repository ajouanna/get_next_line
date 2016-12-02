/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:04:19 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/30 15:22:14 by ajouanna         ###   ########.fr       */
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
	static int pos_in_buffer = 0;
	static char buf[BUFF_SIZE + 1];
	static int res;
	int i;
	int j;
	char *subline;
	char *line2;
	int ret;
	int found_nl;

/*
	ft_putstr("get_next_line : pos_in_buffer =");
	ft_putnbr(pos_in_buffer);
	ft_putstr(" res =");
	ft_putnbr(res);
	ft_putstr("\n");
*/
	found_nl = 0;
	if (pos_in_buffer == 0)
	{
		res = read(fd, buf, BUFF_SIZE);
		if (res == -1)
		{
			ft_putstr("erreur de lecture\n");
			return (-1);
		}
		if (res == 0)
		{
			// ft_putstr("plus rien a lire\n");
			return (0);
		}

		i = 0;
	}
	else
	{
//		if (pos_in_buffer == res)
//			return (0);
		i = pos_in_buffer;
	}

	while (i < res)
	{
		if (buf[i] == '\n')
		{
		/*
			ft_putstr("newline trouve pour i = ");
			ft_putnbr(i);
			ft_putstr("\n");
			*/
			found_nl = 1;
			break;
		}
		i++;
	}
	*line = malloc(sizeof(char) * (i - pos_in_buffer + 1));
	if (*line == NULL)
		return (-1);
	j = 0;
	// ici, i vaut soit res, soit la position du \n
	while (j < (i - pos_in_buffer))
	{
		(*line)[j] = buf[pos_in_buffer + j];
		j++;
	}
	(*line)[j] = 0;
	// pos_in_buffer = (i < res) ? i + 1 : res;
	pos_in_buffer = i + 1;
	if (found_nl)
		return (1);
	if (pos_in_buffer >= res)
	// else
	{
		// ici, on sait qu'il faut lire a nouveau dans le fichier
		pos_in_buffer = 0;
		ret = get_next_line(fd, &subline);
		if (ret > 0) 
		{
			line2 = ft_strjoin(*line, subline);
			free(*line);
			free(subline);
			*line = line2;
			if (*line == NULL)
			{
				ft_putstr("erreur de ft_strjoin\n");
				return (-1);
			}
		}
		if (ret == 0)
			return (1);
		return (ret);

	}
	return (1);
}
