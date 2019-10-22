/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:16:41 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 17:19:36 by coscialp    ###    #+. /#+    ###.fr     */
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
#include "get_next_line.h"

int			main(int ac, char **av)
{
	int		fd;
    int     ret;
	char	*line;
    int     count = 0;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		puts(line);
        free(line);
        count++;
        printf("\nVALEUR DE RETOUR : %d\n", ret);
	}
    printf("VALEUR DE RETOUR : %d\n", ret);
    printf("LIGNE LUE(S) : %d\n", count);
	close(fd);
}