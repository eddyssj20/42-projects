/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusmain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:52:00 by elorente          #+#    #+#             */
/*   Updated: 2025/01/02 17:52:04 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fds[3];
    char    *line;
    int     lines;
    int     i;

    fds[0] = open("test1.txt", O_RDONLY);
    fds[1] = open("test2.txt", O_RDONLY);
    fds[2] = open("test3.txt", O_RDONLY);

    if (fds[0] == -1 || fds[1] == -1 || fds[2] == -1) {
        perror("Error al abrir los archivos");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        lines = 1;
        printf("Leyendo archivo %d\n", i + 1);
        
        while ((line = get_next_line(fds[i]))) {
            printf("%d->%s\n", lines++, line);
            free(line);
        }
        close(fds[i]);
    }

    return 0;
}