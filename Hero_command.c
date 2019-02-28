#include <gtk/gtk.h>
#include "stdlib.h"
#include "time.h"
#include <Monster.h>
#include <structs.h>
#include <GTK_tools.h>
#include <unistd.h>

void Hero_power_attack(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int damage;
    char message[256];

    srand((unsigned)time(NULL));
    damage = ((k->hero_p)->power_attack) + rand() % ((k->hero_p)->lucky);

    if ((rand() % 2) == 1 && *k->enemy_1_alive_p == 1)
    {
        ((k->enemy_1_p)->hp) -= damage;
        if (((k->enemy_1_p)->hp) <= 0)
        {
            (k->enemy_1_p)->hp = 0;
            *(k->enemy_1_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage, (k->enemy_1_p)->name);
        }
        else
        {
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage);
        }
    }
    else if (rand() % 2 == 1 && *k->enemy_2_alive_p == 1)
    {
        //Enemy2に攻撃がヒット
        ((k->enemy_2_p)->hp) -= damage;
        if (((k->enemy_2_p)->hp) <= 0)
        {
            (k->enemy_2_p)->hp = 0;
            *(k->enemy_2_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_2_p)->name, damage, (k->enemy_2_p)->name);
        }
        else
        {
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_2_p)->name, damage);
        }
    }
    else
    {
        //攻撃を外す
        sprintf(message, "%s のこうげき! しかし %s のこうげきははずれてしまった!", (k->hero_p)->name, (k->hero_p)->name);
    }
    change_battle_message(k, message, 1);
    if (*k->enemy_1_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_1_p), k);
    }
    if (*k->enemy_2_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_2_p), k);
    }

    change_status(k);
}

void Hero_magic_attack(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int damage;
    char message[256];
    srand((unsigned)time(NULL));
    damage = (k->hero_p)->magic_attack + rand() % (k->hero_p)->lucky;

    if ((rand() % 2) == 1 && *k->enemy_1_alive_p == 1)
    {
        (k->enemy_1_p)->hp -= damage;
        if (((k->enemy_1_p)->hp) <= 0)
        {
            (k->enemy_1_p)->hp = 0;
            *(k->enemy_1_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage, (k->enemy_1_p)->name);
        }
        else
        {
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage);
        }
    }
    else if ((rand() % 2 == 1) && *k->enemy_2_alive_p == 1)
    {
        //Enemy2に攻撃がヒット
        (k->enemy_2_p)->hp -= damage;
        if (((k->enemy_2_p)->hp) <= 0)
        {
            (k->enemy_2_p)->hp = 0;
            *(k->enemy_2_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_2_p)->name, damage, (k->enemy_2_p)->name);
        }
        else
        {
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage);
        }
    }
    else
    {
        //攻撃を外す
        sprintf(message, "%s のこうげき! しかし %s のこうげきははずれてしまった!", (k->hero_p)->name, (k->hero_p)->name);
    }

    change_battle_message(k, message, 1);

    if (*k->enemy_1_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_1_p), k);
    }
    if (*k->enemy_2_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_2_p), k);
    }
    change_status(k);
}
void Hero_healing(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int healing;
    char message[256];

    healing = (k->hero_p)->healing + (k->hero_p)->lucky;

    (k->hero_p)->hp += healing;

    sprintf(message, "%s は かいふくのじゅもんをとなえた｡ %s の体力が %d かいふく!", (k->hero_p)->name, (k->hero_p)->name, healing);

    change_battle_message(k, message, 1);

    if (*k->enemy_1_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_1_p), k);
    }
    if (*k->enemy_2_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_2_p), k);
    }

    change_status(k);
}

void Hero_item(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int damage;
    char message[256];
    srand((unsigned)time(NULL));
    damage = rand() % 10 + 1;
    if ((rand() % 2 == 1) && *k->enemy_1_alive_p == 1)
    {
        (k->enemy_1_p)->hp -= damage;
        if (((k->enemy_1_p)->hp) <= 0)
        {
            (k->enemy_1_p)->hp = 0;
            *(k->enemy_1_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage, (k->enemy_1_p)->name);
        }
        else
        {
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_1_p)->name, damage);
        }
    }
    else if ((rand() % 2) == 1 && *k->enemy_2_alive_p == 1)
    {
        //Enemy2に攻撃がヒット
        (k->enemy_2_p)->hp -= damage;
        if (((k->enemy_2_p)->hp) <= 0)
        {
            (k->enemy_2_p)->hp = 0;
            *(k->enemy_2_alive_p) = 0;
            sprintf(message, "%s のこうげき! %s は %s に %d のダメージをあたえた! %s をたおした!", (k->hero_p)->name, (k->hero_p)->name, (k->enemy_2_p)->name, damage, (k->enemy_2_p)->name);
        }
    }
    else
    {
        //攻撃を外す
        sprintf(message, "%s のこうげき! しかし %s のこうげきははずれてしまった!", (k->hero_p)->name, (k->hero_p)->name);
    }

    change_battle_message(k, message, 1);

    if (*k->enemy_1_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_1_p), k);
    }
    if (*k->enemy_2_alive_p == 1)
    {
        Enemy_attack_Entrance((k->enemy_2_p), k);
    }
    change_status(k);
}