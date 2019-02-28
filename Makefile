MAKEFILE_DIR := $(CURDIR)
GTK_pass := `pkg-config --cflags --libs gtk+-3.0`

build: 	Main.o Monster.o Hero.o GTK.o
		gcc  Monster_command.o Main.o Hero_command.o GTK.o -I $(MAKEFILE_DIR) -I $(GTK_pass)

Main.o:	Main.c
		gcc -c Main.c -I $(MAKEFILE_DIR) -I $(GTK_pass) 

Monster.o:	Hero_command.c
			gcc -c Hero_command.c -I $(MAKEFILE_DIR) -I $(GTK_pass)

Hero.o:	Monster_command.c
		gcc -c Monster_command.c -I $(MAKEFILE_DIR) -I $(GTK_pass)

GTK.o:	GTK.c
		gcc -c GTK.c -I $(MAKEFILE_DIR) -I $(GTK_pass)

clean:	Monster_command.o Main.o Hero_command.o GTK.o
		rm -f Monster_command.o Main.o Hero_command.o GTK.o
