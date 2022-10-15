-------------------
marp: true
theme: black
class: invert
paginate: true
-------------------

# MTRNSoc C++ Workshop

By Dan

---

## Attendance

<centre><img src="attendance.png" alt="attendance" width="30%"></centre>

---

## Overview

1. Constructors.
1. Vectors
1. Pointers & Iterators.
1. STL Algorithms.
1. Sets
1. Maps

Some theory and some questions.

---

## Constructors

Constructors are functions which instantiate an object.

```cpp
class Vector;

int main() {
    Vector v; // Instantiate an object called v of type Vector.
}
```

<!-- 

The job of the constructor is to initialise an object with the values you want it to have initially.

Constructors are always called when an object gets instantiated.
    It has the same name as the class.
    It does not return anything.

 -->

---

### Different Types of Constructors

```cpp
class Vector {
    Vector();                          // Default constructor.
    Vector(int);                       // User-defined constructor.
    Vector(Vector const&);             // Copy constructor.
    Vector(Vector&&);                  // Move constructor.
    Vector& operator=(Vector const&);  // Copy assignment.
    Vector& operator=(Vector&&);       // Copy assignment.
};
```

<!-- 

Default constructor don't have any arguments.

User-defined constructors are constructors we write ourselves.
    It can have whatever arguments we pass to the constructor.

There are two main ways of giving objects their initial value.
    Assignment.
        Values get initialised in the body of the constructor.
    Initialising.
        Values get initialised before the body of the constructor.
        This is very important when you have const and reference attributes.

Copy constructors should copy the internal data of a class to *this.

Move constructors should move the internal data of a class to *this.

Copy assignments are like copy constructors but only if *this already exists.

Move assignments are like move constructors but only if *this already exists.

Constructors are really boilerplate.
    When we first start learning C++ - just refer to examples. Over time, you rote learn what you need to do.

Do example-class.cpp.

 -->

---

## Vectors

Vector is an array that can change size.

```cpp
std::vector<int> v1;     // Size of 0.
std::vector<int> v2(3);  // Size of 3.
std::vector<int> v3(4);  // Size of 4.
```

If you don't resize, you will get a segmentation fault.

```cpp
// Bad.
std::vector<int> v4;
v4[0];  // Seg fault.

// Good.
std::vector<int> v5;
v5.resize(1);
v5[0];  // No seg fault.
```

<!-- 

When we create a vector, we can specify its size upon initialisation.

A common mistake students make is not checking the size of the vector before using it.

Do example-vector.cpp.

 -->

---

## Vectors

Can also create vectors with an initialiser list.
```cpp
std::vector<int> v6{0};  // [0].
std::vector<int> v7{1, 2, 3};  // [1, 2, 3].
```

<!-- 

When we create a vector, we can specify the initial values of the elements of the vector.
    Very handy.

Do example-vector.cpp.

 -->

---

## Pointers

Pointers are variables whose value is an address.

```cpp
int var{42};
int* ptr{&var};
std::cout << ptr << std::endl;   // Prints the address.
std::cout << *ptr << std::endl;  // Prints the value AT the address.
```

```
address:    0x0     0x4
           -----   ----- 
value:    | 0x4 | |  42 |
           -----   -----
             ^       ^
            int*    int
```

<!-- 

Pointers are not scary if you just think of it as variables whose value is an address. It's like any other datatype.

If we print ptr directly, then we just print the value which is an address.

If we print the dereference of ptr, then we print the value at the address.
    When we dereference ptr. We go to the address then we get the value.

Do example-pointer.cpp.

 -->

---

## Pointer Arithmetic

We can look up other addresses by offsetting.

```cpp
int* ptr{new int[3]};
*ptr = 42;        // Base address.
*(ptr + 1) = 43;  // Offsets by sizeof(int) * 1.
*(ptr + 2) = 44;  // Offsets by sizeof(int) * 2.
std::cout << *ptr << std::endl;
std::cout << *(ptr + 1) << std::endl;
std::cout << *(ptr + 2) << std::endl;
```

Or more concisely...
```cpp
*ptr = ptr[0];
*(ptr + 1) = ptr[1];
*(ptr + 2) = ptr[2];
```

<!-- 

Let's malloc a int[3].

We can use pointer arithmetic to access the other elements of the array.
    We offset from the base address.

C/C++ also provides a syntactic sugar for accessing an array using [] instead of pointer arithmetic.

Do example-pointer-arithmetic.cpp.

 -->

---

## Iterators

Iterators are *light* class wrappers of pointers.

Lets us iterate over an STL container.

```cpp
std::vector<int> vec(3);
*vec.begin() = 42;        // Base address.
*(vec.begin() + 1) = 43;  // Offsets by sizeof(int) * 1.
*(vec.begin() + 2) = 44;  // Offsets by sizeof(int) * 2.
```

Or more concisely...
```cpp
std::vector<int> vec(3);
vec[0] = 42;  // Base address.
vec[1] = 43;  // Offsets by sizeof(int) * 1.
vec[2] = 44;  // Offsets by sizeof(int) * 2.
```

<!-- 

We can simply treat iterators exactly as if they are just pointers.
    We use iterators for STL containers.
    We can do pointer arithmetic on iterators as well.

Do example-iterators.cpp.

 -->

---

## STL Algorithms

---

## Sets

---

## Maps

---

