#include <gtk/gtk.h>

void button_clicked(GtkWidget *button, gpointer data)
{
	g_print("Press:%s\n", (char *)data);
}

int main(int argc, char *argv[]) 
{
	GtkWidget *window, *button;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello！GTK+！");
	button = gtk_button_new_with_label("Press");
	gtk_container_add(GTK_CONTAINER(window), button);

	g_signal_connect(G_OBJECT(window), "destroy",
			 G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(button), "clicked",
			 G_CALLBACK(button_clicked), "Hello! Button");

	gtk_widget_show_all(window);
//	gtk_widget_show(window);
//	gtk_widget_show(button);
	gtk_main();

	return 0;
}
