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

## Problem D - Matrix Cascade
### TLDR

Implementation Problem

- Operation on one cell affects other cells , question required to use prefix matrix to keep track of changes that were caused due previous cells , accumulate those changes and perform another operation accordingly


### Description

Operation on one cell initiated a kind of chain reaction from that cell in the shape of a triangle . Thinking about triangle , three movements make a triangle from a point that are downwards , left diagonal and right diagonal. So to solve the problem we created a prefix matrix that holds the count of previous movements in the three directions . On every point we accumulate the prefix and use that information to decide whether to call an operation on the current cell or not.

- prefix created :
~~~
vector<vector<vector<int>>> prefix(n , vector<vector<int>>(n , vector<int>(3 , 0)));
~~~

- Movement that build the traingle
~~~
	   if(i + 1 < n)
	   {
	       if(j - 1 >= 0)
	       {
		   prefix[i + 1][j - 1][0] = prefix[i][j][0];
	       }

	       if(j + 1 < n)
	       {
		   prefix[i + 1][j + 1][2] = prefix[i][j][2];
	       }

	       prefix[i + 1][j][1] = current; 
	   }
~~~
