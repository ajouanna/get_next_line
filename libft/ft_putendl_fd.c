/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:15:40 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/08 16:18:25 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		l;
	char	c;

	if (s)
	{
		l = ft_strlen(s);
		write(fd, s, l);
		c = '\n';
		write(fd, &c, 1);
	}
}
