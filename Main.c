#include <gtk/gtk.h>
#include "stdlib.h"
#include "time.h"
#include <structs.h>
#include <Hero.h>
#include <GTK_tools.h>
#include <Monster.h>

int main(int argc, char **argv)
{
    MainDialogs dialogs;
    MainDialogs *di1;
    di1 = &dialogs;

    int enemy_1_alive_flag = 1;
    int enemy_2_alive_flag = 1;

    srand((unsigned)time(NULL));
    appearance_character Hero = {"Hero", rand() % 40 + 80, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6, rand() % 12 + 6},
                         Enemy_1 = {"Linus_1", rand() % 10 + 70, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1},
                         Enemy_2 = {"Linus_2", rand() % 10 + 70, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1};

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

    dialogs.magic_button = gtk_button_new_with_label("魔法");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.magic_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.magic_button, "clicked", G_CALLBACK(Hero_magic_attack), &pointers);

    dialogs.healing_button = gtk_button_new_with_label("回復");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.healing_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.healing_button, "clicked", G_CALLBACK(Hero_healing), &pointers);

    dialogs.item_button = gtk_button_new_with_label("アイテム");
    gtk_box_pack_start(GTK_BOX(dialogs.hbox), dialogs.item_button, TRUE, TRUE, 0);
    g_signal_connect(dialogs.item_button, "clicked", G_CALLBACK(Hero_item), &pointers);

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
