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
**  cree une nouvelle chaine etendue et libere la memoire de celle 
** passee en parametre
*/
/*
static char *extend_string(char *str, size_t size)
{
	char *res;
	size_t i;
	size_t len;

	if (size == 0)
		return str;
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + size));
	if (res)
	{
		i = 0;
		while (i < len)
		{
			res[i] = str[i];
			i++;
		}
		while (i < (len + size))
		{
			res[i] = 0;
			i++;
		}
	}
	free(str);
	return res;
}
*/

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
	int ret;
	int found_nl;

	ft_putstr("get_next_line : pos_in_buffer =");
	ft_putnbr(pos_in_buffer);
	ft_putstr("\n");

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
			ft_putstr("plus rien a lire\n");
			return (0);
		}

		i = 0;
	}
	else
	{
		if (pos_in_buffer == res)
			return (0);
		i = pos_in_buffer;
	}

	while (i < res)
	{
		if (buf[i] == '\n')
		{
			found_nl = 1;
			break;
		}
		i++;
	}
	*line = malloc(sizeof(char) * (i + 1));
	if (*line == NULL)
		return (-1);
	j = 0;
	while (j <= i)
	{
		(*line)[j] = buf[pos_in_buffer + j];
		j++;
	}
	(*line)[j] = 0;
	// pos_in_buffer = (i < res) ? i + 1 : res;
	pos_in_buffer = i + 1;
	if (found_nl)
		return (1);
	//if (pos_in_buffer == res)
	else
	{
		// ici, on sait qu'il faut lire a nouveau dans le fichier
		pos_in_buffer = 0;
		ret = get_next_line(fd, &subline);
		if (ret > 0) 
		{
			*line = ft_strjoin(*line, subline);
			ft_putstr("appel a ft_strjoin\n");
			free(subline);
			if (*line == NULL)
			{
				ft_putstr("erreur de ft_strjoin\n");
				return (-1);
			}
		}
		return (ret);

	}
	return (1);
}
