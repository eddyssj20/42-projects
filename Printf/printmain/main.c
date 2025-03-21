/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:37:02 by elorente          #+#    #+#             */
/*   Updated: 2024/12/10 17:37:07 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    // Test con cadenas
    printf("Original: [%s]\n", "Hello, World!");
    ft_printf("Custom:   [%s]\n", "Hello, World!");

    // Test con enteros
    printf("Original: [%d]\n", 42);
    ft_printf("Custom:   [%d]\n", 42);

    printf("Original: [%d]\n", -42);
    ft_printf("Custom:   [%d]\n", -42);

    // Test con unsigned int
    printf("Original: [%u]\n", 3000000000U);
    ft_printf("Custom:   [%u]\n", 3000000000U);

    // Test con punteros
    printf("Original: [%p]\n", NULL);
    ft_printf("Custom:   [%p]\n", NULL);

    int x = 42;
    printf("Original: [%p]\n", &x);
    ft_printf("Custom:   [%p]\n", &x);

    // Test con hexadecimal
    printf("Original: [%x]\n", 255);
    ft_printf("Custom:   [%x]\n", 255);

    printf("Original: [%X]\n", 255);
    ft_printf("Custom:   [%X]\n", 255);

    // Prueba combinada
    printf("Original: [%s] [%d] [%p] [%x]\n", "test", 42, &x, 255);
    ft_printf("Custom:   [%s] [%d] [%p] [%x]\n", "test", 42, &x, 255);
    ft_printf("                 .\"-,.__\n");
    ft_printf("                 `.     `.  ,\n");
    ft_printf("              .--'  .._,'\"-' `.\n");
    ft_printf("             .    .'         `'\n");
    ft_printf("             `.   /          ,'\n");
    ft_printf("               `  '--.   ,-\"'\n");
    ft_printf("                `\"`   |  \\\n");
    ft_printf("                   -. \\, |\n");
    ft_printf("                    `--Y.'      ___.\n");
    ft_printf("                         \\     L._, \\\n");
    ft_printf("               _.,        `.   <  <\\                _\n");
    ft_printf("             ,' '           `, `.   | \\            ( `\n");
    ft_printf("          ../, `.            `  |    .\\`.           \\ \\_\n");
    ft_printf("         ,' ,..  .           _.,'    ||\\l            )  '\".\n");
    ft_printf("        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");
    ft_printf("      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");
    ft_printf("    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");
    ft_printf("    |  '          ..         `-...-\"  |  `-'      / /        . `.\n");
    ft_printf("    | /           |L__           |    |          / /          `. `.\n");
    ft_printf("   , /            .   .          |    |         / /             ` `\n");
    ft_printf("  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n");
    ft_printf(" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");
    ft_printf(".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n");
    ft_printf("' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");
    ft_printf("|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n");
    ft_printf("||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");
    ft_printf("||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");
    ft_printf("|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");
    ft_printf("||/            _,-------7 '              . |  `-'    l         /    `||\n");
    ft_printf(". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");
    ft_printf(" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n");
    ft_printf("          /      ,'      |               |,'    \\-.._,.'/'\n");
    ft_printf("          .     /        .               .       \\    .''\n");
    ft_printf("        .`.    |         `.             /         :_,'.'\n");
    ft_printf("          \\ `...\\   _     ,'-.        .'         /_.-'\n");
    ft_printf("           `-.__ `,  `'   .  _.>----''.  _  __  /\n");
    ft_printf("                .'        /\"'          |  \"'   '_\n");
    ft_printf("               /_|.-'\\ ,\".             '.'`__'-( \\\n");
    ft_printf("                 / ,\"'\"\\,'               `/  `-.|\" mh\n");
    return (0);
}
