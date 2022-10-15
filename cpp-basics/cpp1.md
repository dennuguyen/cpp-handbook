-------------------
marp: true
theme: black
class: invert
paginate: true
-------------------

# C++

Basic Topics

<!--

What is C++?
    It's a superset of C

    Some people like to think of C++ as C but with classes which lets you use a powerful style of programming called OOP

    But you also get really nice and convenient libraries in C++ that you would've had to write from scratch in C
-->

-------------------
## Learning Outcomes

- Revise data types and learn commonly used C++ data types. 
- Revise variables and implicit conversions. 
- Learn C++ style type casting and its benefits over C-style type casting. 
- Understand use of const keyword and its benefits. 
- Understand type inference, auto keyword, and benefits of using auto. 
- Understand how scope affects life-time of variables. 


-------------------
## Learning Outcomes

- Revise while and for loops. 
- Revise conditional statements. 
- Revise functions and learn trailing-return syntax. 
- Understand how to use default arguments. 
- Understand funtion overloading and when to use it. 
- Identify different kind of errors and can reason cause of error. 
- Know relevant resources for C++ programmers.

-------------------
## Hello World
Differences?

```cpp
#include <stdio.h>
int main() {
    printf("Hello World!");
    return 0;
}
```

```cpp
#include <iostream>
int main() {
    std::cout << "Hello World!";
    return 0;
}
```

<!-- Notes

Differences?
    <stdio.h> vs <iostream>
    printf() vs std::cout <<

Avoid C where you can. There are lot of features C++ will introduce that is a lot safer/better practice over C-style code. This will be covered in future lectures.

-->

-------------------
## Data Types

C has:
```cpp
int    // 4 bytes
float  // 4 bytes
double // 8 bytes
char   // 1 byte
struct // as large as whatever is inside it
```

C++ introduces:
```cpp
bool        // 1 byte
std::string // depends on how long the string is
class       // exactly like struct
```

Remember to initialise your variables!!

<!--

The types you know from C are still there.

But C++ introduces a few new data types:
    bool
    std::string
    class

bool is 1 byte because it's the fundamental addressable unit by the CPU. CPUs address memory by their byte not bit.

analogy:
    a building with 4 floors = 1 byte has 4 bits.

    a byte has an address, a building also has an address.

    The mailman doesn't deliver mail to the floors individually, they deliver to the whole building because all the floors have the same address.

 -->

-------------------
### std::string

Goodbye `char*` and `char[]`.

```cpp
std::string str1 = "this is ";
std::string str2 = "my string";
if (str1 != str2)
    std::cout << str1 + str2 << std::endl;
```

<!-- 

Show string.cpp

Never ever use char pointers or char arrays.

There's no need to malloc unlike a char pointer.

You can directly compare std::strings unlike a char array.

It's also still possible to access strings like an array.

 -->

-------------------
## Variables

Variables have a size, data type, and name.

```cpp
int var1;        // uninitialised variable
if (var1 == 2);  // this will throw a runtime error
```
```cpp
int var2 = 2;    // initialised variable
if (var2 == 2);  // this is okay
```

> A variable is an object or a reference that is not a non-static data member, that is introduced by a declaration.

<!-- 

For the purposes of understanding what variables are. Variables have a size, data type, and name.

I have included the C++ definition of a variable because I want to emphasise that variables are objects and have more parameters than just size, data type, and name.

Good practice:
    Always initialise variables.

    Declare variables close to where you use them. Minimise the lifetime of the variable.

 -->

-------------------
### Const

- Keyword which marks a variable as NOT modifiable.
- Mark everything as const unless you know it will be modified.

```cpp
int const a = 432;  // this is valid
const int b = 234;  // this is also valid

a = 123; // this won't compile
```

Why?
Protection, reasoning, optimisation...

<!-- 

Why const?
    Protect variables from unintended modification. Compiler will throw an error if you try.

    Easier to reason your code if you know this variable hasn't changed.

    Tells other programmers that this variable shouldn't be modified

    Compilers may make some optimisations by not providing storage for variables.
 -->

-------------------
### Implicit Conversion

- Implicit conversions occur when a data type is used in a *context* which expects a *different data type*.
- *Numeric Conversion:* Types may change their values (and CAN lose precision).
- *Numeric Promotion:* Types convert to "larger" types.

