MOOSE L-PBF
=====

A MOOSE implementation of code that models the Laser Powder Bed Fusion process.

To run, clone the repo and run `make` on your machine. Requires a valid Python > 3.6, gcc and Make.

This is a WIP. It is anticipated to model the physics using nodal continuous and discontinuous Finite Element method simultaneously.

## Structure

- Benchmarks: Benchmarking Cases of various numerical schemes in different settings, to determine optimal choices for different kernels
- Code: Actual model code
- Test: Tests for custom kernels

## ToDo

- [ ] Multiphase
- [ ] Domain
- [ ] Domain segmentation
- [ ] BCs
- [ ] ICs
- [ ] Kernels

"Fork lpbf" to create a new MOOSE-based application.

For more information see: [http://mooseframework.org/create-an-app/](http://mooseframework.org/create-an-app/)
