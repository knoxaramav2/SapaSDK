# Sapa SDK

This library is used for developing SAPA models. Providing base formulas and structures, custom variations on the base implementation may be extended and use with the SimCore library to construct runtime simulators.

## Formulas and Constants
Most calculations and values utilize verbatim and derivatives of the Hodgekin-Huxley model, as well as some of the Boltzman equations. 

Note that constants defined in neuralMath.h and hh_const.h are subject to change in the future to non-compile time configuration.

### Variable definitions
* Ion probabilities
    * n - Potassium activation
    * m - Sodium activation
    * h - Sodium de-activation
* Boltzmann equations
    * α - Gate opening flux
    * ß - Gate closing flux

### Constants

