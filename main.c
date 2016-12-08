/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:49:11 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/08 14:37:38 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void	print_buffer(char *line)
{
	int i;

	i = 0;
	ft_putstr("print_buffer : ");
	while (line[i])
	{
		ft_putchar(line[i]);
		i++;
	}
	ft_putchar('\n');
}

/*
** main : enchainement des traitements et gestion des erreurs
*/

int		main(int ac, char *av[])
{
	char		*buf;
	int			fd;
	int			ret;

	buf = NULL;
	if (ac > 2)
	{
		ft_putstr("usage : pour lire un fichier ./get_next_line source_file\n");
		ft_putstr("usage : pour lire l'entree standard ./get_next_line \n");
		return (1);
	}
	if (ac == 1)
		fd = 1;
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Erreur open\n");
		return (1);
	}
	while ((ret = get_next_line(fd, &buf)) == 1)
	{
		print_buffer(buf);
		free(buf);
	}
	close(fd);
	return (0);
}
