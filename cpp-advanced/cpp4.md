-------------------
marp: true
theme: black
class: invert
paginate: true
-------------------

# C++

Advanced Topics

<!--

These topics will build the fundamental knowledge to completely understand later topics such as classes and templates.

Warning: this is a highly theoretical tutorial.

-->


-------------------
## Learning Outcomes

- Understand the concept of C++ objects.
- Briefly know the definition of C++ expressions.
- Can identity different value categories and their implications of memory use.
- Understand how different type categories affects object resource manipulation.
- Understand the basis for move semantics.
- Know different exception types and how to handle them.
- Understand the concept of RAII and how memory is utilised under this technique.
- Understand concept of polymorphism and when polymorphism can occur.
-------------------
## Objects

An object has:
- Size.
- Alignment requirement.
- Storage duration.
- Lifetime.
- Type.
- Value.
- And maybe a name.

Common theme of an object is memory!

Basically all variables are objects.

<!-- 

No this is not OOP.

Objects in C++ have
    size (how much memory is allocated)
    alignment requirement (where the memory is allocated)
    storage duration (automatic, static, dynamic, local)
    lifetime (how long memory should be used for)
    type
    value
    name

There's a common theme here which is anything that requires run-time memory is an object.

What can we do with objects?
    Create, destroy, refer, access, manipulate

Basically variables are objects.

Examples of things that are not objects are values, references, functions, enumerators, types, non-static class members, templates, classes, namespaces.
    Because these are all determined in compile-time.

 -->

-------------------
## Expressions

Expressions are a sequence of operators and operands when evaluated may return a result.

```cpp
int a = b;
if (a == b || c == d) { ... }
int a, b, c;
```

Expressions have two independent properties: type and value.

<!-- 

Expressions have operators and operands when evaluated will give us some result.
    =, +=, -=, *=, ++a, --a, a + b, a >> b, !a, a[b], *a, a->b, a ? b : c...

Can you identify what operators and operands are in the example?

Expressions are characterised by a type and a value category.
    Belonging to one of three value categories: prvalue, xvalue, lvalue.

Now we know everything we need to move on.

 -->

-------------------
## Value Categories

Values can be considered inputs and outputs of an expression's evaluation.

- *glvalue*: expression which determines identity of object or function.
- *prvalue*: expression which computes value or initialises an object.
- *xvalue*: glvalues whose object's resources can be reused.
- *lvalue*: glvalues that are not xvalues.
- *rvalue*: prvalue or xvalue.

Why do we care about this?
Defines rules for moving and reusing an object's resources.

<!-- 

Formally, values are a member of a set of possible interpretations of an infinite sequence of symbols.

glvalue: generalised lvalue
    expression when evaluated determines identity of object or function

prvalue: pure rvalue
    expressions when evaluated computes value of an operand or initialises an object

xvalue: expiring value
    glvalues whose object's resources can be reused

lvalue: left value
    glvalues that are not xvalues
    typically left-hand side of assignment

rvalue: right value
    prvalue or xvalue
    typically right-hand side of assignment

But we really only care about lvalues and rvalues because these 2 rules defines how we want to move, copy, reuse object resources.

 -->

-------------------
## Lvalues & Rvalues Simplified

*lvalue*: typically has storage.
*rvalue*: typically has no storage.

```cpp
int /* lvalue */ a = 1 /* rvalue */;
int /* lvalue */ b = a /* lvalue */;
```

<!-- 

Quite simply
    lvalues have storage
    rvalues have no storage

 -->

-------------------
## Type Categories

Types restricts an expression's possible operations on a value.

`char`, `float`, `void`, `pointers`, `arrays`, `classes`, `references` are all types.

```cpp
int a = 3;          // Has type int.
int[2] b = {4, 5};  // Has type int[].
a + b;              // Does this make sense?
```

<!-- 

Types restricts what operations are possible in an expression.
    What makes sense and doesn't make sense?
    Basically semantics.

