# HarbourSpace (Div1 + Div2)

## Problem C - Divisor Chain
### TLDR

Number theory involved

- A number is always divisible by the least significant bit that is set in the binary representation of the number , find that number using :-

~~~
x &= (-x)
~~~

### Description

A number is always divisible by the least significant bit that is set in the binary representation of the number , adding the number formed by the least significant set bit to itself multiple times generates all combination of bits that are to the left of the lsb and all right bits remain zero , hence during this generation of numbers we will come across all numbers that are divisible by the lsb
