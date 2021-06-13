#include "header.h"
/**
 * calculator - Executes basic math operations
 *
 * @op: char that indicates math operation executed.
 * @num1: number one.
 * @num2: number two.
 * Return: addition if op is '+'
 *         subtraction if op is '-'
 *         multiplication if op is '*'
 *         division if op is '/'
 *         otherwise, 0.
 */
int calculator(char op, int num1, int num2)
{
    if (op == '+')
        return (num1 + num2);
    if (op == '-')
        return (num1 - num2);
    if (op == '*')
        return (num1 * num2);
    if (op == '/')
        return (num1 /num2);
    return (0);
}