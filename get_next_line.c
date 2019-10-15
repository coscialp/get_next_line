/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:11:57 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 12:41:04 by coscialp    ###    #+. /#+    ###.fr     */
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

char		*ft_strfjoin(char *s1, const char *s2)
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
	//ft_strdel(&s1);
	return (str);
}

int		ft_read_line(int fd, char **str)
{
	int ret;
	char buf[BUFFER_SIZE + 1];

	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		*str = ft_strfjoin(*str, buf);
		if (strchr(buf, '\n'))
			break ;
	}
	return (1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	return (str);
}

int	get_next_line(int fd, char **string)
{
	static char *s = "";
	int i;

	if (ft_read_line(fd, &s))
		return (-1);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		return (0);
	}
	if (i == 0)
	{
		*string = strdup("");
		i++;
		return (1);
	}
	*string = ft_substr(s ,0 ,i);
	i++;
	s = s + i;
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	int fd;
	int i = 6;
	
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return 0;
	while ((get_next_line(fd, &line) != 0))
		ft_putendl(line);
	close(fd);
	return 0;
}