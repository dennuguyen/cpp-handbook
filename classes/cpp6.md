-------------------
marp: true
theme: owr-theme
class: invert
paginate: true
-------------------

# C++

Classes Extended

<!--

These slides are focused on extending the functionality of classes in C++.

-->


-------------------
## Learning Outcomes

- Can use static member variables and functions for appropriate cases.
- Can use nested types (e.g. classes and enums) and understand the scope of inner and outer class members.
- Can use friend functions.
- Can use operator overloading.
- Understand the concept of inheritance and how it can be used.
- Aware of multiple inheritance and the dreaded diamond.
- Understand how virtual inheritance solves dreaded diamond inheritance.
- Understand when to use virtual destructors.

-------------------
## Learning Outcomes

- Understand the purpose of virtual functions and how they are implemented.
- Understand the purpose of pure virtual functions and how they affect class instantiation.
- Understand the purpose of final keyword in preventing inheritance and overrides.
- Understand the concept of dynamic binding and which method implementations are selected at run-time.
- Understand how to explicitly up-cast and down-cast types using dynamic cast.

-------------------
## Static Members

Static members are not bound to the class instance.

```cpp
class Math {
public:
    static double sqrt(double val) { return std::sqrt(val); }
    static constexpr double pi = 3.14;  // Needs constexpr.
};

int main() {
    std::cout << Math::sqrt(3) << std::endl;  // Can use scope operator.
    std::cout << Math::pi << std::endl;       // Can use scope operator.

    Math math;
    std::cout << math.pi << std::endl;  // Can also instantiate and access with dot operator.
}
```

<!-- 

Members that are declared with the static keyword can be used without instantiating a class.
    I.e. static members are not bound to the class instance.

This may be useful if a static member is shared.
    E.g. it does not make sense for every Math object to have its own pi and sqrt function.

Typically associated with utility functions.

Static members obviously has static storage duration.
    Basically has global lifetime.

pi needs to be declared with constexpr because pi is an in-class initialisation.
    Value of pi must be determined at compile-time.

Show cpp6-01.

 -->

-------------------
## Nested Types

`inner` class has visibility of `outer`'s private members.
`outer` class does not have visibility of `inner`'s private members.

```cpp
struct outer {
    static int b;  // Must be static or compiler error.

    struct inner {
        void foo() {
            b++;
        }
    };
};

outer::inner::x;
```

`inner` can't use `outer`'s non-static members.

<!-- 

It's possible to define a class within another class.
    Can also define enums within class.

Inner class will have access to private members of the enclosing class.
But enclosing class will not have access to private members inner class.

Common use case for nested classes.
    STL containers have their own nested iterator class.

Use nested classes if there's an inner class that's closely related to your outer class that no one else will use.

Show cpp6-02.

 -->

-------------------
## Friends

Grants non-member functions or classes access to private and protected members of a class.

```cpp
class Graph {...};

class Node {
    friend void setVal(int val) { val_ = val; }  // setVal can access Node's privates.
    friend Graph;                                // Graph can access Node's privates.
    int val_;                                    // Private member.
};

setVal(3);                                            // setVal can access Node's privates.
Graph::getNodeValue(Node node) { return node.val_; }  // Graph can access Node's privates.
```

*My friends can touch my private parts.*

<!-- 

There will be cases where you need a non-member function or class to access private and protected members of a class.
    To give these functions and classes access, we declare them with friend specifier.

My friends can touch my private parts.
I cannot touch my friend's private parts.
A friend of my friend is not my friend.
My friend's children are not my friends.

Why use friends?
    Provides more freedom in how you call a function.

When should you use friend?
    Operator overloading.
    Give a closely-related encapsulating class access to your class.

Important to note that access specifiers do not affect friendship.

Show cpp6-03.

 -->

-------------------
## Operator Overloading

Can customise operators for user-defined classes.

```cpp
class MyClass {
    MyClass operator*=(MyClass const& obj) {
        data_ *= obj.data_;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, MyClass const& obj) {
        os << obj.data_;
        return os;
    }
};
```

<!-- 

You actually did operator overloading with move assignment and copy assignment.

Operator overloading lets you write your own meaning for an operator.

This is where friends become very important so we can have more syntax freedom in how to use overloaded operators.

 -->

-------------------
### Binary Operators

Overloaded operators which require 2 operands are *friends*.

<table>
    <tr>
        <th> I/O </th>
        <td> <code><<</code>, <code>>></code> </td>
    </tr>
    <tr>
        <th> Comparison </th>
        <td> <code>==</code>, <code>!=</code>, <code><</code>, <code>></code>, <code><=</code>, <code>>=</code>, <code><=></code> </td>
    </tr>
    <tr>
        <th> Arithmetic </th>
        <td> <code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>, <code>%</code>, <code>&</code>, <code>|</code>, <code>^</code> </td>
    </tr>
    <tr>
        <th> Logical </th>
        <td> <code>&&</code>, <code>||</code> </td>
    </tr>
