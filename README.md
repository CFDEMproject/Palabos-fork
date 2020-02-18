# Fork Information

This is a fork of https://gitlab.com/unigespc/palabos. Its purpose is to preserve the state of Palabos with which the [Aspherix-Palabos](https://github.com/CFDEMproject/Aspherix-Palabos) coupling example is developed.

Everything below this line is the original README.md from the UNIGE repository.

# Palabos

[Palabos](https://palabos.unige.ch/) is an open-source CFD solver based on the [lattice Boltzmann method](https://palabos.unige.ch/lattice-boltzmann/what-lattice-boltzmann/). 
On this page you can download the source code, [access examples](https://gitlab.com/unigespc/palabos/tree/master/examples) and resources, 
and [interact with the user base](http://palabos-forum.unige.ch/).

# Installation

Palabos is very easy to install since it does not depend on any external dependencies.
All the following commands are used for Linux installation. The windows instructions
will be added soon.

## Prerequisites

The mandatory packages are the following:

- A modern C++ compiler `gcc` or `clang`
- `make`
- `python3` for the current version of Palabos.

### For Debian based distributions

```
$ sudo apt install gcc clang python3 make
```

### For Arch based distributions

```
$ sudo pacman -S gcc clang python make
```

The optional but recommended packages are the following:

- `libopenmpi`, by default all the examples use MPI.
- `imagemagick`, some examples output `.gif` which are generated by calling `convert`.

### For Debian based distributions

```
$ sudo apt install libopenmpi-dev
```

### For Arch based distributions

```
$ sudo pacman -S openmpi 
```
  
The majority of the output of Palabos is under the form of `VTK` files. We recommend the use
of [Paraview](https://www.paraview.org/) for their visualization.

## The installation steps

For nightly `Palabos` clone this repo

```
git clone https://gitlab.com/unigespc/palabos.git
```

or for stable releases download the appropriate version
from [this link](https://gitlab.com/unigespc/palabos/-/tags).
If you downloaded `palabos-v2.1r0.tar.gz` (the version 2.1 of Palabos) you
can extract the files from the archive with

```
$ tar xzvf palabos-v2.1r0.tar.gz
```

Congratulations. You should now have a functioning version of Palabos.
Assuming `palabos` is the directory where the Palabos source is located,
you can check your installation by typing the following commands

```
$ cd palabos/examples/showCases/cavity2d
$ make
$ ./cavity2d
```

If your installation is fully functional this should generate the following output:

```
$ ./cavity2d
step 0; t=0; av energy=3.81587645e-07; av rho=1
Time spent during previous iteration: 0
step 1280; t=0.1; av energy=1.143114423e-06; av rho=0.9999958713
Time spent during previous iteration: 0.000729634
Saving Gif ...

step 2560; t=0.2; av energy=1.464417219e-06; av rho=0.999991746
```

# Compile an example


Once you have an installation we assume that you are located in your Palabos
installation directory (see above).
To compile an example, `boussinesqThermal3d` in this case, do the following commands

```
$ cd examples/showCases/boussinesqThermal3d
$ make
```

These commands should generate the `boussinesqThermal3d` executable.
If you have a functioning MPI installation you can run it on 4 cores for example
using the command

```
$ mpirun -np 4 ./boussinesqThermal3d 10000
```

The output should look like

```
$ mpirun -np 4 ./boussinesqThermal3d 10000
10000 1
time elapsed for rayleighBenardSetup:0.0661382
0 : Writing VTK.
0 : Writing gif.


average=1.00251; stdDev/average=0.0719342
average=0.999835; stdDev/average=0.0373279
3.33333 : Writing VTK.
```

# Documentation

The documentation of Palabos can be found following this [link](http://www.palabos.org/documentation/userguide/).

# Getting help

If you need help with Palabos, or with the lattice Boltzmann method theory, please use the [Palabos forum](http://palabos-forum.unige.ch/).
<!-- There is also a [matrix room](https://matrix.to/#/!MCMTEdGiUEycWSngZU:matrix.org?via=matrix.org)
where you can discuss things. -->

# Bug reports

When you think you have identified a bug, please open an issue and do not forget to give as many details as possible for us to be able to
reproduce the bug.

# Contributing

To see how to open issues, submit bug reports, create feature requests, submit your additions to the Palabos library, see the [Contributing](https://gitlab.com/unigespc/palabos/blob/master/CONTRIBUTING.md) page.
