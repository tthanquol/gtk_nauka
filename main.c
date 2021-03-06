#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
void show_info(GtkWidget *widget, gpointer okno)
{
GtkWidget *dw_Info = gtk_about_dialog_new();
//GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("GTK_icon.png", NULL);

gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dw_Info), "Nauka GTK+");
//gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG(dw_Info),pixbuf);
gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dw_Info), "0.1");
gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dw_Info), "(c) Tomasz \"tete\" W.");
gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dw_Info), "Program trenażer do nauki tworzenia okien GTK+");
gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dw_Info), "https://github.com/tthanquol/gtk_nauka");
gtk_window_set_title(GTK_WINDOW(dw_Info), "O programie");

//g_object_unref(pixbuf), pixbuf = NULL;
gtk_dialog_run(GTK_DIALOG(dw_Info));
gtk_widget_destroy(dw_Info);
}

void open_file_dialog(GtkWidget *widget, gpointer okno)
{
    GtkWidget *dialog;

    dialog = gtk_file_chooser_dialog_new (
    "Otwórz...",
    GTK_WINDOW(okno),
    GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
    NULL);

//    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
//    {
//        char *nazwa_pliku;
//
//        nazwa_pliku = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
//        //gtk_label_set_text(GTK_LABEL(etykieta), nazwa_pliku);
//        g_free (nazwa_pliku);
//    }
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{
GtkWidget *MainWindow; //referencja do widżetu okna głownego
GtkWidget *vBox;     //referencja do verticalboxa

GtkWidget *menu_container; //referencja do paska na menu

GtkWidget *menu_plik; //referencja do menu_plik
GtkWidget *plik; //referencja do pozycji menu w menu_plik
GtkWidget *nowy; //referencja do pozycji Nowy w menu_plik
GtkWidget *separator;
GtkWidget *exit; //referencja do pozycji wyjdz w menu_plik

GtkWidget *menu_pomoc;
GtkWidget *pomoc;
GtkWidget *o_programie;

GtkAccelGroup *akceleratory;

GtkWidget *wallpaper;

gtk_init(&argc, &argv); //zainicjowanie GTK+ i przekazanie parametrów uruchomieniowych programu
//okno główne
MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //utworzenie okna programu z dekoracjami i domyślnym rozmiarem (200x200)
//gtk_window_set_default_size(GTK_WINDOW(MainWindow),400,200); //ustawienie rozmiaru okna
gtk_window_set_position(GTK_WINDOW(MainWindow),GTK_WIN_POS_CENTER); //ustawinie okna na środku ekranu
gtk_window_set_title(GTK_WINDOW(MainWindow),"Nauka GTK+"); //ustawianie tytułu okna
gtk_window_set_resizable(GTK_WINDOW(MainWindow), FALSE);

vBox = gtk_vbox_new(FALSE,0); //utworzenie kontenera typu vbox
gtk_container_add(GTK_CONTAINER(MainWindow),vBox); //umieszczenie vboxa w oknie głównym


menu_container = gtk_menu_bar_new(); //stworzenie paska dla menu

menu_plik = gtk_menu_new(); //stworzenie menu "plik"
menu_pomoc = gtk_menu_new(); //stworzenie menu pomoc

akceleratory = gtk_accel_group_new(); //utworzenie grupy akceleratorów
gtk_window_add_accel_group(GTK_WINDOW(MainWindow), akceleratory); //dodanie grupy akceleratorów do okna głównego

plik = gtk_menu_item_new_with_mnemonic("_Plik"); //stworzenie pozycji głownej dla menu plik

nowy = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW,NULL);//stworzenie pozycji nowy dla menu plik (z predefiniowanych etykiet)
gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM(nowy),TRUE);
gtk_widget_add_accelerator(nowy, "activate",akceleratory, GDK_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

separator = gtk_separator_menu_item_new(); //stworzenie separatora

exit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT,NULL);//stworzenie pozycji wyjdz dla menu plik (z predefiniowanych etykiet)
gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM(exit),TRUE);//wymuszenie pokazywania obrazków dla pozycji menu
gtk_widget_add_accelerator(exit, "activate",akceleratory, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); //podpięcie akceleratora CTRL+q dla pozycji wyjdż

gtk_menu_item_set_submenu(GTK_MENU_ITEM(plik),menu_plik); //przypisanie pozycji plik do menu plik
gtk_menu_shell_append(GTK_MENU_SHELL(menu_plik),nowy); //dodanie pozycji nowy do menu plik
gtk_menu_shell_append(GTK_MENU_SHELL(menu_plik), separator);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_plik),exit); //dpdanie pozycji wyjdz do menu plik
gtk_menu_shell_append(GTK_MENU_SHELL(menu_container),plik); //dodanie menu plik do paska menu

pomoc = gtk_menu_item_new_with_mnemonic("P_omoc"); //stworzenie pozycji głownej dla menu pomoc

o_programie =gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT,NULL);
gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM(o_programie),TRUE);
gtk_widget_add_accelerator(o_programie, "activate",akceleratory, GDK_i, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);



gtk_menu_item_set_submenu(GTK_MENU_ITEM(pomoc),menu_pomoc);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_pomoc),o_programie);
gtk_menu_shell_append(GTK_MENU_SHELL(menu_container),pomoc);


gtk_box_pack_start(GTK_BOX(vBox),menu_container,FALSE,FALSE,0); //dodanie paska menu do kontenera vbox
wallpaper = gtk_image_new_from_file("hello_world.jpg");
gtk_box_pack_start(GTK_BOX(vBox),wallpaper,FALSE,FALSE,5);

g_signal_connect(G_OBJECT(nowy),"activate", G_CALLBACK(open_file_dialog),(gpointer)MainWindow);
g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL); //zakończenie procesu w przypadku zamknięcia okna
g_signal_connect(G_OBJECT(exit),"activate", G_CALLBACK(gtk_main_quit),NULL);
g_signal_connect(G_OBJECT(o_programie),"activate", G_CALLBACK(show_info),(gpointer)MainWindow);

//g_signal_connect(G_OBJECT(MainWindow),)
gtk_widget_show_all(MainWindow); //wyświetlenie okna programu
gtk_main(); //uruchomienie pętli głównej


  return 0;
}


