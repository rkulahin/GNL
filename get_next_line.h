/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:44:34 by rkulahin          #+#    #+#             */
/*   Updated: 2018/11/12 09:15:57 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 100

int		get_next_line(const int fd, char **line);
char	*if_find(t_list *list, const int fd);
t_list	*find_list(t_list *start, const int fd);
#endif
