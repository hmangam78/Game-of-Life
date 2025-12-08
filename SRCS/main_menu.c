/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:55:16 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/04 09:09:57 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

int	main_menu(int height, int width, int board[height][width])
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

void	menu_loop(int height, int width, int board[height][width])
{
	int	selection = 0;

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
}