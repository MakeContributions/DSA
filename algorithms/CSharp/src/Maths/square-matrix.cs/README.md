# <SQUARE MATRIX    >

< description of the problem >
This problem does the addition the diagonals in a square matrix and then, it does the difference of both in absolute value. For example:
We have the next square matrix:

1 4 5 6
2 3 4 5
1 2 3 4
7 4 8 9

The first addition is for the diagonal from the left-to-right corner:
- 1 + 3 + 3 + 9 = 16

The second addition is from the right-to-left corner diagonal:
- 6 + 4 + 2 + 7 = 19

So, the difference of both diagonals in absolute value is:
|16-19| = 3

## Prerequisites

- No prerequisites needed.

## Instructions

- instructions to run the project
- < The project is made using C#, so the comands form run it is: >
1º You have to be in the next directory:
```bash
    cd .\GitHub\DSA\algorithms\CSharp\src\Maths\
```
2º Then, to run the console app:

```bash
    dotnet run
```

## Test Cases & Output < if exists>

< This testcases code covers a variety of test cases, including arrays with positive and negative numbers, arrays with a single element and empty arrays.

The testcase is save in:

*.\algorithms\CSharp\test\Maths\square-matrix-test.cs*

To run the unit tests, you can use the following command:
```bash
    nunit Algorithms.Maths.Tests.dll
```

If all tests pass, you will see a message like the following:

Tests passed: 5.
If any of the tests fail, you will see a message like the following:

Tests failed: 1. >