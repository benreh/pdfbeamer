#!/bin/sh
# gettextize --force --copy
#libtoolize --force --copy
aclocal 
automake --add-missing --force-missing --gnu
autoconf
autoreconf