```cpp
int x = 0; double y = 2.2; char z = 'a';

int myInt = z;           // What value is myInt?
???? intOrChar = x + z;  // What data type is intOrChar?
???? sum = x + y + z;    // What data type is sum?
```

There are a few more types of conversions...
https://en.cppreference.com/w/cpp/language/implicit_conversion

<!-- 

There's a few types of implicit conversions.
    Focus on numeric and implicit conversions because most relevant/important.

To see all the other types of implicit conversions and their rules, check out the doc.

Go through example.

We can check the ASCII table to see what value myInt is.
    myInt = 97;

Promotion
    types get converted to "larger" types
    char -> int
    int -> unsigned int
    int -> long
    float -> double

myInt is "integral promoted"

intOrChar is also "integral promoted"

Show implicit-conversion.cpp to prove example.

 -->

-------------------
### Explicit Conversion

- You tell the compiler what you want.
- How? By "type casting".
```cpp
double a = 2.2;
int b = a;                    // implicit conversion.
int c = (int)(a);             // explicit C-style type cast.
int d = static_cast<int>(a);  // explicit C++ style type cast.
```

Why?
Safer.

<!-- 

Explicit conversions are like implicit conversions.

Show explicit-type-casting.cpp

Type casts are safer
    Easier to reason your code if you know what data type your variable is.

    You know you're not unintentionally changing a datatype.

    Use C++ style of type casting. More meaningful, easier to find.

    Avoid type casting. Excessive use is a code smell.
 -->


-------------------
### Type Inference

Compiler statically infers `auto` data type based on its assignment.

```cpp
auto i = 0;                 // int
auto j = 4.2;               // double
auto s = "Hello";           // std::string
auto f = std::list<int>();  // std::list<int>
```

Why use `auto`?
```cpp
std::array<std::array<int, 4>, 4> matrix; // 4 x 4 matrix

auto firstRow = matrix[0];

std::array<int, 4> firstRow = matrix[0];
```

Readable, correct, robust, convenient, enforce explicit conversions...

<!-- 
Type inference relies on the RHS to determine the type.

Show type-inference.cpp

Why use auto?
    Can increase readability IF the datatype is extremely long.

    Can increase correctness because you either don't explicitly state its data type or you do it only once.

    Makes code more robust. If code needs to be changed, every explicit data types needs to be updated.

    Auto guarantees no implicit conversions. Enforces explicit type casting.

    It's very convenient. Less typing.

Drawbacks of using auto
    It hides away data types, MAY be harder to reason what datatype a variable is. But if you can't reason what a variable is from its datatype, you probably need to rename your variable.

Good practices:
    Use auto on LHS, infer the types on the RHS
 -->

-------------------

## Scope

Region of code where variable is "visible".

```cpp
int a; // Global scope.

void foo() {
    int b; // Scope only within foo.
}

int main() {
    int c; // Scope only within main.

    {
        int d; // Scope only within {}.
    }
}
```

<!-- 

Attempting to use a variable outside of its scope will throw a compiler error.

 -->

-------------------
## Loops

Counting for loop.
```cpp
for (initialise; condition; increment/decrement)
```

Range-based for loops.
```cpp
for (initialise : range expression)
```

<!-- 

Show loops.cpp.

Do exercise.

Show range-based.cpp

C++ introduces range-based for loops.
    Always prefer this over counting loops.

    This becomes very important when we want to iterate over more complex data types.
 -->

-------------------
## Conditional Statements

If condition is true, skips remaining `else`/`else if` conditions.
If everything fails, do `else`.
```cpp
if (A)
    doSomething();
else if (B)
    doSomething();
else if (C)
    doSomething();
else
    doSomething();
```

<!-- 

C++ does not introduce any new features with conditional statements.

 -->

-------------------
Check all conditions.
```cpp
if (A)
    doSomething();
if (B)
    doSomething();
if (C)
    doSomething();
```

Checks a variable's value.
```cpp
switch(myVar) {
    case 1: doSomething(); break;
    case 2: doSomething(); break;
    default:
}
```

Short-handed expression.
```cpp
std::string str = i % 2 ? "even" : "odd";
```

