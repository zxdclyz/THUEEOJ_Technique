#include <iostream>

inline int fast_read()
{
    char ch = getchar();
    int x = 0, flag = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x * flag;
}