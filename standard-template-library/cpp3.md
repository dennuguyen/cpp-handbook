-------------------
marp: true
theme: owr-theme
class: invert
paginate: true
-------------------

# C++

Standard Template Library

<!--

This is one of the most useful topics you will learn in C++.

Using this library will save lots of time instead of building commonly used datatypes from scratch.

-->

-------------------
## Learning Outcomes

- Understand what an iterator is and how it can be used.
- Appreciate the convenience of STL containers, iterators, and algorithms.
- Know how to utilise a wide variety of STL containers, iterators, and algorithms.

-------------------
## What is STL?

- Collection of generic containers and algorithms.
- Containers store data and have iterators.
- Algorithms manipulate iterators.

![width:160mm](images/container-iterator-algorithm.png)

<!--

STL is a convenience library so we don't have to re-invent the wheel.

STL containers are generic and can accept any datatype in its container.
    Can have a vector of int or a vector of string.
    Or a map with int keys and string values.
    Or a map with string keys and int values.

STL algorithms are also generic and accepts iterators from any STL container.
    Can use a for_each algorithm over a vector or over a linked list.

 -->

-------------------
## STL Containers

Convenience classes that stores data of any datatype.

https://en.cppreference.com/w/cpp/container

<!-- 

I will show what STL containers C++ offers, but to really understand how to use these containers, we must always consult the documentation.

Show cpp3-01, cpp3-02, cpp3-03 with following container slides.

 -->

-------------------
### Sequence Containers

Data structures which can be accessed sequentially.

```cpp
std::array
std::vector
std::deque
std::forward_list
std::list
```

-------------------
### Associative Containers

Sorted data structures which can be searched quickly, `O(log n)`.

```cpp
std::set
std::map
std::multiset
std::multimap
```

-------------------
### Unordered Associative Containers

Unsorted data structures which can be searched quickly, `O(1) - O(n)`.

```cpp
std::unordered_set
std::unordered_map
std::unordered_multiset
std::unordered_multimap
```

-------------------
### Container Adaptors

Different interface for sequential containers.

```cpp
std::stack
std::queue
std::priority_queue
```

-------------------
### Span

No ownership over contiguous sequence of objects.

```cpp
std::span
```

-------------------
## STL Iterators

Iterators are basically pointers with added directional meaning.

```cpp
// Iterate moving forward.
begin()  // Points to first element.
end()    // Points to past-the-last element.

// Iterate moving backwards.
rbegin()  // Points to the last element.
rend()    // Points to before-the-first element.

// Iterate moving forward and guarantee no modifications.
cbegin()
cend()

// Iterate moving backwards and guarantee no modifications.
crbegin()
crend()
```

<!-- 

Iterators are pointers but with added directional meaning.
    Pointers that iterate or move forward across some container.

Implementation of iterators
    Iterators are classes
    Encapsulate raw pointers
    Provides methods to interact with the pointer
        Incrementing
        Derefencing

It's the glue between STL containers and STL algorithms.

There are a few types of iterators
    ::iterator
    ::reverse_iterator
    ::const_iterator

Show cpp3-04.

 -->

-------------------
## STL Algorithms

Convenience functions to let us interact with STL containers via iterators.

https://en.cppreference.com/w/cpp/algorithm

<!-- 

When do we use STL algorithms?
    Whenever we can.
    If you're using for loops with containers, most likely you can use STL algorithms.

There are so many different STL algorithms that it's impossible to cover all of them.
    You will know these algorithms through experience and reading.

 -->

-------------------

### Lambda Functions

Functions that are *"stateless"*, *"anonymous"*, *"inline"*, *"less verbose"*.

Instead of defining a function...
```cpp
auto foo() -> bool {...}
std::copy_if(..., ..., foo);
```

Use lambda functions like this:
```cpp
std::copy_if(..., ..., [](){});
```

Anatomy of a lambda function.
```cpp
[ capture ]( parameters ){ body }
```

<!-- 

In order to use STL algorithms to their full potential, we need to learn lambda functions.

Defining foo and passing the function name is equivalent to writing a lambda function.

We prefer lambda functions when
    Function is very specific, not used anywhere else
    Function is short

Anatomy of a lambda function
    Three sets of brackets
    Capture
        Objects are passed into the capture so they are "scoped" in the function
        Parameters are same as function parameters
        Body does the work

Show cpp3-05.

 -->