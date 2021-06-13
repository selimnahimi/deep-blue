#include "header.h"
#include <stdio.h>
/**
 * main - Entry Point
 *
 * Return: Always 0.
 */
int main(void)
{
    printf("4 + 2 = %d\n", calculator('+', 4, 2));
    printf("4 - 2 = %d\n", calculator('-', 4, 2));
    printf("4 * 2 = %d\n", calculator('*', 4, 2));
    printf("4 / 2 = %d\n", calculator('/', 4, 2));
    return (0);
}