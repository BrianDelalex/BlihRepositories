/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** factor and power
*/

int  my_factrec_synthesis(int nb)
{
    int res = 1;

    if (nb == 1 || nb == 0)
        return (1);
    if (nb > 12 || nb < 0)
        return (0);
    for (; nb > 1; nb--) {
        res = res * nb;
    }
    return (res);
}

int  my_squareroot_synthesis(int nb)
{
    int res = 0;

    if (nb < 0)
        return (-1);
    for (; (res * res) < nb; res++);
    if ( (res * res) == nb )
        return (res);
    else
        return (-1);
}
