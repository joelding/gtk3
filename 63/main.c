#include <glib.h>

int main(int argc, 
		 char *argv[])
{
	int i, *ps32= g_new(int, 10);

	for (i = 0; i < 10; ++i)
		*(ps32 + i) = 3257 + i;

	for (i = 0; i < 10; ++i)
		g_print("*ps32[%d]=%d\n", i, *(ps32 + i));

	g_free(ps32);

	return 0;
}
