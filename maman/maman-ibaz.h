#ifndef __MAMAN_IBAZ_H__
#define __MAMAN_IBAZ_H__

#include <glib-object.h>

G_BEGIN_DECLS

// Declare an interface that is derived from GObject
#define MAMAN_TYPE_IBAZ maman_ibaz_get_type ()
G_DECLARE_INTERFACE (MamanIbaz, maman_ibaz, MAMAN, IBAZ, GObject)

// Declare which methods the interface implementations should provide
struct _MamanIbazInterface
{
  GTypeInterface parent_iface;

  void (*do_action) (MamanIbaz *self);
  void (*do_something) (MamanIbaz *self);
};

// These functions are used to call the interface methods
void maman_ibaz_do_action    (MamanIbaz *self);
void maman_ibaz_do_something (MamanIbaz *self);

G_END_DECLS

#endif /* __MAMAN_IBAZ_H__ */
