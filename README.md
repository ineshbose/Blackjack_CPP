# Blackjack (C++)
[![AppVeyor](https://img.shields.io/appveyor/build/ineshbose/blackjack-cpp?label=AppVeyor&style=flat-square&logo=appveyor)](https://ci.appveyor.com/project/ineshbose/blackjack-cpp)
[![Travis (.org)](https://img.shields.io/travis/ineshbose/blackjack_cpp?label=Travis&style=flat-square&logo=travis-ci)](https://travis-ci.org/github/ineshbose/blackjack_cpp)
[![Codacy grade](https://img.shields.io/codacy/grade/760d6c817b324726898e79ded9aa807e?style=flat-square&logo=codacy)](https://app.codacy.com/manual/ineshbose/Blackjack_CPP)
[![GitHub](https://img.shields.io/github/license/ineshbose/Blackjack_CPP?style=flat-square)](LICENSE)
[![Run on Repl.it](https://img.shields.io/badge/run_on_repl.it--lightgrey?style=flat-square&logo=repl.it)](https://repl.it/github/ineshbose/blackjack_cpp)

Developed in order to repolish my C++ skills and as my first C++ repository. Have had many memories playing blackjack while being drunk with flatmates during the first year of uni.

<img style="display: block; margin-left: auto; margin-right: auto;" alt="Blackjack Demo" src="data/demo.gif" />


## Setup

### Cloning
You should have [Git](https://git-scm.com/) installed and use the following commands in your terminal in your preferred directory
```sh
$ git clone https://github.com/ineshbose/Blackjack_CPP
$ cd Blackjack_CPP
```
else you can download a [ZIP](https://github.com/ineshbose/Blackjack_CPP/archive/master.zip).

### Building / Compiling
There are four options available ordered by recommendation. You should compile the program in the `build` directory.
```sh
$ cd build
```

#### CMake
```sh
$ cmake ..          # generates build configuration (Makefile)
$ cmake --build .   # or `make` to build the executable
$ ./blackjack       # viola!
```

#### Meson
```sh
$ meson ..          # generates build configuration (ninja)
$ ninja             # builds the executable
$ ./blackjack       # viola!
```

#### Make
```sh
$ cd ..             # if you are in the build directory
$ make              # builds executable based on Makefile
$ ./blackjack       # viola!
```

#### g++
```sh
$ cd ..             # if you are in the build directory
$ g++ src/blackjack.cpp src/card.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/player.cpp src/print.cpp src/statistics.cpp -o blackjack
$ ./blackjack       # viola!
```


## Contributing
Any kind of contributions / improvements are greatly appreciated!
* To report any bug, [raise an issue](https://github.com/ineshbose/Blackjack_CPP/issues).
* To make changes to this repository, [create a pull request](https://github.com/ineshbose/Blackjack_CPP/pulls).

All contributors will be thanked and named in the README. 😄