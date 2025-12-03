/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:10:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/03 13:47:28 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

void    init_board(int height, int width, int board[height][width], char *pattern)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
            board[j][i] = 0;
    }
    int x = 0;
    int y = 0;
    bool pen_down = 0;
    for (int i = 0; pattern[i] != '\0'; i++)
    {
        if (pattern[i] == 'x')
            pen_down = !pen_down;
        else if ((pattern[i] == 'w') && (y > 0))
                y -= 1;
        else if ((pattern[i] == 'a') && (x > 0))
                x -= 1;
        else if ((pattern[i] == 's') && (y < (height - 1)))
                y += 1;
        else if ((pattern[i] == 'd') && (x < (width - 1)))
                x += 1;
        if (pen_down)
            board[y][x] = 1;        
    }
}

void   print_board(int height, int width, int board[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (board[j][i] == 0)
                putchar('.');
            else
                putchar('X');
        }
        putchar('\n');
    } 
}

char    *read_pattern(void)
{
    char    *input;
    char    c;
    int     bytes_read = 0;
    int     len = 0;

    input = malloc(sizeof(char));
    if (!input)
        return NULL;
    while ((bytes_read = read(STDIN_FILENO, &c, 1)) > 0)
    {
        char    *tmp;
        tmp = realloc(input, len + 2);
        if (!tmp)
        {
            free(input);
            return (NULL);
        }
        input = tmp;
        input[len] = c;
        len++;
    }
    input[len] = '\0';
    putchar('\n');
    return (input);
}

int count_neighbours(int height, int width, int j, int i, int board[height][width])
{
    int neighbours = 0;
    for (int k = -1; k < 2; k++)
    {
        if (((j + k) >= 0) && ((j + k) < height))
        {
            for (int l = -1; l < 2; l++)
                if (((i + l) >= 0) && ((i + l) < width))
                    neighbours += board[j + k][i + l];
        }
    }
    neighbours -= board[j][i];
    return (neighbours);
}

void    simulation(int height, int width, int board[height][width])
{
    int new_board[height][width];
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            new_board[j][i] = 0;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int alive_neighbours = 0;
            alive_neighbours = count_neighbours(height, width, j, i, board);
            switch (alive_neighbours)
            {
                case 0:
                {
                    new_board[j][i] = 0;
                    break;
                }
                case 1:
                {
                    new_board[j][i] = 0;
                    break;
                }
                case 2:
                {
                    new_board[j][i] = board[j][i];
                    break;
                }
                case 3:
                {
                    new_board[j][i] = 1;
                    break;
                }
                default:
                {
                    new_board[j][i] = 0;   
                }
            }
        }
    }
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            board[j][i] = new_board[j][i];
}