#include <glib.h>

int main(int argc, 
		 char *argv[])
{
	g_print("sizeof(gboolean):%lu\n", sizeof(gboolean));
	g_print("sizeof(gpointer):%lu\n", sizeof(gpointer));
	g_print("sizeof(gconstpointer):%lu\n", sizeof(gconstpointer));
	g_print("sizeof(gchar):%lu\n", sizeof(gchar));
	g_print("sizeof(gshort):%lu\n", sizeof(gshort));
	g_print("sizeof(glong):%lu\n", sizeof(glong));
	g_print("sizeof(gfloat):%lu\n", sizeof(gfloat));
	g_print("sizeof(gdouble):%lu\n", sizeof(gdouble));
	g_print("sizeof(guint8):%lu\n", sizeof(guint8));
	g_print("sizeof(guint16):%lu\n", sizeof(guint16));
	g_print("sizeof(guint32):%lu\n", sizeof(guint32));
#ifdef G_HAVE_GINT64
	g_print("sizeof(guint64):%lu\n", sizeof(guint64));
#endif
	
	return 0;
}
