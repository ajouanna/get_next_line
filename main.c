/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:49:11 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/30 14:15:49 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void 	print_buffer(char *line)
{
	int i;

	i = 0;
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

	if (ac != 2)
	{
		ft_putstr("usage : ./get_next_line source_file\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Erreur open\n");
		return (1);
	}
	while ((ret = get_next_line(fd, &buf)) == 1)
	{
		ft_putstr("main : get_next_line a renvoye 1\n");
		print_buffer(buf);
		free(buf);
	}
	ft_putstr("main : get_next_line a renvoye \n");
	ft_putnbr(ret);
	ft_putstr("\n");
	close(fd);
	return (0);
}
