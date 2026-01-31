# Trigonometry Library

A C++ library for trigonometric functions.

## Files

- `trignometry.h`: Header file with function declarations
- `trignometry.cpp`: Implementation of the trigonometric functions
- `test_trig.cpp`: Example usage and testing

## Functions

### Trigonometric Functions (input in radians)
- `double sine(double angle)`: Returns sin(angle)
- `double cosine(double angle)`: Returns cos(angle)
- `double tangent(double angle)`: Returns tan(angle)

### Conversion Functions
- `double degrees_to_radians(double degrees)`: Converts degrees to radians
- `double radians_to_degrees(double radians)`: Converts radians to degrees

## Compilation

To compile the library and test:

```bash
g++ -c trignometry.cpp -o trignometry.o
g++ test_trig.cpp trignometry.o -o test_trig
./test_trig
```

## Usage

Include the header in your code:

```cpp
#include "trignometry.h"
```

All trigonometric functions expect angles in radians. Use the conversion functions if needed.

## Error Handling

Inverse functions throw `std::invalid_argument` for out-of-range inputs.