Can you identify the types in the example?

In this tutorial, we care about reference types because it will tell us how we can manipulate object resources.

 -->

-------------------
## Lvalue References

Alias an existing object.

```cpp
void foo(T& t);
```

<!-- 

You should already know this from cpp1.

 -->

-------------------
## Rvalue References

Used to extend the lifetime of objects by transferring "ownership" of an object's resources.

```cpp
void foo(T&& t);
```

`std::move` turns Lvalues into Rvalues.

```cpp
auto v1 = std::vector<int>({1, 2, 3});
auto v2 = std::move(v1);
// v1 can now be discarded.
```

Why move?

To optimise copying.

<!-- 

Another kind of reference which lets us reassign an owner of the reference.
    Changing owners also means moving the object's resources.

Denoted by &&.

How do we move an object? Using std::move which turns Lvalues into Rvalues.

See example.
    We should no longer care about v1 after we moved it to v2.

Show cpp4-01.

Can see that this is useful if we want the object's lifetime to be extended
    Maybe the original object was going out of scope e.g. exiting a function.

Now real question is why move at all?
    Why not just pass by value or
    assign v2 = v1

    What if you only want one copy of the object? Copying is a waste of processing power and memory.

    Moving doesn't make any copies at all. It just transfers ownership of some resources.

 -->

-------------------
## Forward References

Preserves an expression's value category when passing its result around function to function.

```cpp
void inner(int& val) { ... }
void inner(int&& val) { ... }
void outer(int&& val) { inner(val); }  // Problem: calls inner(int&).

int main() {
    outer(20);
}
```

Remember the definition of Lvalues and Rvalues.
*Lvalue resources cannot be reused.*

<!-- 

We now know how to convert Lvalues to Rvalues and Rvalues to Lvalues.

Now we need to know how to not convert them by using forward references.

Introduce forwarding problem.

There will be cases where you need to pass by reference to multiple nested functions. It is important that its Lvaluedness and Rvaluedness is maintained or the meaning of the expression may change.
    In this example our Rvalue of 20 becomes an Lvalue which is why inner(int&) is called. What does this mean?
        Our val being an Lvalue means its resources has been allocated and it cannot be reused.

Show cpp4-02

 -->

-------------------
## Reference Collapsing

Rules that enables perfect forwarding.

Can reference references through a `decltype`, `typedef` or `template`.

Chaining references will "collapse" into a reference.

```cpp
using lref = int&;
using rref = int&&;
int n;
lref& r1 = n;   // lref(lref) = lref
lref&& r2 = n;  // lref(rref) = lref
rref& r3 = n;   // rref(lref) = lref
rref&& r4 = n;  // rref(rref) = rref
```

An Lref in a chain of Lrefs and Rrefs will result in an Lref.

<!-- 

You can reference references but only through a decltype, typedef, or template.

Basically if you have lrefs and rrefs, it'll simplify to an lreft.

When would you need to use this?
    To allow perfect forwarding.
    If we are only passing rrefs around, we don't expect the value to behave like an lvalue.
    If we have pased our value as an lvalue then we do expect it to behave like an lvalue.

 -->

-------------------
## Exceptions

Exceptions are for logic and run-time errors that are exceptional.

```cpp
try {
    // Do something.
} catch(std::exception const& e) {  // Catches a particular exception object.
    std::cerr << e.what() << "\n";  // Print the exception.
} catch(...) {                      // Catches all exceptions.
    throw;                          // Rethrow so code higher up can catch it.
}
```

Exception objects are the result of a throw expression.

https://en.cppreference.com/w/cpp/error/exception


<!-- 

What are exceptions?
    Errors that we can catch during runtime and attempt to fix or do something about or rethrow.
    Errors are typically run-time errors or logic errors.

Why exceptions?
    Allows us to catch errors in runtime and not crash our program.
    Clean separation between working code and error handling code.

