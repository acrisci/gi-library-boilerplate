# GObject-introspection Library Boilerplate

Just some stuff to get you started on a new library.

## About

This is a complete, minimal example of an introspectable library based on the [GObject reference manual](https://developer.gnome.org/gobject/stable/) example designed to be the basis of a new project.

It notably includes a working [autotools](https://en.wikipedia.org/wiki/GNU_build_system) build system that creates a [gir](https://developer.gnome.org/gi/stable/) and typelib to expose bindings to scripting languages.

For a complete explanation of this project, see the [blog post](http://dubstepdish.com/blog/2014/02/12/gobject-introspection-build-system-example/) I wrote about it.

## Source code

This project contains three definitions:

1) A simple class called MamanBar that is final (i.e. cannot be derived
from) and has one public method and some internal state.

2) A non-instantiable interface called MamanIbaz which specifies two methods and one
property.

3) A derivable (can be subclassed) class called MamanBaz which
implements the above interface, and also adds a virtual method and a signal.

## Installing

Run `autogen.sh` to initialize the build system and configure the project. Then run `make` and the project will build in the `maman` directory.

## Using the bindings

To set up a development environment for the bindings, set these environment variables:

```sh
export GI_TYPELIB_PATH=/path/to/gi-library-boilerplate/maman:$GI_TYPELIB_PATH
export LD_LIBRARY_PATH=/path/to/gi-library-boilerplate/maman/.libs:$LD_LIBRARY_PATH
```

Then with the [PyGObject](https://wiki.gnome.org/action/show/Projects/PyGObject) module available, the library can be accessed like this:

```python
#!/usr/bin/env python3

from gi.repository import Maman

# Create a new object
bar = Maman.Bar()

# Say hello to bar
words = bar.speak('Hello, world!')

print(words)

# Ibaz is an interface which cannot be instantiated
# ibaz = Maman.Ibaz()
# NotImplementedError: Ibaz can not be constructed


# But we can instantiate an implementation of it
baz = Maman.Baz()

# And call methods that are defined  in the interface
baz.do_action()

# And also set and get properties
baz.set_property("name","papan")
print (baz.get_property("name"))

# Connect to a signal
baz.connect("changed",lambda baz, frobs: print ("signal received from %s: %d" % (baz, frobs)))

# And make a call that will trigger the signal:
# signal received from <Baz object at 0x7f41a121f1f8 (MamanBaz at 0x26376d0)>: 42
baz.handle_frob(42)

```

## License

This work is available under the GNU General Public License (See COPYING).

Copyright © 2014, Tony Crisci

(You can use your own copyright and license of course)
