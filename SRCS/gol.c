/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:44:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/03 22:01:08 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

float   speed = SPEED;

int main(void)
{
    int height = HEIGHT;
    int width = WIDTH;
    int board[height][width];

    system("clear");
    menu_loop(height, width, board);
    return 0;
}