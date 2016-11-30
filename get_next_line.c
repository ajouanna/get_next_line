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
#include <unistd.h>

/*
**
*/

int		get_next_line(const int fd, char **line)
{
	static int pos_in_buffer = 0;
	static char *buf = 0;
	int res;

	if (pos_in_buffer)
	while ((res = read(

}
