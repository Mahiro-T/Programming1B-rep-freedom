#include <gtk/gtk.h>
#include "stdlib.h"
#include "time.h"
#include <structs.h>

void Enemy_power_attck(void *d)
{
    appearance_character *k = d;
}

void Enemy_magic_attack(void *d)
{
    appearance_character *k = d;
}

void Enemy_healing(void *d)
{
    appearance_character *k = d;
}

void Enemy_item(void *d)
{
    appearance_character *k = d;
}

void Enemy_attack_Entrance(void *d)
{
    appearance_character *k = d;
    srand((unsigned)time(NULL));
    int a = rand() % 4;

    switch (a)
    {
    case 0:
        Enemy_power_attck(k);
        break;

    case 1:
        Enemy_magic_attack(k);
        break;

    case 2:
        Enemy_healing(k);
        break;

    case 3:
        Enemy_item(k);
        break;
    }
}

