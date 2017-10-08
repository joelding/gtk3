#include <glib.h>

static gboolean src_callback(gpointer user_data)
{
	static int count;

	GMainLoop *loop = (GMainLoop *)user_data;

	if (count < 10) 
	{
		g_print("%s %d\n", __func__, count++);
		return TRUE;
	}

	g_main_loop_quit(loop);

	return FALSE; // the source should be removed
}

int main(int argc,
	 char *argv[])
{
	GMainLoop *mloop = g_main_loop_new(NULL, FALSE);
	GSource *src = g_idle_source_new();

	g_print("Start loop!\n");
	g_idle_add(src_callback, mloop);

	g_main_loop_run(mloop);

	g_source_unref(src);	
	g_main_loop_unref(mloop);
	g_print("Exit!\n");
	
	return 0;
}

