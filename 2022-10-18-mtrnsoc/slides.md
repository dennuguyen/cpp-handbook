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
1. Pointers & Iterators.
1. Vectors
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

## Pointers

Pointers are variables whose value is an address.

```cpp
int var{42};
int* ptr{&var};
```

If we assume that `var1` and `var2` is **contiguous** in memory...
```cpp
int var1{42};
int var2{43};
int* ptr{&var1};
std::cout << ptr << std::endl;
std::cout << ptr + 1 << std::endl;
```

---

## Iterators

Iterators are *light* class wrappers of pointers.

Lets us iterate over an STL container.

---

## Vectors

Vector is an array that can change size.

```cpp
std::vector<int> v1;
```

---

## STL Algorithms

---

## Sets

---

## Maps

---

