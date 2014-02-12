# GObject-introspection Library Boilerplate

Just some stuff to get you started on a new library.

## About

This is a complete, minimal example of an introspectable library based on the [GObject reference manual](https://developer.gnome.org/gobject/stable/) example designed to be the basis of a new project.

It notably includes a working [autotools](https://en.wikipedia.org/wiki/GNU_build_system) build system that creates a [gir](https://developer.gnome.org/gi/stable/) and typelib to expose bindings to scripting languages.

## Installing

Run `autogen.sh` to initialize the build system and configure the project. Then run `make` and the project will build in the `maman` directory.

## Using the bindings

To set up a development environment for the bindings, set these environment variables:

```
export GI_TYPELIB_PATH=/path/to/gi-library-boilerplate/maman:$GI_TYPELIB_PATH
export LD_LIBRARY_PATH=/path/to/gi-library-boilerplate/maman/.libs:$LD_LIBRARY_PATH
```

Then with the [PyGObject](https://wiki.gnome.org/action/show/Projects/PyGObject) module available, the library can be accessed like this:

```python
from gi.repository import Maman

# Create a new object
bar = Maman.Bar()

# Say hello to bar
bar.speak('Hello, world!')
```

## License

This work is available under the GNU General Public License (See COPYING).

Copyright © 2014, Tony Crisci

(You can use your own copyright and license of course)
