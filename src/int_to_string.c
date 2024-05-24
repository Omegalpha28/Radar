/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** convert interger to string
*/
#include <stdlib.h>

int size_num(int number)
{
    int size = 1;
    int temp = number;

    while (temp / 10 != 0) {
        temp /= 10;
        size++;
    }
    return size + 1;
}

char *size_string(int number)
{
    int size = 1;
    char *result;
    int temp = number;

    while (temp / 10 != 0) {
        temp /= 10;
        size++;
    }
    result = (char *)malloc(sizeof(char) * (size + 2));
    return result;
}

char *base_case(int number)
{
    if (number == 0)
        return "0";
    else if (number == 1)
        return "1";
}

char const *int_to_string(int number)
{
    int size = size_num(number);
    char *result = size_string(number);
    int count = 1;

    if (number == 0 || number == 1)
        return base_case(number);
    if (number < 0) {
        result[0] = '-';
        number = -number;
    } else
        size -= 1;
    while (number / 10 != 0) {
        result[size - count] = '0' + number % 10;
        number /= 10;
        count++;
    }
    result[size - count] = '0' + number;
    result[size + count - 1] = '\0';
    return result;
}
