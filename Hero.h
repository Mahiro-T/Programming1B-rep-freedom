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

void Hero_power_attack(GtkWidget *entryMainValue, gpointer user_data)
{
}
void Hero_magic_attack(GtkWidget *entryMainValue, gpointer user_data)
{
}
void Hero_healing(GtkWidget *entryMainValue, gpointer user_data)
{
}
void Hero_item(GtkWidget *entryMainValue, gpointer user_data)
{
}