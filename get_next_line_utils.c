/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 10:15:55 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 11:46:16 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strnlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (str[i] && i < maxlen)
		i++;
	return (i);
}

char		*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*dest;

	i = 0;
	size = ft_strlen(str);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * ((i * j) + 1))))
		return (NULL);
	j = 0;
	if (!(str = ft_strdup(s1)))
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

char	*ft_strndup(const char *s, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strnlen(s, n) + 1))))
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
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
