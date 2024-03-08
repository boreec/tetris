# Description

This program is an amateur reproduction of the Tetris game made with C++, Qt and OpenGL.

[![video](https://img.youtube.com/vi/kj1cXrnWwcY/0.jpg)](https://www.youtube.com/watch?v=kj1cXrnWwcY)

# Requirements

- Qt >= 6.0.0
- OpenGL
- CMake >= 3.5
- C++14
- [Doxygen](https://www.doxygen.nl/index.html) to build documentation (optional).

# Building/Executing

Steps from cloning the repository to running the game:
```bash
$ git clone https://gitlab.com/boreec/tetris.git
$ cd tetris
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./Tetris
```

From this step, you can generate the documentation:

```bash
$ cd doc
$ make
$ firefox ../../doc/html/index.html
```

