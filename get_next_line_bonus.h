/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.h                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 10:47:30 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:16:32 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "stdlib.h"
# include <unistd.h>

size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nb, size_t size);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
