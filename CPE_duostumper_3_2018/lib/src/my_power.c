/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** return the first argument raised a the power of the second
*/
int my_power(int nb, int p)
{
    int l_result;
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    l_result = nb * my_power(nb, (p - 1));
    if (l_result <= 2147483647) {
        result = l_result;
    } else {
        return (0);
    }
    return (result);
}
