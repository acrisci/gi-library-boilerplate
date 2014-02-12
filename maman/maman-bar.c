#include "maman-bar.h"

struct _MamanBarPrivate
{
  gint hsize;
};

G_DEFINE_TYPE_WITH_PRIVATE (MamanBar, maman_bar, G_TYPE_OBJECT)

static void
maman_bar_class_init (MamanBarClass *klass)
{
}

static void
maman_bar_init (MamanBar *self)
{
  self->priv = maman_bar_get_instance_private (self);
  self->priv->hsize = 42;
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
maman_bar_speak (gchar *words)
{
  gchar *retval;

  retval = g_strdup_printf("'%s', I say.", words);

  return retval;
}
