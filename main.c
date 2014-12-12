#include <stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
GtkWidget *MainWindow; //referencja do widżetu okna głownego
GtkWidget *vBox;     //referencja do verticalboxa

GtkWidget *menu_container; //referencja do paska na menu

GtkWidget *menu_plik; //referencja do menu_plik
GtkWidget *plik; //referencja do pozycji menu w menu_plik
GtkWidget *nowy; //referencja do pozycji Nowy w menu_plik
GtkWidget *exit; //referencja do pozycji wyjdz w menu_plik



gtk_init(&argc, &argv); //zainicjowanie GTK+ i przekazanie parametrów uruchomieniowych programu
//okno główne
MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //utworzenie okna programu z dekoracjami i domyślnym rozmiarem (200x200)
gtk_window_set_default_size(GTK_WINDOW(MainWindow),400,200); //ustawienie rozmiaru okna
gtk_window_set_position(GTK_WINDOW(MainWindow),GTK_WIN_POS_CENTER); //ustawinie okna na środku ekranu
gtk_window_set_title(GTK_WINDOW(MainWindow),"Nauka GTK+"); //ustawianie tytułu okna

vBox = gtk_vbox_new(FALSE,0); //utworzenie kontenera typu vbox
gtk_container_add(GTK_CONTAINER(MainWindow),vBox); //umieszczenie vboxa w oknie głównym

menu_container = gtk_menu_bar_new();
menu_plik = gtk_menu_new();

plik = gtk_menu_item_new_with_mnemonic("_Plik");

exit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT,NULL);
gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM(exit),TRUE);

nowy = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW,NULL);
gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM(nowy),TRUE);

gtk_menu_item_set_submenu(GTK_MENU_ITEM(plik),menu_plik);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_plik),nowy);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_plik),exit);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_container),plik);
gtk_box_pack_start(GTK_BOX(vBox),menu_container,FALSE,FALSE,0);


g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL); //zakończenie procesu w przypadku zamknięcia okna
//g_signal_connect(G_OBJECT(MainWindow),)
gtk_widget_show_all(MainWindow); //wyświetlenie okna programu
gtk_main(); //uruchomienie pętli głównej


  return 0;
}
