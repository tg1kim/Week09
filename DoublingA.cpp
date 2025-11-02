#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
        double money = 1.0;

        for (int i = 2; i <= 30; i++) {
                money *= 2.0;
                printf("%d일날 현재 금액=%lf\n", i, money);
        }
}
