#include "maman-bar.h"

// private members go in this structure
struct _MamanBar
{
  GObject parent_instance;

  gint hsize;
};

// implement MamanBar as a child of GObject
G_DEFINE_TYPE (MamanBar, maman_bar, G_TYPE_OBJECT)

// instance initialization
static void
maman_bar_init (MamanBar *self)
{
  /* initialize all public and private members to reasonable default values.
   * They are all automatically initialized to 0 to begin with. */
  self->hsize = 42;
}

// class initialization
static void
maman_bar_class_init (MamanBarClass *klass)
{
}

/**
 * maman_bar_new:
 *
 * Allocates a new #MamanBar
 *
 * Returns: A new #MamanBar
 *
 */
MamanBar *
maman_bar_new (void)
{
  MamanBar *bar;

  bar = g_object_new(MAMAN_TYPE_BAR, NULL);
  return bar;
}

/**
 * maman_bar_speak:
 * @words: what you want it to say
 *
 * Returns: what the bar actually says
 *
 */
gchar *
maman_bar_speak (MamanBar* self, gchar *words)
{
  gchar *retval;

  retval = g_strdup_printf("'%s', I say.", words);

  return retval;
}
