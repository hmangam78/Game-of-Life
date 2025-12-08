/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:46:45 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/08 18:21:54 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"
#include <termios.h>
#include <unistd.h>

void    set_pattern(int height, int width, int board[height][width])
{
    char    c = 0;
    int     x = 0;
    int     y = 0;
    bool    pen_down = false;
    struct termios old_settings, new_settings;

    while ((c = getchar()) != '\n');
    
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            board[i][j] = 0;
    
    while (c != 'p')
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if ((i == y) && (j == x))
                    printf("█");
                else if (board[i][j] == 0)
                    printf(".");
                else
                    printf("O");
            }
            printf("\n");
        }
        printf("\nControls: arrows=move, space=toggle pen, c=clear cell, p=save\n");
        c = getchar();
        
        if (c == 27)  // ESC
        {
            getchar();  // [
            c = getchar();
            if (c == 'A' && y > 0)  // Up cursor
                y--;
            else if (c == 'B' && y < (height - 1))  // Down cursos
                y++;
            else if (c == 'C' && x < (width - 1))  // Right cursor
                x++;
            else if (c == 'D' && x > 0)  // Left cursor
                x--;
        }
        else if (c == ' ')  // Toggle pen
            pen_down = !pen_down;
        else if (c == 'c')
        {
            pen_down = false;
            board[y][x] = 0;
        }
        else if (c == 'p')  // Exit
            break;
        
        if (pen_down && c != 27)
            board[y][x] = 1;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
}

void    run_custom(int height, int width, int board[height][width])
{
    int selection = 0;
    while ((selection == 0) || (selection != 5))
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Choose an option:\n");
        printf("1. Draw a pattern.\n");
        printf("2. Run simulation.\n");
        printf("3. Change speed.\n");
        printf("4. Set the number of iterations.\n");
        printf("5. Back to main menu\n");
        printf(">>>>> ");
        scanf("%d", &selection);
        switch (selection)
        {
            case 1:
            {
                set_pattern(height, width, board);
                break;
            }
            case 2:
            {
                run_simulation(height, width, board);
                break;
            }
            case 3:
            {
                speed = change_speed();
                break;
            }
            case 4:
            {
                iterations = change_iter();
                break;
            }
            case 5:
            {
                return ;
            }        
        }
    }
}