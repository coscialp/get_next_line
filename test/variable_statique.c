/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   variable_statique.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:11:57 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 19:01:27 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdlib.h"
#include "unistd.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

void	ft_strdel(char **ptr)
{
	if(!(ptr))
		return ;
	free(*ptr);
	*ptr = NULL;
}

char		*ft_strfjoin(char *s1,const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = strlen(s1);
	j = strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	j = 0;
	str = strcpy(str, s1);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	ft_strdel(&s1);
	return (str);
}

char	*ft_read_line(int fd, char *str)
{
	int ret;
	char buf[BUFFER_SIZE + 1];

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(str = ft_strfjoin(str, buf)))
			return (NULL);
		if (strchr(buf, '\n'))
			break ;
	}
	return (str);
}

void	ft_putendl(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

char		*ft_strfdup(char *str)
{
	int		size;
	int		i;
	char	*dest;

	i = 0;
	size = strlen(str);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	ft_strdel(&str);
	return (dest);
}

char	*ft_subfstr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	ft_strdel(&s);
	return (str);
}

int	ft_f(int fd, char **string)
{
	static char *s;
	int i;

	if (!s)
		s = strdup("");
	s = ft_read_line(fd, s);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	if (i == 0)
	{
		*string = strdup("");
		s = strdup(s + i + 1);
		return (1);
	}
	s = ft_subfstr(s ,0 ,i);
	*string = strdup(s);
	i++;
	s = ft_strfdup(s + i);
	return (1);
}

int				main(void)
{
	char		*line = NULL;
	int			fd = open("get_next_line.c", O_RDONLY);
	int i = 0;

	while(ft_f(fd, &line) != 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
