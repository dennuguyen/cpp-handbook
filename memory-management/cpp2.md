-------------------
marp: true
theme: owr-theme
class: invert
paginate: true
-------------------

# C++

Memory Management

<!--

-->


-------------------
## Learning Outcomes

- Understand relevant types of storage duration. 
- Aware of dynamic memory allocation functions: new and delete. 
- Revise raw pointers and aware of dangers of raw pointers. 
- Understand how to use relevant types of smart pointers. 
- Aware of nullptr keyword. 
- Understand references and its differences from a pointer. 
- Understand differences of passing-by-value, passing-by-reference, and passing-by-pointer.

-------------------
## Storage Duration

- *Static*: Object persists throughout program life-time.
- *Automatic*: Object persists within scope life-time.
- *Dynamic*: Object life-time is defined by us.

https://en.cppreference.com/w/cpp/language/storage_duration

<!-- 

This is another parameter of objects and variables.

Storage durations tells us when an object is allocated in memory and deallocated.

Static storage duration:
    This includes global variables, variables declared with static or extern.

    As a result, we can only have one instance of this object which can cause naming conflicts. Bad.

Automatic storage duration:
    All objects have automatic storage duration by default unless it's static.

    Won't go through this, because it's basically scopes.

Dynamic storage duration:
    We tell the compiler how long an object will live for using dynamic memory allocation functions.
 -->

-------------------
### Dynamic Memory Allocation

Goodbye `malloc`, `calloc`, `realloc`, `free`.
```cpp
int* ptr = (int*)malloc(sizeof(int));
free(ptr);
```

Hello `new`, `delete`.
```cpp
int* ptr1 = new int;  // Pointer to int.
delete ptr1;

int* ptr2 = new int[];  // Pointer to int array.
delete[] ptr2;
```

<!-- 

C++ introduces new and delete keywords to replace C-style memory allocation.

C-style memory allocation is very clunky.

Now you know what new and delete is. Don't ever use it.

 -->

-------------------
## Raw Pointers

Pointers are variables which stores addresses.

```cpp
int val = 3;
int* ptr = &val;   // ptr points to address-of val.
int deref = *ptr;  // assign deref the derefence of ptr.
```

<br>

![width:60mm](images/cpp2-raw-pointer.png)

Raw pointers are dangerous.

<!-- 

C++ has pointers, exactly the same as C.

But in C++ we call them raw pointers because we have to manage the lifetime of the pointer ourselves. Very exposed. Which is why we don't ever want to use raw pointers.

When derefencing ptr:
    Go to address that ptr is storing.
    Get the value at that address.

Show raw-pointers.cpp

Raw pointers are very dangerous though. Any ideas why?

 -->

-------------------
### Dangling Pointers

Pointers that point to invalid data.

```cpp
int *ptr1 = new int;
int *ptr2 = new int;

*ptr1 = 42;
ptr2 = ptr1;  // ptr1 and ptr2 both have the same address.

delete ptr1;

std::cout << *ptr2 << std::endl;  // What does this print?

delete ptr2;  // What happens here?
```

<!-- 

Dangling pointers are pointers that point to invalid data.

Show dangling-pointers.cpp

In this example, we have two pointers pointing to the same address.
    We free one of the pointers.

    We print out ptr2. What happens? Everything can be fine, we can crash, get undefined behaviour.

    We free ptr2. What happens? Double free, get undefined behaviour.

It's bad.

 -->

-------------------
### Memory Leaks

Pointers that are never freed.

```cpp
while (true) {
    int *ptr = new int;
    // do ptr stuff
    // free(ptr)  // whoops
}
```

<!-- 

Even more dangerous than dangling pointers are memory leaks.

In this example, we keep allocating memory and forget to free it.
    Our computer only has finite memory. Luckily modern OS's deal with memory leaks very well. The OS will eventually force the program to terminate.

 -->

-------------------
## Smart Pointers

