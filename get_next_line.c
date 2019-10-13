/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 10:15:48 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 14:13:20 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *str)
{
	int ret;
	char buf[BUFFER_SIZE + 1];

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_strjoin(str, buf);
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
}