When to use exceptions?
    Only for exceptional circumstances outside the programmer's control.
    Some examples?
        Receiving a message but finding out it is corrupt.
        Opening a corrupt or missing file.

Example
    General structure for try-catch block
    Absolutely do not nest try-catch statements.
    The order of catch statements starts with specific then more general as you go down.

List of exceptions.
    All exceptions inherit a class called exception.

Show cpp4-03.

 -->

-------------------
## Exception Handling

You caught an exception, now what?

- *No exception safety*: Anything can happen.
- *No throw guarantee*: Exceptions handled internally.
- *Basic exception safety*: Continue where values can be validly changed.
- *Strong exception safety*: Rollback to previous working state.

Which method?
Criticality, frequency, implementation-difficulty.

<!-- 

4 different ways we can handle exceptions.
    No exception safety.
        Do nothing about it, anything can happen
    
    No throw guarantee.
        Code is guaranteed to succeed.
        If an exception occurs, it will be handled internally.
        Programmer does not need to know about it.
        E.g. closing file, freeing memory.
    
    Basic exception safety.
        Code may be partially executed.
        There may be change of state but we continue regardless.

    Strong exception safety.
        Code may fail.
        Rollback to a state before exception occurred.
        Values should not be changed, code is not partially executed.
        Harder to implement because need system for rolling back.

Pick which exception handling method is appropriate based on:
    More critical code may need strong exception safety.
    Extremely exceptional circumstances AND difficult to implement exception handling may prefer no exception safety.

Show cpp4-04.

 -->

-------------------
## RAII

Resouce Acquisition Is Initialisation.

An object with automatic storage duration allocates its resources in heap memory.

1. Acquire: Object gets pushed onto stack memory.
1. Initialise: Object's resources gets allocated on heap.
1. Do whatever.
1. Uninitialise: Object's heap resources gets freed.
1. Unacquire: Object gets popped from stack memory.

<!-- 

This whole tutorial leads up to a very important topic of C++.

Revision.
    Every thread has its own stack of memory which keeps track of the variables that you declare.

    Functions will have its own portion of the stack that no other functions can write/read to.

RAII.
    When you acquire a resource, it also initialises it.
    Acquiring and initialising a resource must be hand-in-hand.
    Acquiring means to allocate the object on stack memory.
    Initialising means to allocate the object's resources on heap memory.

 -->

-------------------
## RAII

Why?
- No resource leaks.
- Guarantees exception safety.

Move semantics helps us safely move ownership of resources and does not break this principle.

<!-- 

This programming technique makes objects manage their own resources.
    In C, you would manually malloc and have to remember to free for each malloc.
    This is very dangerous.
    So we bind the action of malloc/free to a temporary object and let the storage duration do the work.
    This makes sure we don't have memory leaks and guarantees exception safety.
        No throw guarantee when moving resources or freeing memory.

Every single object in the C++ library uses RAII e.g. strings, vectors.
    Under the hood there is mallocing and freeing but as the user, you don't care about that.

Now what if we want to move ownership of an RAII's resources?
    Use std::move().

 -->

-------------------
## Polymorphism

Polymorphism is the ability for an entity to take on many forms.

Polymorphism can occur at:
- Run-time.
- Compile-time.

Ad-hoc polymorphism is a type of polymorphism which provides explicit code to support other types e.g. function overloading.

<!-- 

Will briefly introduce the concept of polymorphism.

Polymorphism is a concept that some entity has multiple forms.
    You can have multiple functions with the same name.
    You can use static_cast to change an object's type.

There are two places where polymorphism can occur:
    At compile-time or run-time.

Ad-hoc polymorphism is a type of polymorphism.
    Writing explicit code to support other types e.g. function overloading.

Is ad-hoc polymorphism run-time or compile-time?

Will introduce other types of polymorphism later.
    Subtype polymorphism.
    Parametric polymorphism.

 -->