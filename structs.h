#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *magic_button;
    GtkWidget *attack_button;
    GtkWidget *healing_button;
    GtkWidget *item_button;

    GtkWidget *image;
    GtkWidget *entry;
    GtkWidget *label_story_1;
    GtkWidget *label_story_2;
    GtkWidget *label_story_3;
    GtkWidget *your_status;
    GtkWidget *Enemy1_status;
    GtkWidget *Enemy2_status;

    GtkWidget *Reset_button;
} MainDialogs;

typedef struct
{
    char name[20];
    int hp;
    int magic_attack;
    int power_attack;
    int power_guard;
    int magic_guard;
    int lucky;
    int healing;
    char message[256];
} appearance_character;

typedef struct
{
    appearance_character *hero_p;
    appearance_character *enemy_1_p;
    appearance_character *enemy_2_p;

    MainDialogs *dialogs_p;
    int *enemy_1_alive_p;
    int *enemy_2_alive_p;
    int *Hero_alive_p;
} Pointer_Addres;

#endif