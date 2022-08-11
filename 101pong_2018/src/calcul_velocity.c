/*
** EPITECH PROJECT, 2018
** calcul_velocity.c
** File description:
** calculs the velocity of the ball
*/

#include "struct.h"
#include "my.h"
#include <stdio.h>

void display(t_ball ball, int n, float angle)
{
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n",
        ball.velocity[0], ball.velocity[1], ball.velocity[2]);
    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n",
        n, ball.pos_at_n[0], ball.pos_at_n[1], ball.pos_at_n[2]);
    if (angle > 0)
        printf("%.2f degrees\n", angle);
    else
        printf("The ball won't reach the bat.\n");
}

void calcul_coordinate_at_n(t_ball ball, int n)
{
    float angle = 0.0;

    for (int i = 0; i < 3; i = i + 1)
        ball.pos_at_n[i] = ball.velocity[i] * n + ball.init_pos[i];
    angle = check_ball_bat_contact(ball);
    display(ball, n, angle);
}

void calcul_velocity(char **av)
{
    t_ball ball;

    for (int i = 0; i < 3; i = i + 1)
        ball.init_pos[i] = my_str_to_float(av[i + 4]);
    for (int i = 0; i < 3; i = i + 1)
        ball.velocity[i] = ball.init_pos[i] - my_str_to_float(av[i + 1]);
    calcul_coordinate_at_n(ball, my_str_to_float(av[7]));
}