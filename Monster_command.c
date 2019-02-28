#include <gtk/gtk.h>
#include "stdlib.h"
#include "time.h"
#include <structs.h>
#include <GTK_tools.h>

void Enemy_power_attck(appearance_character *k, Pointer_Addres *address)
{

    int damage;
    char message[256];

    srand((unsigned)time(NULL));
    damage = (k->power_attack) + rand() % (k->lucky);

    (address->hero_p)->hp -= damage;
}

void Enemy_magic_attack(appearance_character *k, Pointer_Addres *address)
{
    int damage;

    srand((unsigned)time(NULL));
    damage = (k->magic_attack) + rand() % (k->lucky);

    (address->hero_p)->hp -= damage;
}

void Enemy_healing(appearance_character *k, Pointer_Addres *address)
{
    int damage;

    srand((unsigned)time(NULL));
    damage = (k->healing) + rand() % (k->lucky);

    (address->hero_p)->hp -= damage;
}

void Enemy_item(appearance_character *k, Pointer_Addres *address)
{
    int damage;

    srand((unsigned)time(NULL));
    damage = (rand() % 10 + 5) + (k->lucky);

    (address->hero_p)->hp -= damage;
}

//敵モンスターの処理開始はここから
void Enemy_attack_Entrance(appearance_character *k, Pointer_Addres *address)
{

    srand((unsigned)time(NULL));
    int a = rand() % 4;

    switch (a)
    {
    case 0:
        Enemy_power_attck(k, address);
        break;

    case 1:
        Enemy_magic_attack(k, address);
        break;

    case 2:
        Enemy_healing(k, address);
        break;

    case 3:
        Enemy_item(k, address);
        break;
    }
}
