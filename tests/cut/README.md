<a id="top"></a>

<div align="center">
    <h3>CUT</h3>
</div>

---

### Table of Contents

- [Description](#description)
- [Getting Started](#getting-started)
  - [Installation](#installation)
- [Usage](#usage)
  - [Basic usage](#basic-usage)
  - [Initialization](#initialization)
  - [Assertions](#assertions)
  - [Test summary](#test-summary)
- [Contributing](#contributing)
- [License](#license)

---

## Description

CUT (**C** **U**nit **T**esting) is a C library designed to help with program testing.

The library provides easy to use functions that can be called to check what works and what doesn't work in a program.

With its clear and simple output design, the user is able to quickly note was the problems are and can focus on fixing them.

## Getting Started

### Installation

1. Clone the library in the repository of the project you want to test
   ```
   git clone https://github.com/NestorNebula/cut.git
   ```
2. Build the library
   ```
   cd cut
   make
   cd ..
   ```
3. Create a test program using the library (read the [usage section](#usage) for informations on how to use the library)
4. When compiling your program, add the following flags to your compilation command:
   ```
   -Icut/include -Lcut -lcut
   ```
5. Execute your program

## Usage

### Basic usage

The library works by creating a unit test, doing assertions on it and finally printing a summary of the assertions.

### Initialization

For each different thing you want to test, you are encouraged to create a new unit test:

```c
t_unit_test *unit_test;

unit_test = new_unit_test("Test name", false);
```

The first argument is the name of the unit test, the second is a boolean that, if true, will cause the unit test to stop on the first wrong assertion.

### Assertions

To test an assertion on a given unit test, you can use one of the following functions:

```c
cut_assert(true == 1, unit_test, "true has a value of 1");
cut_expect(true == 0, unit_test, "true has a value of 0");
```

The first argument given is the assertion, the second is a unit test instantiated with `new_unit_test` and the third one is a description of the assertion that will be printed in the test output.

The difference between `cut_assert` and `cut_expect` is that `cut_assert` will stop the program (after displaying the test summary) if the assertion is wrong. `cut_expect` will let the program continue in any way.

For comparisons, you can use two other functions that share the same difference than the previous ones, `cut_assert_eq` and `cut_expect_eq`.

Both functions take 6 parameters, the first two being pointers to the values to compare, the third one being the size (in bytes) taken by the two values. The fourth is a a pointer to a function that can compare the values. The fifth and sixth are the same than the last two parameters of `cut_assert` and `cut_expect`.

Comparison functions are provided by the library, but any function having the same prototype will work just as well.

- `cut_cmp_int` for comparing integers
- `cut_cmp_str` for comparing strings 
- `cut_cmp_ptr` for comparing pointers (in that case, the first two arguments of `cut_assert_eq`/`cut_expect_eq` must be the pointers themselves, not pointers to them)
- `cut_cmp_mem` for comparing two portions of memory (can be used for comparing structures)

### Test summary

Once you have finished doing assertions on a unit test (initialized with `new_unit_test`), you should call the following function:

```c
end_unit_test(unit_test);
```

This will print a summary of the unit test's assertions and will free the memory it has taken.

Failing to call this function will cause your testing program to have memory leaks.

## Contributing

The CUT library's goal is to help people test their programs while avoiding any kind of complexity they don't need.

To achieve this goal, the library will be updated regularly, and any help is welcomed.

If you find an issue while using CUT or want to contribute, please <a href="https://github.com/NestorNebula/cut/issues">open an issue</a>.

## License

[![MIT License](https://img.shields.io/badge/License-MIT-darkcyan.svg?style=for-the-badge)](https://github.com/NestorNebula/cut/blob/main/LICENSE)

© Noa Houssier - 2026

<p align='right'>(<a href='#top'>go back to the top</a>)</p>