</table>

<!-- 

Just a list of binary operators which can be overloaded.

 -->

-------------------
### Unary Operators

Overloaded operators which require 1 operand are *members*.

<table>
    <tr>
        <th> Increment/Decrement </th>
        <td> <code>++a</code>, <code>--a</code>, <code>a++</code>, <code>a--</code> </td>
    </tr>
    <tr>
        <th> Logical </th>
        <td> <code>!</code> </td>
    </tr>
    <tr>
        <th> Arithmetic </th>
        <td> <code>+a</code>, <code>-a</code>, <code>~a</code> </td>
    </tr>
    <tr>
        <th> Assignment </th>
        <td> <code>=</code>, <code>+=</code>, <code>-=</code>, <code>*=</code>, <code>/=</code>, <code>%=</code>, <code>&=</code>, <code>|=</code>, <code>^=</code>, <code><<=</code>, <code>>>=</code> </td>
    </tr>
    <tr>
        <th> Access </th>
        <td> <code>[] const</code>, <code>[]</code>, <code>&</code>, <code>*</code>, <code>-></code>, <code>()</code>, <code>.</code> </td>
    </tr>
    <tr>
        <th> Other </th>
        <td> <code>()</code>, <code>,</code> </td>
    </tr>
</table>

<!-- 

Just a list of unary operators which can be overloaded.

 -->

-------------------
## Overload Type Conversions

Can also overload type conversions.

```cpp
class IntVec {
    IntVec operator std::vector<int>() {
        return data_;
    }
};
```

<!-- 

Overloading type conversions can be very useful.

Consider a simple class which is a vector of integers.

Show cpp6-04.

 -->

-------------------
## Inheritance

Derived classes are base classes plus more.

```cpp
class BaseClass {
protected:
    int val1_;
};

class DerivedClass : public BaseClass {
    int val2_;
};
```

Inheritance enables polymorphism and dynamic binding.

<!-- 

C++ supports class inheritance which is an OOP concept.
    But we won't be teaching OOP, just how inheritance works.

To simply understand inheritance. Derived classes are the base class + more.
    Except for private base class members (touch on this next slide).

Can build a hierarchy of classes using inheritance.
    Animal -> Dog -> Husky.

This does reduces code duplication if there is a class that has members based off another class.

But the primary purpose of inheritance is to introduce polymorphism and dynamic binding.
    These are the real reasons to consider when to use inheritance.
    They both provide great flexibility.
    Will discuss these two topics later on.

 -->

-------------------
### Inheritance Type

<table>
    <tr>
        <th>Inheritance Type</th>
        <th>Base Class Access</th>
        <th>Derived Class Access</th>
    </tr>
    <tr>
        <td rowspan="3">Public</td>
        <td>Public</td>
        <td>Public</td>
    </tr>
    <tr>
        <td>Protected</td>
        <td>Protected</td>
    </tr>
    <tr>
        <td>Private</td>
        <td>Inaccessible</td>
    </tr>
    <tr>
        <td rowspan="3">Protected</td>
        <td>Public</td>
        <td>Protected</td>
    </tr>
    <tr>
        <td>Protected</td>
        <td>Protected</td>
    </tr>
    <tr>
        <td>Private</td>
        <td>Inaccessible</td>
    </tr>
    <tr>
        <td rowspan="3">Private</td>
        <td>Public</td>
        <td>Private</td>
    </tr>
    <tr>
        <td>Protected</td>
        <td>Private</td>
    </tr>
    <tr>
        <td>Private</td>
        <td>Inaccessible</td>
    </tr>
</table>

<!-- 

You must add an access specifier when you inherit a class.

This access specifier determines the kind of inheritance:
    public inheritance
    protected inheritance
    private inheritance

These different types of inheritance determines how public, protected, and private members of a class change their specifier between the base and derived class.

Choose the kind of inheritance which makes sense to the relationship of your classes.

Show cpp6-05.

 -->

-------------------
### Multiple Inheritance

Derived classes can inherit multiple base classes.

```cpp
class Base1 {};
class Base2 {};
class Derived : public Base1, public Base2 {};
```

<!-- 

C++ supports multiple inheritance.

Derived will inherit both Base1 and Base2.

Show cpp6-06.

 -->


-------------------
### Virtual Inheritance

Consider the dreaded diamond inheritance which has two instances of `A` in `D`'s hierarchy.

```cpp
class A {};
class B : public A {};
class C : public A {};
class D : public B, public C {};
```

Virtual inheritance allows only one instance of `A` in `D`'s hierarchy.

```cpp
class A {};
class B : public virtual A {};
class C : virtual public A {};
class D : public B, public C {};
```

<!-- 

In the first example, the derived class D actually has 2 instances of base class A.
    When we try to compile, we COULD get a compiler error.
        Typically reference to something in A is ambiguous.

