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
			ft_putstr("plus rien a lire\n");
			return (0);
		}

		i = 0;
		while (buf[i] != '\n' && i < res)
			i++;

		pos_in_buffer = (i < res) ? i + 1 : res;
		*line = malloc(sizeof(char) * (i + 1));
		if (*line == NULL)
			return (-1);
		j = 0;
		while (j <= i)
		{
			(*line)[j] = buf[j];
			j++;
		}
		(*line)[j] = 0;
		return (1);
	}
	else
	{
		if (pos_in_buffer == res)
			return (0);
		i = pos_in_buffer;
		while (buf[i] != '\n' && i < res)
			i++;
		
		pos_in_buffer = (i < res) ? i + 1 : res;
		*line = malloc(sizeof(char) * (i + 1));
		if (*line == NULL)
			return (-1);
		j = 0;
		while (j <= i)
		{
			(*line)[j] = buf[j];
			j++;
		}
		(*line)[j] = 0;
		return (1);
	}

}
