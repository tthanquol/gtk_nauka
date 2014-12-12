#include <stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
GtkWidget *MainWindow; //referencja do widżetu okna głownego
GtkWidget *MainContainer; //referencja do "pojemnika na przycisk
GtkWidget *Btn_Zamknij; //referencja do przycisku
gtk_init(&argc, &argv); //zainicjowanie GTK+ i przekazanie parametrów uruchomieniowych programu

MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //utworzenie okna programu z dekoracjami i domyślnym rozmiarem (200x200)
gtk_window_set_default_size(GTK_WINDOW(MainWindow),400,200); //ustawienie rozmiaru okna
gtk_window_set_position(GTK_WINDOW(MainWindow),GTK_WIN_POS_CENTER); //ustawinie okna na środku ekranu
gtk_window_set_title(GTK_WINDOW(MainWindow),"Nauka GTK+"); //ustawianie tytułu okna

MainContainer = gtk_fixed_new(); //tworzenie "pojemnika" fixed
gtk_container_add(GTK_CONTAINER(MainWindow),MainContainer); //umieszczenie pojemnika w oknie głównym

Btn_Zamknij = gtk_button_new_with_label("Zamknij"); //tworzenie przycisku
gtk_widget_set_size_request(Btn_Zamknij,120,50); //nadawania rozmiaru dla przyciski
gtk_fixed_put(GTK_FIXED(MainContainer),Btn_Zamknij,270,140); //dodanie przycisku do kontenera i ustalanie jego pozycji

g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL); //zakończenie procesu w przypadku zamknięcia okna
//g_signal_connect(G_OBJECT(MainWindow),)
gtk_widget_show_all(MainWindow); //wyświetlenie okna programu
gtk_main(); //uruchomienie pętli głównej


  return 0;
}
