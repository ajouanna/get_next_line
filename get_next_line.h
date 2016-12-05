/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:48:04 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/05 18:10:55 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5000

typedef struct	s_sbuf
{
	int		fd;
	int		pos_in_buf;
	char	buf[BUFF_SIZE + 1];
}				t_sbuf;

int				get_next_line(const int fd, char **line);

#endif
