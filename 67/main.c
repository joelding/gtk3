#include <glib.h>

static gboolean src_callback(gpointer user_data)
{
	GMainLoop *loop = (GMainLoop *)user_data;
	g_main_loop_quit(loop);

	return FALSE; // the source should be removed
}

int main(int argc,
	 char *argv[])
{
	GMainLoop *mloop = g_main_loop_new(NULL, FALSE);
	GSource *src = g_timeout_source_new_seconds(5);

	g_print("Start loop!\n");
	g_source_set_callback(src,
						  src_callback,
						  mloop, NULL);
	g_source_attach(src, NULL);

	g_main_loop_run(mloop);

	g_source_unref(src);	
	g_main_loop_unref(mloop);
	g_print("Exit!\n");
	
	return 0;
}

