#include <gtk/gtk.h>
#include "stdlib.h"
#include "time.h"

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
} appearance_character;

typedef struct
{
    appearance_character *hero_p;
    appearance_character *enemy_1_p;
    appearance_character *enemy_2_p;

    MainDialogs *dialogs_p;
    int *enemy_1_alive_p;
    int *enemy_2_alive_p;
} Pointer_Addres;

void change_status(void *d)
{
    Pointer_Addres *k = d;

    char buf[256];
    sprintf(buf, "%s HP:%03d", ((k->hero_p)->name), ((k->hero_p)->hp));
    gtk_label_set_text(GTK_LABEL((k->dialogs_p)->your_status), buf);

    char buf2[256];
    sprintf(buf2, "%s HP:%03d", (k->enemy_1_p)->name, (k->enemy_1_p)->hp);
    gtk_label_set_text(GTK_LABEL((k->dialogs_p)->Enemy1_status), buf2);

    //data = &((k->dialogs_p)->Enemy2_status);
    char buf3[256];
    sprintf(buf3, "%s HP:%03d", (k->enemy_2_p)->name, (k->enemy_2_p)->hp);
    gtk_label_set_text(GTK_LABEL((k->dialogs_p)->Enemy2_status), buf3);
}
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
        }
    }
    else
    {
        //攻撃を外す
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

    if (rand() % 2 == 1 && *k->enemy_1_alive_p == 1)
    {
        (k->enemy_1_p)->hp -= damage;
        if (((k->enemy_1_p)->hp) <= 0)
        {
            (k->enemy_1_p)->hp = 0;
            *(k->enemy_1_alive_p) = 0;
        }
    }
    else if (rand() % 2 == 1 && *k->enemy_2_alive_p == 1)
    {
        //Enemy2に攻撃がヒット
        (k->enemy_2_p)->hp -= damage;
        if (((k->enemy_2_p)->hp) <= 0)
        {
            (k->enemy_2_p)->hp = 0;
            *(k->enemy_2_alive_p) = 0;
        }
    }
    else
    {
        //攻撃を外す
    }

    change_status(k);
}
void Hero_healing(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int healing;
    char message;

    healing = (k->hero_p)->healing + (k->hero_p)->lucky;

    (k->hero_p)->hp += healing;

    change_status(k);
}

void Hero_item(GtkWidget *entryMainValue, gpointer user_data)
{
    Pointer_Addres *k = user_data;
    int damage;
    char message[256];
    srand((unsigned)time(NULL));
    damage = rand() % 10 + 1;
    if (rand() % 2 == 1 && *k->enemy_1_alive_p == 1)
    {
        (k->enemy_1_p)->hp -= damage;
        if (((k->enemy_1_p)->hp) <= 0)
        {
            (k->enemy_1_p)->hp = 0;
            *(k->enemy_1_alive_p) = 0;
        }
    }
    else if (rand() % 2 == 1 && *k->enemy_2_alive_p == 1)
    {
        //Enemy2に攻撃がヒット
        (k->enemy_2_p)->hp -= damage;
        if (((k->enemy_2_p)->hp) <= 0)
        {
            (k->enemy_2_p)->hp = 0;
            *(k->enemy_2_alive_p) = 0;
        }
    }
    else
    {
        //攻撃を外す
    }

    change_status(k);
}

int main(int argc, char **argv)
{
    MainDialogs dialogs;
    MainDialogs *di1;
    di1 = &dialogs;

    int enemy_1_alive_flag = 1;
    int enemy_2_alive_flag = 1;

    srand((unsigned)time(NULL));
    appearance_character Hero = {"Hero", rand() % 40 + 80, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6},
                         Enemy_1 = {"Linus_1", rand() % 10 + 50, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1},
                         Enemy_2 = {"Linus_2", rand() % 10 + 50, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1};

    appearance_character *appear1, *appear2, *appear3;
    appear1 = &Hero;
    appear2 = &Enemy_1;
    appear3 = &Enemy_2;

    Pointer_Addres pointers = {appear1, appear2, appear3, di1, &enemy_1_alive_flag, &enemy_2_alive_flag};

    gtk_init(&argc, &argv);

    dialogs.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(dialogs.window, 1000, 500);

    //ウィンドウにタイトルを設定する
    gtk_window_set_title(GTK_WINDOW(dialogs.window), "VS Linus Toparz");

    //ウィンドウが閉じられたときの動作
    gtk_container_set_border_width(GTK_CONTAINER(dialogs.window), 10);
    g_signal_connect(G_OBJECT(dialogs.window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    dialogs.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(dialogs.window), dialogs.vbox);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);

    dialogs.attack_button = gtk_button_new_with_label("攻撃");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.attack_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.attack_button, "clicked", G_CALLBACK(Hero_power_attack), &pointers);
    //g_signal_connect(G_OBJECT(dialogs.attack_button), "clicked", G_CALLBACK(change_status), &pointers);

    dialogs.magic_button = gtk_button_new_with_label("魔法");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.magic_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.magic_button, "clicked", G_CALLBACK(Hero_magic_attack), &pointers);
    //g_signal_connect(G_OBJECT(dialogs.attack_button), "clicked", G_CALLBACK(change_status), &pointers);

    dialogs.healing_button = gtk_button_new_with_label("回復");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.healing_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.healing_button, "clicked", G_CALLBACK(Hero_healing), &pointers);
    //g_signal_connect(G_OBJECT(dialogs.attack_button), "clicked", G_CALLBACK(change_status), &pointers);

    dialogs.item_button = gtk_button_new_with_label("アイテム");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.item_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.item_button, "clicked", G_CALLBACK(Hero_item), &pointers);
    //g_signal_connect(G_OBJECT(dialogs.item_button), "clicked", G_CALLBACK(change_status), &pointers);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    dialogs.label_story_1 = gtk_label_new("Enemy appear!");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.label_story_1, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    dialogs.label_story_2 = gtk_label_new("What will you do?");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.label_story_2, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    dialogs.label_story_3 = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.label_story_3, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.image = gtk_image_new_from_file("./00_m.jpg");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.image, TRUE, TRUE, 0);
    dialogs.image = gtk_image_new_from_file("./01_m.jpg");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.image, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    dialogs.your_status = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.your_status, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    dialogs.Enemy1_status = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.Enemy1_status, TRUE, TRUE, 0);

    dialogs.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.hbox, TRUE, TRUE, 0);
    dialogs.Enemy2_status = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(dialogs.vbox), dialogs.Enemy2_status, TRUE, TRUE, 0);
    change_status(&pointers);

    gtk_widget_show_all(dialogs.window);
    gtk_main();
    //ここまで設定 以下より戦闘処理

    return 0;
}
