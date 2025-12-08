/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:44:32 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/08 18:09:43 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H
# define WIDTH 80
# define HEIGHT 45
# define SPEED 5
# define ITERATIONS 100
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
extern float	speed;
extern int		iterations;

void	init_board(int height, int width, int board[height][width], char* pattern);
void	print_board(int height, int width, int board[height][width]);
char	*read_pattern(void);
int		count_neighbours(int height, int width, int j, int i, int board[height][width]);
void	simulation(int height, int width, int board[height][width]);

void	run_preset(int height, int width, int board[height][width]);
float	change_speed(void);

void    run_simulation(int height, int width, int board[height][width]);
int   change_iter(void);

//Main menu loop and selection functions
int		main_menu(int height, int width, int board[height][width]);
void	run_custom(int height, int width, int board[height][width]); // TODO
void	menu_loop(int height, int width, int board[height][width]);

void    run_custom(int height, int width, int board[height][width]);

#endif