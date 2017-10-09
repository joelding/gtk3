#include <glib.h>

static gpointer thread_func(gpointer data)
{
	gint n = GPOINTER_TO_INT(data);
	guint cnt = 0;

	while (cnt < 10)
	{
		g_print("thread %d\n", n);
		//g_usleep(1); /* 1us */
		++cnt;
	}

	return NULL;
}

int main(int argc,
	 char *argv[])
{
	GThread *thread[2];
	gint i;

	for (i = 0; i < 2; ++i)
	{
		thread[i] = g_thread_new(NULL, thread_func, GINT_TO_POINTER(i));	
	}

	g_thread_join(thread[0]);
	g_thread_join(thread[1]);
	g_thread_unref(thread[0]);
	g_thread_unref(thread[1]);

	return 0;
}

