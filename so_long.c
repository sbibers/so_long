/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/11 20:17:44 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <X11/keysym.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>

typedef struct s_var
{
    void *mlx;
    void *win;
    void *img;
    int   img_with;
    int   img_height;
    int   x;
    int   y;
}   t_vars;


#define MAX_LINES 1000

void check(char **lines)
{
    int size;
    int i;
    int j;

    size = 0;
    while (lines[0][size] != '\n')
        size++;
    i = 1;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j] != '\0' && lines[i][j] != '\n')
            j++;
        if (j != size)
        {
            i = -1;
            while (lines[++i])
                free(lines[i]);
            free(lines);
            exit(0);
        }
        i++;
    }
}

void ft_free(char **str)
{
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void check_sympol(char **lines)
{
    int i;
    int j;

    i = 0;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j])
        {
            if (lines[i][j] != '1' && lines[i][j] != '0' && lines[i][j] != 'C' && lines[i][j] != 'P' && lines[i][j] != 'E' && lines[i][j] != '\n')
            {
                ft_free(lines);
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void read_map(char *argv)
{
    int fd = open(argv, O_RDONLY);
    if (fd == -1)
        exit(1);
    char **lines;
    char *str;
    int count = 0;

    lines = malloc(MAX_LINES * sizeof(char *));
    while ((str = get_next_line(fd)) != NULL && count < MAX_LINES)
    {
        size_t len = strlen(str);
        lines[count] = (char *)malloc(len + 1);
        if (!lines[count])
        {
            free(str);
            break;
        }
        strcpy(lines[count], str);
        free(str);
        count++;
    }
    lines[count] = NULL;
    check(lines);
    check_sympol(lines);
    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1][0] == '\0')
        return (perror(""), 1);
    read_map(argv[1]);
    return (0);
}