<!-- 

Switch-case
    break lets us break out of the switch condition, otherwise all expressions afterwards will execute.

Ternary operator
    Should only use for conditional assignments.

    Keep it short and sweet.

Show conditions.cpp

 -->

-------------------
## Functions

```cpp
bool isEven(int const a) {...}

int multiply(int const a, int const b) {...}

int multiplyIfEven(int const a, int const b) {
    if (isEven(a) || isEven(b))
        return multiply(a, b);
    return -1;
}
```

Why?
Reusable, reasonable, readable

<!-- 

Show functions.cpp

Functions are incredibly important, it should be bread and butter
    Makes your code re-usable. You only have to write the logic once and avoids repetition. Could also re-use in future assignments...

    Easier to understand what your is doing if logic is encapsulated.

    Easier to read in general, functions need good names.

Functions should do only one thing and be simple.

What if the function is large?
    Break it up with even smaller functions and call them.
 -->


-------------------
### Function Syntax

What you know.
```cpp
int main() {...}
```

Trailing return type.
```cpp
auto main() -> int {...}
```

Not important for now. Be consistent.

<!-- 

C++ introduces another function syntax.
    Trailing return type lets you use some advanced C++ features like applying type inference to functions.

    It could be more readable because a list of functions will always be aligned.

Doesn't matter which one you use, be consistent.

 -->

-------------------
### Default Arguments

If an argument is not specified, the default argument is used.

```cpp
std::string rgb(int r = 0, int g = 0, b = 0);

rgb();               // rgb(0, 0, 0)
rgb(255);            // rgb(255, 0, 0)
rgb(255, 255);       // rgb(255, 255, 0)
rgb(255, 255, 255);  // rgb(255, 255, 255)
rgb(255, , 255);     // Not valid.
```

- *Formal Parameter*: The input the function is declared with.
- *Actual Parameter*: The variable you pass into a function.

<!-- 

Define what a parameter is:
    Programmers should know these definitions, easier to communicate.

    It is easier to refer to actual parameters as arguments.

 -->

-------------------
### Function Overloading

Functions in the *same scope* with the *same name* but different *parameters* can be *overloaded*.

```cpp
auto doubleNumber(int a) -> int { return a * 2; }
auto doubleNumber(double a) -> double { return a * 2; }
```

Do not overload if the function logic is different.
```cpp
auto operateNumber(int a) -> int { return a + 2; }
auto operateNumber(double a) -> double { return a / 2; }
```

<!-- 

Function overloading can be useful if you want to use the same function name for different data types.

The compiler determines which function to use based on its formal parameter types.

Why?
    Cleaner and more reasonable code.
 -->

-------------------
## Errors

Compile-time errors.
```cpp
int a = 3
```

Link-time errors.
```cpp
void foo();

int main() {
    foo();
}
```

<!-- 

Going through common types of errors.
    Be aware of these errors.
    You will encounter them in the future, understanding category of errors is basis for debugging.

Compile-time errors are caught by the compiler because there's incorrect syntax.

Link-time errors are caught by the linker because there's a missing definition.

 -->

-------------------
## Errors

Run-time errors.
```cpp
std::vector<int> vec = {0,, 1, 2};
for (int i = 0; i < 5; i++) {
    vec[i];
}
```

Programmer errors.
```cpp
int a;
std::cout << a << std::endl;
```

<!-- 

Run-time errors are not caught. You realise there's a run-time error when the program crashes.
    Dangerous and hard to debug.

Programmer errors are when the programmer has made a mistake.
    Typically happens because code is complex.
    Silly mistakes.

 -->

-------------------
## How to be a Better C++ Programmer

[cppreference](https://en.cppreference.com/w/Main_Page)
[stack overflow](https://stackoverflow.com/)
[CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

<!-- 

If you want to do something in C++ but don't know how to do it, google it first.

Use cppreference
    to consult on how to use functions and libraries.

    check if a particular function exists.

    don't use cplusplus

Use stack overflow
    if you have a bug.

    there's a minor problem that someone else probably solved before.

Use cppcoreguidelines
    literally a set of guidelines on what is good and bad style.

    will teach you how to be a better programmer.

 -->