This can be solved with virtual inheritance.
    Which ensures that any virtually inherited class appears once in the inheritance hierarchy.

Show cpp6-07.

 -->

-------------------
### Virtual Destructors

Ensures the `Derived` destructor is called.

```cpp
class Base {
public:
    virtual ~Base() {}  // Virtual destructor.
};

class Derived : public Base {};

Base* base = new Derived;
delete base;  // Safe.
```

Use when deleting **pointers** to `Base`.


<!-- 

Remember the order of construction/destruction for classes with inheritance.
    Base constructor.
    Derived constructor.
    Derived destructor.
    Base destructor.

Not having a virtual destructor in Base means the Derived destructor will not be called.
    Deleting pointer to base will just call Base constructor.
        Doesn't know that there's another destructor that should be called.

Marking Base's destructor virtual will ensure that all the destructors are called.

Show cpp6-08.

 -->

-------------------
## Virtual Functions

Allows the original behaviour of a method to be overriden.

```cpp
struct Base {
    virtual int getValue();
};

struct Derived : public Base {
    int getValue() override;
};
```

<!-- 

Virtual functions is a concept that lets us override the original behaviour of a method.
    I.e. a base class may define an implementation that is not suitable for our derived class.
    So our derived class is able to override that behaviour for a new suitable behaviour.

Override is optional but strongly recommend it since it's explicit and will cause compiler-error if getValue doesn't actually override anything like expected.

What would be some good examples of when virtual functions would be used?

Show cpp6-09.

 -->

-------------------
### Pure Virtual Functions

Pure virtual functions are virtual functions marked with `= 0`.

```cpp
class Base {                     // Base is an abstract class.
    virtual int getValue() = 0;  // Is a pure virtual function.
};

class Derived {
    int getValue() override { return val_; }  // Must define.
};
```

Enforces:
- Base class cannot be instantiated (is an abstract class).
- Subclass must define/override the pure virtual function.

<!-- 

=0 is also called pure-specifier.

The concept of abstract class exists in C++.
    It is implemented with pure virtual functions.

Pure virtual functions are just virtual functions with some extra rules.
    To specify a virtual function is pure, add = 0 at the end.
    This makes the class of the pure virtual function abstract.
        Which means it cannot be instantiated.
        If you want to use this class, you need to instantiate some derived class.
    And the pure virtual function MUST be defined in the derived class.

 -->

-------------------
### Final

`final` prevents the class from being inherited or method to be overriden.

```cpp
class Base {
    virtual void foo() final;  // Derived cannot override foo.
};

class Derived final : public Base {};  // B cannot be derived.
```

-------------------
### Dynamic Binding

Choosing an appropriate method at run-time.

```cpp
struct Base {
    virtual std::string out() { return "Base"; }
};

struct Derived : Base {
    std::string out() override { return "Derived"; }
};

Base* b1 = new Base;
Base* b2 = new Derived;  // Implicit up-cast.

// What will these print?
std::cout << b1->out() << std::endl;
std::cout << b2->out() << std::endl;
```

<!-- 

Dynamic binding is binding a function to the correct behaviour at run-time.
    Program won't know what behaviour out() will have at compile-time.

Important to understand that behaviour is dependent on what b1 and b2 was initialised with.

Show cpp6-10.

 -->

-------------------
## Dynamic Cast

Explicitly and safely converts pointers and references to classes up or down the inheritance hierarchy.

```cpp
Base& b1 = dynamic_cast<Base&>(derived);          // Up-casting a reference
Base* b2 = dynamic_cast<Base*>(&derived);         // Up-casting a pointer.
Derived& derived = dynamic_cast<Derived&>(base);  // Down-casting a reference.
Derived* derived = dynamic_cast<Derived*>(base);  // Down-casting a pointer.
```

- Up-casting: `Derived` -> `Base`.
- Down-casting: `Base` -> `Derived`.
    - Requires `Base` to be a polymorphic type.
    - Always test down-casting.

*A class is a polymorphic type if it has a virtual function*.

<!-- 

Dynamic cast is similar to static_cast except.
    nullptr can be returned when casting a pointer to an object goes wrong.
    exception can be thrown when casting a reference to an object goes wrong.
    static_cast does not perform any run-time checks.

For dynamic casting to work.
    Derived class needs to inherit Base.

There are two ways you can use dynamic casting.
    Up-casting.
        This is also an implicit type conversion.
    Down-casting.
        Not an implicit type conversion.
        Virtual function is required in Base to make Base a polymorphic type.
        Bad style because it usually doesn't make sense.
        If you down-cast, ALWAYS check the object.

    Type of polymorphism is subtype polymorphism.
    Subtype polyrmophism allows new types to use another type's functions.
        Morphing the behaviour of a function based an object's type.

Show cpp6-11.

 -->