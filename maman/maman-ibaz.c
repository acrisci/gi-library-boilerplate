#include "maman-ibaz.h"

G_DEFINE_INTERFACE (MamanIbaz, maman_ibaz, G_TYPE_OBJECT);

// properties and signals of the interface are defined here
static void
maman_ibaz_default_init (MamanIbazInterface *iface)
{
    g_object_interface_install_property (iface,
                                       g_param_spec_string ("name", // name
                                                            "Name", // nickname
                                                            "Name of the MamanIbaz", // description
                                                            "maman", // default value
                                                            G_PARAM_READWRITE)); // flags
}

// interface methods dereference the interface structure and call into its members
// (which point to actual implementations)
void
maman_ibaz_do_action (MamanIbaz *self)
{
  g_return_if_fail (MAMAN_IS_IBAZ (self));

  MAMAN_IBAZ_GET_IFACE (self)->do_action (self);
}

void
maman_ibaz_do_something (MamanIbaz *self)
{
  g_return_if_fail (MAMAN_IS_IBAZ (self));

  MAMAN_IBAZ_GET_IFACE (self)->do_something (self);
}
