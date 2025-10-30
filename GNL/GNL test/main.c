/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
    int     fd;
    char    *line;
    int     lines;

    lines = 1;
    fd = open("test1.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        printf("%d->%s\n", lines++, line);
        free(line);
    }
    close(fd);
}
