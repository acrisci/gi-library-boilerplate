/* inclusion guard */
#ifndef __MAMAN_BAZ_H__
#define __MAMAN_BAZ_H__

#include <glib-object.h>
/*
 * Potentially, include other headers on which this header depends.
 */

G_BEGIN_DECLS

/*
 * Type declaration. MamanBaz is a class that can be derived from.
 */
#define MAMAN_TYPE_BAZ maman_baz_get_type ()
G_DECLARE_DERIVABLE_TYPE (MamanBaz, maman_baz, MAMAN, BAZ, GObject)

struct _MamanBazClass
{
  GObjectClass parent_class;

  /* Class virtual methods fields. */
  void (* handle_frob)  (MamanBaz *bar,
                         guint     n_frobs);

};

//Accessor functions for virtual methods.
void maman_baz_handle_frob (MamanBaz *self, guint n_frobs);

/*
 * Method definitions.
 */
MamanBaz *maman_baz_new (void);

G_END_DECLS

#endif /* __MAMAN_BAZ_H__ */
