#include <glib.h>

int main(int argc,
	 char *argv[])
{
	g_print("GLib version: %d.%d.%d\n", 
		GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	/* this can be seen if "export G_MESSAGES_DEBUG=all" */
	g_log(G_LOG_DOMAIN,
	      G_LOG_LEVEL_INFO,
	      "%s\n", argv[0]);

	g_message("%s\n", argv[0]);

	/* g_warning, g_critical prints process ID */
	g_warning("%s\n", argv[0]);
	g_critical("%s\n", argv[0]);

	/* g_error causes application stop */
//	g_error("%s\n", argv[0]);
//
	g_debug("%s\n", argv[0]);

	return 0;
}

