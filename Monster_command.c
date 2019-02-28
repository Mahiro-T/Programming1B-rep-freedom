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
    if (((address->hero_p)->hp) < 0)
    {
        (address->hero_p)->hp = 0;
        sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた! %s は死んでしまった!", k->name, k->name, (address->hero_p)->name, damage, (address->hero_p)->name);
        dead_message(k, 1);
    }
    else
    {
        sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた!", k->name, k->name, (address->hero_p)->name, damage);
    }
    sprintf(k->message, "%s", message);
}

void Enemy_magic_attack(appearance_character *k, Pointer_Addres *address)
{
    int damage;
    char message[256];

    srand((unsigned)time(NULL));
    damage = (k->magic_attack) + rand() % (k->lucky);

    (address->hero_p)->hp -= damage;

    if (((address->hero_p)->hp) < 0)
    {
        (address->hero_p)->hp = 0;
        sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた! %s は死んでしまった!", k->name, k->name, (address->hero_p)->name, damage, (address->hero_p)->name);
        dead_message(k, 1);
    }
    else
    {
        sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた!", k->name, k->name, (address->hero_p)->name, damage);
    }
    sprintf(k->message, "%s", message);
}

void Enemy_healing(appearance_character *k, Pointer_Addres *address)
{
    int heal;
    char message[256];

    srand((unsigned)time(NULL));
    heal = (k->healing) + (rand() % (k->lucky) + 5);

    sprintf(message, "%sはじゅもんをとなえた! %s のHPが %dかいふく!", k->name, k->name, heal);

    k->hp += heal;
    sprintf(k->message, "%s", message);
}

void Enemy_item(appearance_character *k, Pointer_Addres *address)
{
    int damage;
    char message[256];

    srand((unsigned)time(NULL));
    damage = (rand() % 10 + 5) + (k->lucky);

    (address->hero_p)->hp -= damage;

    if (((address->hero_p)->hp) < 0)
    {
        (address->hero_p)->hp = 0;
        sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた! %s は死んでしまった!", k->name, k->name, (address->hero_p)->name, damage, (address->hero_p)->name);
        dead_message(k, 1);
    }
    else
    {
        if (*k->Hero_alive_p == 1)
            sprintf(message, "%sのこうげき! %s は %s に %dのダメージをあたえた!", k->name, k->name, (address->hero_p)->name, damage);
    }
    sprintf(k->message, "%s", message);
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

void Enemy_attack(Pointer_Addres *k)
{
    if (*k->enemy_1_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_1_p), k);
        change_battle_message(k, (k->enemy_1_p)->message, 2);
    }
    if (*k->enemy_2_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_2_p), k);
        change_battle_message(k, (k->enemy_2_p)->message, 3);
    }
}