/* inclusion guard */
#ifndef __MAMAN_BAR_H__
#define __MAMAN_BAR_H__

#include <glib-object.h>

// Declare MamanBar as a final (non-derivable) class inherited from GObject
#define MAMAN_TYPE_BAR maman_bar_get_type ()
G_DECLARE_FINAL_TYPE (MamanBar, maman_bar, MAMAN, BAR, GObject)

// constructor
MamanBar * maman_bar_new (void);

/*
 * MamanBar method declarations.
 */

gchar * maman_bar_speak (MamanBar* self, gchar *words);

#endif /* __MAMAN_BAR_H__ */
