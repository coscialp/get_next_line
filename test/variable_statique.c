/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   variable_statique.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:11:57 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 14:10:38 by coscialp    ###    #+. /#+    ###.fr     */
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

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = strlen(s1);
	j = strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * ((i * j) + 1))))
		return (NULL);
	j = 0;
	if (!(str = strdup(s1)))
		return (NULL);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_line(int fd, char *str)
{
	int ret;
	char buf[BUFFER_SIZE + 1];

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
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

int	ft_f(int fd, char **string)
{
	static char *s = "";
	static int i;
	int j;

	s = ft_read_line(fd, s);
	j = i;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	if (i == j)
	{
		*string = strdup("");
		i++;
		return (1);
	}
	*string = ft_substr(s ,j ,i - j);
	i++;
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	int fd;
	
	fd = open(av[1], O_RDONLY);
	while ((ft_f(fd, &line) != 0))
		printf("%s\n", line);
	close(fd);
	return 0;
}
