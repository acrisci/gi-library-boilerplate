/*
 * Copyright/Licensing information.
 */

/* inclusion guard */
#ifndef __MAMAN_BAR_H__
#define __MAMAN_BAR_H__

#include <glib-object.h>
/*
 * Potentially, include other headers on which this header depends.
 */

/**
  * SECTION: maman-bar
  * @short_description: A minimal and complete GI library.
  *
  * The #MamanBar teaches you how to make a GObject-introspection library.
  *
  */

/*
 * Type macros.
 */
#define MAMAN_TYPE_BAR                  (maman_bar_get_type ())
#define MAMAN_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), MAMAN_TYPE_BAR, MamanBar))
#define MAMAN_IS_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MAMAN_TYPE_BAR))
#define MAMAN_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), MAMAN_TYPE_BAR, MamanBarClass))
#define MAMAN_IS_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), MAMAN_TYPE_BAR))
#define MAMAN_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), MAMAN_TYPE_BAR, MamanBarClass))

typedef struct _MamanBar        MamanBar;
typedef struct _MamanBarClass   MamanBarClass;
typedef struct _MamanBarPrivate MamanBarPrivate;

struct _MamanBar
{
  /* Parent instance structure */
  GObject parent_instance;

  /* private member */
  MamanBarPrivate *priv;

  /* instance members */
};

struct _MamanBarClass
{
  /* Parent class structure */
  GObjectClass parent_class;

  /* class members */
};

/* used by MAMAN_TYPE_BAR */
GType maman_bar_get_type (void);

MamanBar * maman_bar_new (void);

/*
 * Method definitions.
 */

gchar * maman_bar_speak (gchar *words);

#endif /* __MAMAN_BAR_H__ */
