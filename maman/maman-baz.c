#include "maman-ibaz.h"
#include "maman-baz.h"

static void maman_ibaz_interface_init (MamanIbazInterface *iface);

// class private data goes into this structure
typedef struct
{
  gint instance_member;
  gchar *name;
} MamanBazPrivate;

// define MamanBaz as a class that is derived from GObject, has private data and implements IBaz interface
G_DEFINE_TYPE_WITH_CODE (MamanBaz, maman_baz, G_TYPE_OBJECT,
                         G_ADD_PRIVATE (MamanBaz)
                         G_IMPLEMENT_INTERFACE (MAMAN_TYPE_IBAZ,
                                                maman_ibaz_interface_init))

// enum for class properties
enum
{
  PROP_NAME = 1,
  N_PROPERTIES
};

// enum for class signals
enum
{
  SIG_CHANGED,
  N_SIGNALS
};

// array of class signal ids
static guint signals[N_SIGNALS];

// property setter
static void
maman_baz_set_property (GObject      *object,
                        guint         prop_id,
                        const GValue *value,
                        GParamSpec   *pspec)
{
  MamanBaz *baz = MAMAN_BAZ (object);
  MamanBazPrivate *priv = maman_baz_get_instance_private (baz);

  switch (prop_id)
    {
    case PROP_NAME:
      g_free (priv->name);
      priv->name = g_value_dup_string (value);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

// property getter
static void
maman_baz_get_property (GObject    *object,
                        guint       prop_id,
                        GValue     *value,
                        GParamSpec *pspec)
{
  MamanBaz *baz = MAMAN_BAZ (object);
  MamanBazPrivate *priv = maman_baz_get_instance_private (baz);

  switch (prop_id)
    {
    case PROP_NAME:
      g_value_set_string (value, priv->name);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

/* Default implementation for the virtual method. */
static void
maman_baz_do_handle_frob (MamanBaz *self, guint n_frobs)
{
  g_print("This implements a virtual  method handle_frob(): 0x%x", n_frobs);

  // let's also emit a signal
  g_signal_emit(self, signals[SIG_CHANGED], n_frobs);
}

// class initialization: we
// a) link parent class virtual method pointers to our reimplementations of them
// b) link virtual method pointers to our implementations of them
// c) declare that we provide an implementation of "name" property
// d) declare that we provide a signal called "changed"
static void
maman_baz_class_init (MamanBazClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->set_property = maman_baz_set_property;
  object_class->get_property = maman_baz_get_property;

  g_object_class_override_property (object_class, PROP_NAME, "name");

  klass->handle_frob = maman_baz_do_handle_frob;

  signals[SIG_CHANGED] =
    g_signal_new ("changed",
                 G_TYPE_FROM_CLASS (object_class),
                 G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
                 0 /* closure */,
                 NULL /* accumulator */,
                 NULL /* accumulator data */,
                 NULL /* C marshaller */,
                 G_TYPE_NONE /* return_type */,
                 1     /* n_params */,
                 G_TYPE_UINT  /* param_types */);
}

// implementations of the IBaz interface methods
static void
maman_baz_do_action (MamanIbaz *self)
{
  MamanBazPrivate *priv = maman_baz_get_instance_private (MAMAN_BAZ(self));
  g_print ("Baz implementation of Ibaz interface Action: 0x%x.\n",
           priv->instance_member);
}

static void
maman_baz_do_something (MamanIbaz *self)
{
  MamanBazPrivate *priv = maman_baz_get_instance_private (MAMAN_BAZ(self));
  g_print ("Baz implementation of Ibaz interface Something: 0x%x.\n",
           priv->instance_member);
}

// Link interface methods to our implementations of them
static void
maman_ibaz_interface_init (MamanIbazInterface *iface)
{
  iface->do_action = maman_baz_do_action;
  iface->do_something = maman_baz_do_something;
}

// initialize private data
static void
maman_baz_init (MamanBaz *self)
{
  MamanBazPrivate *priv = maman_baz_get_instance_private (self);

  priv->instance_member = 0xdecafbad;
}


