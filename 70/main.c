#include <glib.h>

static GCond cond;
static GMutex mutex;
static gpointer pdata = NULL;

static gpointer thread_func0(gpointer data)
{
	g_print("%s\n", __func__);
	g_mutex_lock(&mutex);
	while (!pdata)
		g_cond_wait(&cond, &mutex);

	g_print("get %d\n", *(int *)pdata);
	g_free(pdata);
	pdata = NULL;
	g_mutex_unlock(&mutex);

	return NULL;
}

static gpointer thread_func1(gpointer data)
{
	int *p;

	g_print("%s\n", __func__);
	g_mutex_lock(&mutex);

	p = g_new(int, 1);
	*p = 38;
	pdata = p;
	g_cond_signal(&cond);
	g_print("send %d\n", *p);
	g_mutex_unlock(&mutex);

	return NULL;
}

int main(int argc,
	 char *argv[])
{
	GThread *thread[2];

	g_cond_init(&cond);
	g_mutex_init(&mutex);

	thread[0] = g_thread_new(NULL, thread_func0, NULL);	
	thread[1] = g_thread_new(NULL, thread_func1, NULL);	

	g_thread_join(thread[0]);
	g_thread_join(thread[1]);
	g_thread_unref(thread[0]);
	g_thread_unref(thread[1]);

	return 0;
}

