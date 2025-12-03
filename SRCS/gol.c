/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:44:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/03 13:51:11 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

float speed = SPEED;

int    main_menu(int height, int width, int board[height][width])
{
    (void)height;
    (void)width;
    (void)board;
    int selection = 0;
    while ((selection < 1) || (selection > 4))
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Enter one of the following options:\n");
        printf("1. Select a pattern to run.\n");
        printf("2. Draw a new pattern.\n");
        printf("3. Change the speed of the simulation.\n");
        printf("4. Exit.\n");
        printf(">>>>> ");
        scanf("%d", &selection);
    }
    return (selection);
}

void    run_custom(int height, int width, int board[height][width])
{
    (void)height;
    (void)width;
    (void)board;
    system("clear");
    printf("Run custom\n");
    usleep(2000000);
}

int main(int args, char **argv)
{
    char    *pattern;
    system("clear");
    if (args != 1)
    {
        printf("Wrong usage. Run with './gameoflife'\n");
        return 0;
    }

    (void)pattern;
    (void)argv;
    int height = HEIGHT;
    int width = WIDTH;
    int board[height][width];
    int selection = 0;
    while (selection != 4)
    {
        selection = main_menu(height, width, board);
        switch (selection)
        {
            case 1:
            {
                run_preset(height, width, board);
                break;
            }
            case 2:
            {
                run_custom(height, width, board);
                break;
            }
            case 3:
            {
                speed = change_speed();
                break;
            }
            default:
                ;
        }
    }
    /*pattern = read_pattern();
    init_board(height, width, board, pattern);
    //print_board(height, width, board);
    for (int i = 0; i < 100; i++)
    {
       simulation(height, width, board);
       print_board(height, width, board);
       usleep(500000 * (1 / speed));
    }
    free(pattern);*/

    return 0;
}