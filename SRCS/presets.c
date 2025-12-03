/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:56:15 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/03 22:08:18 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

char	*pick_preset(int selection)
{
	switch (selection)
	{
		case 1:
		{
			return ("ssssssssssssssssddddddddddddddddddddddddddddddddddddxddx");
		}
		case 2:
		{
			return ("sssddddxxsdxxsaaxddx");
		}
		case 3:
		{
			return ("ssssssssssssssssssssssssdddddddddddddddddddddddddddddddddxxdddxxsaaaaaaxdddddddx");
		}
		case 4:
		{
			return ("ssssssssssssssssssssdddddddddddddddddddddddddddddddddxdddddddddx");
		}
	}
	return ("");
}

float   change_speed(void)
{
    float   selection = 0;
    while (selection == 0)
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Set the simulation speed (float: 1, 1.2, 3...):\n");
        printf(">>>>> ");
        scanf("%f", &selection);
    }
    return (selection);
}

int   change_iter(void)
{
    int   selection = 0;
    while (selection == 0)
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Set the number of iterations:\n");
        printf(">>>>> ");
        scanf("%d", &selection);
    }
    return (selection);
}

void    sim_preset(int height, int width, int board[height][width])
{
    int selection = 0;
    int iter = 200;
    float   sim_speed = speed;
    while ((selection == 0) || (selection != 4))
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Choose an option:\n");
        printf("1. Run simulation.\n");
        printf("2. Change speed.\n");
        printf("3. Set the number of iterations.\n");
        printf("4. Back to main menu\n");
        printf(">>>>> ");
        scanf("%d", &selection);
        switch (selection)
        {
            case 1:
            {
                for (int i = 0; i < iter ; i++)
                {
                    system("clear");
                    printf("-------------Game of Life-------------\n");
                    simulation(height, width, board);
                    print_board(height, width, board);
                    usleep(500000 * (1 / sim_speed));
                }
                break;
            }
            case 2:
            {
                sim_speed = change_speed();
                break;
            }
            case 3:
            {
                iter = change_iter();
                break;
            }
            case 4:
            {
                return ;
            }        
        }
    }
}


void    run_preset(int height, int width, int board[height][width])
{
    int selection = 0;
    while ((selection == 0) || (selection > 5))
    {
        system("clear");
        printf("-------------Game of Life-------------\n");
        printf("Select one of the following presets:\n");
        printf("1. Blinker.\n");
        printf("2. Glider.\n");
        printf("3. Acorn.\n");
        printf("4. Complex pattern.\n");
        printf("5. Back to main menu\n");
        printf(">>>>> ");
        scanf("%d", &selection);
    }
    if (selection == 5)
        return ;
    else
    {
        init_board(height, width, board, pick_preset(selection));
        print_board(height, width, board);
        sim_preset(height, width, board);
    }
}