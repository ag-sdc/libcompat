# libcompat

A minimal compatibility library originally extracted from `btrfs-progs`'s common compatibility files (`compat.h` and `compat.c`).
It provides common stubs, wrappers, and polyfills for missing functions across different environments, specifically tailored to aid in Android cross-compilation where certain GNU extensions or POSIX functions might be missing from the Bionic libc.

## Build Instructions
Can be built using either Autotools or CMake.

### Autotools
```bash
./autogen.sh
./configure --prefix=/usr
make
make install
```

### CMake
```bash
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make
make install
```

## License
This project is licensed under the GNU General Public License v2.0 (GPLv2).
