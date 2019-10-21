/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 10:16:01 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:08:20 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>

size_t		ft_strlen(const char *str);
size_t		ft_strnlen(const char *str, size_t maxlen);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strndup(const char *s, size_t n);
int			get_next_line(int fd, char **line);
char	    *ft_strchr(const char *str, int c);
char		*ft_read_line(int fd, char *str);
char    	*ft_substr(char *s, unsigned int start, size_t len);

#endif
