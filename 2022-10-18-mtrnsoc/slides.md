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
1. `std::vector`.
1. STL Algorithms.
1. `std::set`.
1. `std::map`.

Some theory and some questions.

---

## Constructors

Constructors are functions which instantiate an object.

```cpp
class Graph;

int main() {
    Graph g; // Instantiate an object called g of type Graph.
}
```

<!-- 

The job of the constructor is to initialise an object with the values you want it to have initially.

 -->

---

### How to initialise variables?

There are two ways...

```cpp
class Graph {
public:
    Graph(Nodes n, Edges e) {  // Assignment - not true initialisation.
        n_ = n;
        e_ = e;
    }

    Graph(Nodes n, Edges e) : n_(n), e_(e) {}  // Using a member initialiser list.

private:
    Nodes n_;
    Edges e_;
};
```

<!-- 

Constructors are always called when an object gets instantiated.
    It has the same name as the class.
    It does not return anything.


There are two main ways of giving objects their initial value.
    Assignment.
        Values get initialised in the body of the constructor.
    Initialising.
        Values get initialised before the body of the constructor.
        This is very important when you have const and reference attributes.

Show cpp5-02.
Show cpp5-03.

 -->

---

### Different Types of Constructors

- Default constructor.
- User-defined constructor.
- Copy constructor.
- Move constructor.

Relevant but not constructors:
- Copy assignment.
- Move assignment.

<!-- 



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

