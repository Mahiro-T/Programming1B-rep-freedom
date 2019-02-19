# **Programming1B-rep-freedom**

｢ドラクエのような戦闘処理を行う｣というプログラムに｢GTK3+｣を用いて､GUIをつけたものとなっています｡

### **遊び方**

あなたは主人公となって現れた敵と戦います｡
あなたが実行できるのは 

｢攻撃｣ ｢魔法｣ ｢回復｣ ｢アイテム｣

の4つです｡

### **コンパイル方法**
このファイルをコンパイルするにあたってはGTK+3.0が必要です｡

以下にUbuntu上でのインストール方法を記載します｡

まずは

`sudo apt-get install libgtk-3-dev`

コマンドを実行し､GTK+3.0をインストールします｡

`
pkg-config --cflags gtk+-3.0
`

を実行し､


`-pthread -I/usr/include/gtk-3.0 -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/freetype2 -I/usr/include/pixman-1 -I/usr/include/libpng12
`

と表示されれば完了です｡

コンパイルには

`gcc ファイル名 $(pkg-config --cflags --libs gtk+-3.0)`

と入力してください｡
