#include "stdlib.h"
#include "time.h"
#include <gtk/gtk.h>
#include <Monster.h>
#include <structs.h>
#include <GTK_tools.h>

void change_battle_message(void *d, char message[])
{
    Pointer_Addres *k = d;
}

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