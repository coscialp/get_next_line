/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 10:47:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 16:43:48 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (n--)
		str[i++] = c;
	return (s);
}

void				*ft_calloc(size_t nb, size_t size)
{
	void			*ptr;

	if (!(ptr = malloc(size * nb)))
		return (NULL);
	ft_memset(ptr, 0, nb * size);
	return (ptr);
}

char				*ft_strfjoin(char *s1, const char *s2)
{
	int				i;
	int				j;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	j = 0;
	str = ft_strcpy(str, s1);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char				*next_line(char *str, char **line, size_t i)
{
	char			*tmp;

	if (!str)
		return ((char*)-1);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			str = ft_strcpy(str, tmp);
			free(tmp);
			return (*line);
		}
		else
		{
			*line = ft_substr(str, 0, i);
			str[0] = 0;
			return (*line);
		}
	}
	return (NULL);
}

int					get_next_line(int fd, char **line)
{
	int				ret;
	static char		*str[256];
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		if (!str[fd])
			if (!(str[fd] = (char*)ft_calloc(sizeof(char), 1)))
				return (-1);
		buf[ret] = '\0';
		if (!(tmp = ft_strfjoin(str[fd], buf)))
			return (-1);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((*line = next_line(str[fd], line, 0)) == (char*)-1)
		return (-1);
	return (*line == NULL ? 0 : 1);
}
