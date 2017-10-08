#include <glib.h>

int main(int argc,
	 char *argv[])
{
	g_print("GLib version: %d.%d.%d\n", 
		GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
	g_print("%s\n", glib_check_version(2, 50, 3));

	return 0;
}

