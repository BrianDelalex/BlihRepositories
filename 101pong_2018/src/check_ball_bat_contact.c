/*
** EPITECH PROJECT, 2018
** check_ball_bat_contact.c
** File description:
** check if the ball has a contact with the bat
*/

#include <math.h>
#include "struct.h"

float check_ball_bat_contact(t_ball ball)
{
    float angle = 0.0;
    float t = 0.0;
    float length = 0.0;
    float x_zero = 0.0;
    float y_zero = 0.0;

    if (ball.velocity[0] == 0 && ball.velocity[1] == 0)
        return (90.0);

    if ((ball.init_pos[2] > 0 && ball.pos_at_n[2] < 0) || 
        (ball.init_pos[2] < 0 && ball.pos_at_n[2] > 0)) {
        t = - ball.init_pos[2] / ball.velocity[2];
        x_zero = ball.velocity[0] * t + ball.init_pos[0];
        y_zero = ball.velocity[1] * t + ball.init_pos[1];
        length = sqrt( pow( (ball.init_pos[0] - x_zero), 2) + 
        pow( (ball.init_pos[1] - y_zero), 2) + pow(ball.init_pos[2], 2));
        angle = asin( ball.init_pos[2] / length ) * 180 / M_PI;
    }
    return (angle);
}