> Smart pointers enable *automatic*, *exception-safe*, *object lifetime* management.

Pointer is deallocated when no longer used.

```cpp
auto uniquePtr = std::make_unique<int>(42);

auto sharedPtr1 = std::make_shared<int>(108);
auto sharedPtr2 = std::shared_ptr<int>(sharedPtr1);
```
Types of Ownership
- *Unique Pointer*: Only one pointer can manage the resource.
- *Shared Pointer*: Many pointers can manage the resource.

<!--

How do we avoid all the dangers of raw pointers?

C++ introduces smart pointers.
    Exactly the same as raw pointers but everything is managed for us. Smart pointers actually uses raw pointers, new and delete under the hood.

    Smart pointers have automatic storage duration. Remember what automatic is? Smart pointers get deallocated when out-of-scope, therefore we don't get dangling pointers nor memory leaks.

    Therefore if you want to use pointers, ONLY use smart pointers.

There are two main types of smart pointers that you may use:
    There are more types but not important.

    Unique pointers only lets a single pointer manage the resource. When the unique pointer is out of scope, the resource gets destroyed.

    Shared pointers lets many pointers manage the resource. When the LAST shared pointer is out of scope, i.e. there are no more pointers managing the resource, then the resource gets destroyed.

 -->


-------------------
## Null Pointers

Pointers that store nothing.

```cpp
std::unique_ptr<int> ptr = nullptr;  // Null pointer.
```

Use `nullptr` over `NULL` for null pointers.

<!-- 

C++ introduces a keyword for null pointers called surprisingly nullptr.

nullptr is pointer datatype.
NULL is an integer of void* datatype.

 -->


-------------------
## References

Alias to an **existing** object.
Use it like a value but behaves like a pointer.

```cpp
int orig = 21;
int& ref = orig;  // Reference to orig

orig = 36;
std::cout << ref << std::endl;  // What does ref print out?

ref = 42;
std::cout << orig << std::endl;  // What does orig print out?
```

<!--

C++ introduces references:
    Very convenient semantic that lets you use variables that behaves like pointers.

Benefits of references:
    Can be considered syntactic sugar over pointers.

    You can chain pass references as arguments through multiple function calls unlike pointers. It's a lot easier to pass references as arguments over pointers.

    Whether references can't be assigned NULL or can't be reassigned depends on your use-case.

Show references.cpp

 -->


-------------------
### References vs Pointers

Reference | Pointer
-|-|
Must be initialised when declared | Can be initialised later when declared
Cannot be re-referenced | Can be re-pointed
Cannot be assigned `NULL` | Can be assigned `NULL`
Share address with assigned object | Has its own address


-------------------
### Dangling References

References whose variable gets destroyed.

```cpp
auto getString() -> std::string& {
    return "This string gets destroyed";
}

std::string& str = getString();  // Dangling reference.
std::cout << str;                // Undefined behaviour.
```

<!-- 

Even though references can't be assigned NULL, it can still dangle.

Be aware of dangling references.

Trying to use a dangling references is undefined behaviour.

 -->

-------------------
## More Function Parameters

We can pass references and pointers into functions.

```cpp
auto byValue(int a) -> void;                     // Pass by value.
auto byReference(int& a) -> void;                // Pass by reference.
auto byPointer(std::shared_ptr<int> a) -> void;  // Pass by pointer.
```

<!-- 

Show passing-by.cpp

Passing by value.
    We can modify the variable inside the function, and it doesn't modify the original variable.

Passing by reference.
    Modifying the reference inside the function will modify the original variable outside the function.

Passing by pointer.
    Modifying the pointer inside the function will modify the dereferenced value of the pointer.

    Some caveats however. The pointer to be passed must be a shared pointer because passing in a smart pointer means that a new smart pointer will be created and will take ownership of the resource.

We should prefer to pass by reference
    It's simpler

    More convenient

 -->