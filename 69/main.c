#include <glib.h>

static gpointer thread_push(gpointer data)
{
	GAsyncQueue *queue = (GAsyncQueue *)data;
	int n = 50, *p;

	while (n > 0) {
		//g_print("%s+\n", __func__);
		//g_async_queue_lock(queue);
		p = g_new0(int, 1);
		*p = n;
		g_print("push %d\n", n);
		g_async_queue_push(queue, p);
		//g_async_queue_unlock(queue);
		--n;
		g_usleep(1);
		//g_print("%s-\n", __func__);
	}

	return NULL;
}

static gpointer thread_pop(gpointer data)
{
	GAsyncQueue *queue = (GAsyncQueue *)data;
	int n = 50, *p;

	while (n > 0) {
		//g_print("%s+\n", __func__);
		//g_async_queue_lock(queue);
		if ((p = g_async_queue_try_pop(queue)))
		{
			g_print("pop %d\n", *(int *)p);
			g_free(p);
			--n;
		}
		//g_async_queue_unlock(queue);
		//g_print("%s-\n", __func__);
	}

	return NULL;
}

int main(int argc,
	 char *argv[])
{
	GThread *thread[2];
	GAsyncQueue *queue = g_async_queue_new();

	thread[0] = g_thread_new(NULL, thread_push, queue);	
	thread[1] = g_thread_new(NULL, thread_pop, queue);	

	g_thread_join(thread[0]);
	g_thread_join(thread[1]);
	g_thread_unref(thread[0]);
	g_thread_unref(thread[1]);
	g_async_queue_unref(queue);

	return 0;
}

