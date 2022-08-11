/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display_the_wanted_nbr
*/

void my_putchar(char c);

void my_putnbr(int i)
{
    if (i < 0){
        my_putchar('-');
        i = i * (-1);
    }
    if (i > 9)
        my_putnbr(i / 10);
    my_putchar(i % 10 + 48);
}
