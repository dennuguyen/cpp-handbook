-------------------
marp: true
theme: owr-theme
class: invert
paginate: true
-------------------

# C++

Classes

<!--

How much do students know about classes?

Classes are an OOP concept which enables encapsulation of data.
    Makes writing code very clean and cohesive.

These slides are focused on the basics of classes and everything about how to construct them.

-->

-------------------
## Learning Outcomes

- Understand the concept of classes and its significance on encapsulation.
- Understand how to mark a method const.
- Understand how access specifiers affect class encapsulation.
- Understand this keyword and its use cases.
- Understand purpose of constructors and how to write them.
- Know what a default constructor is and how it is implicitly declared.
- Can use delegating constructors.
- Aware of implicit class conversions and how this is prevented with explicit constructors.

-------------------
## Learning Outcomes

- Can use initialiser lists to initialise objects.
- Understand purpose of destructors.
- Understand purpose of move constructor and how to implement it.
- Understand purpose of copy constructor and how to implement it.
- Understand purpose of move assignment and how to implement it.
- Understand purpose of copy assignment and how to implement it.
- Understand the purpose of default and delete keywords on constructors.
- Understand the purpose of rule of 5 and when to use this pattern.
- Understand the purpose of rule of 0 and when to use this pattern.

-------------------
## Classes

A lot more than C-style structs.

```cpp
class MyClass {
public:
    auto getVal() -> int;
};

auto main() -> int {
    MyClass myClass; // myClass is an instance of MyClass.
    myClass.getVal();
}
```

Classes are datatypes like an `int` or `bool` but with member variables and functions.

- *Instantiate*: Create an instance/object of a class.

<!-- 

Recall C.
    structs could only have data members.
    Can have member functions if you wanted to play with function pointers - too complex.

C++ introduces the concept of classes.
    Classes are user-declared datatypes which are abstract representations of some thing.

What can a class have? See example.
    Name.
    Public/private access modifiers.
    Constructors.
    Member functions.
    Member variables.

 -->

-------------------
### Member Variables

Also called attributes.

```cpp
struct Box {
    double width;
    double height;
    double length;
};
```

Accessing and modifying attributes.
```cpp
Box box;
box.width = 301.4;
std::cout << box.height;
```

<!-- 

Classes can encapsulate a bunch of member variables of any type.

In this example we have a box with a width, height, and length.

To access and modify our attributes, we use the . operator.

Should be straight-forward, no different than C structs.

 -->

-------------------
### Member Functions

Also called methods.

Methods must be declared inside the class body and can be defined inside or outside.

```cpp
class Wrench {
    bool turnClockwise(double angle) {...}  // Define inside class.
    bool turnCounterclockwise(double angle);
};

bool Wrench::turnCounterclockwise(double angle) {...}  // Define outside class.
```

Methods are used like a typical function.

```cpp
Wrench wrench;
auto flag = wrench.turnClockwise(90);
```

<!-- 

Classes lets us declare and define functions inside the class which C structs did not let us do.

This allows for better encapsulation.

We usually specify functions as public for clients and helper functions as private.

 -->

-------------------
### Const Methods

Ensure methods do not modify their objects.

```cpp
class MyClass {
    bool getValue() const { return value; }
    auto getValue() const -> bool { return value++; }  // Compiler error.
};
```

`const` keyword is used immediately after function name.

<!-- 

Methods can be marked with the const keyword.
    Ensures that the method is not allowed to modify any attributes within the object.

Always mark a method const when you know it shouldn't modify any attributes.

 -->

-------------------
### Access Specifier

Choose how members can be used outside of `MyClass`.

```cpp
class MyClass {
public:
    int a;  // Anybody can use a.
protected:
    int b;  // Only this or derived classes can use b.
private:
    int c;  // Only this class can use c.
};
```

Prefer to keep as much `private` as possible.

<!-- 

Classes have a notion of access specifiers which lets us select the visibility of our members.
    This is to promote encapsulation.
        Which is safe because less risk of unintentionally modifying the class.

There are 3 access specifiers.
    Anything declared below an access specifier belongs to that specifier until another specifier is met.

    Public: Members are visible to MyClass and anybody outside of MyClass.

    Protected: Members are visible only to MyClass and derived classes of MyClass.

    Private: Members are visibly only to MyClass.

General use of access specifiers is if a member does not need to be used by everyone then make it private.

Show cpp5-01.

Also C++ structs are identical to classes.
    The only difference
        Members are public by default in structs.
        Members are private by default in classes.

 -->

-------------------
### This

Implicit pointer to itself.
```cpp
class MyClass {
public:
    auto getObject() -> MyClass { return *this; }

    // Equivalent to "return value" as "this" is implicit.
    auto getValue() -> int { return this->value; }

private:
    int value;
};
```

Can help deal with naming conflicts.

<!-- 

We can use the "this" keyword which is literally a pointer to itself.

Useful for moving or copying this object (shown later).

Useful for resolving naming conflicts as it's possible that an argument and attribute have the same name.
    But conventionally prefer to prefix with 'm' or suffix with '_' to resolve names.

 -->

-------------------
## Constructors

Upon instantiating, constructors will initialise the object.

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

- *Initialise*: Assign an initial value upon object creation.

<!-- 

Constructors are always called when an object gets instantiated.
    It has the same name as the class.
    It does not return anything.

The job of the constructor is to initialise an object with the values you want it to have initially.

There are two main ways of giving objects their initial value.
    Assignment.
        Values get initialised in the body of the constructor.
    Initialising.
        Values get initialised before the body of the constructor.
        This is very important when you have const and reference attributes.

Show cpp5-02.
Show cpp5-03.

 -->

-------------------
### Default Constructor

Default constructor has no arguments.

```cpp
struct MyClass {
    // MyClass() {}  // Default constructor implicitly defined.
    int val;
};
```

Default constructor is implicitly defined if there are no user-defined constructors, otherwise default constructor will not be generated.

```cpp
struct MyClass {
    MyClass(int val);  // User-defined constructor.
    // MyClass() {}    // Default constructor will not be generated.
    int val;
};
```

<!-- 

Default constructors have no arguments.

This gets implicitly defined if the user does not provide any constructors.

However if the user provides constructors, the default constructor will not be generated.

Why are default constructors a thing?
    If the user does not provide any constructors then how else will the object get constructed?

Show cpp5-04.

 -->

-------------------
### Delegating Constructor

Sometimes many constructors will do the same work.

Prefer to chain constructors to reduce code duplication.

```cpp
class Graph {
public:
    Graph(Nodes n, Edges e) : Graph(n, e, Weights()) {}  // Delegating to next constructor.
    Graph(Nodes n, Edges e, Weights w) : n_(n), e_(e), w_(w) {}

private:
    Nodes n_;
    Edges e_;
    Weights w_;
};
```

<!-- 

Constructors can call other constructors in the initialiser list.
    This reduces code duplication thus more reliable, less prone to human error.

Using the above example, we introduce weights.
    We have two constructors which are doing the same thing.
    Why not delegate the work to a "more general" constructor.

Show cpp5-05.

 -->

-------------------
### Explicit Constructor

Constructors with a single parameter can be implicitly converted from the parameter type to the class type.

```cpp
class Table {
    Table(int height);
};

Table table = 3;  // Implicit type conversion from int to Table.
```

Prevent implicit type conversions with `explicit` or `auto`.

```cpp
class Table {
    explicit Table(int height);
};

Table table = 3;        // Compiler error.
auto table = Table(3);  // Is definitely a Table.
auto table = 3;         // Is an int, not a Table.
```

<!-- 

Constructors with a single parameter will cause an implicit type conversion.

Remember that implicit type conversions are frowned upon, we prefer explicit conversions.
    Safer, readability.

Simply add explicit keyword to beginning of constructor to disable implicit type conversion.

An aside
    auto helps reinforce the convention of not using implicit type conversions.

Show cpp5-06.

 -->

-------------------
## Initialiser List

`std::initializer_list` is a lightweight object that provides access to an array of objects.

```cpp
class MyClass {
    MyClass(std::initializer_list<int> const& il);
};

MyClass my_class = {"hello", "world"};
```

Can construct objects with an initialiser list.

<!-- 

Not the same as member initialiser lists as introduced earlier.

Initialiser lists are just a data that's lightweight for passing around an array of objects.

Because it's a list you use to initialise objects.

Show cpp5-07.

 -->

-------------------
## Destructor

Destructors frees an object's resources at the end of its lifetime.

```cpp
class Graph() {
public:
    ~Graph() noexcept {}
};
```

`noexcept` keyword gives us no throw guarantee.

<!-- 

The opposite of constructors.
    Free/destroy object's resources.

Destructors are always called at the end of an object's lifetime.

Constructors and destructors is what makes RAII possible.

When to define it?
    Will be answered by rule of 5 and 0.

 -->

-------------------
## Move Constructor

Moving data from an old to a newly-constructed object.

```cpp
class MyClass {
    MyClass(MyClass&& other) noexcept : data_(std::exchange(other.data_, {})) {}
};

MyClass myClass(std::move(other));
auto myClass = MyClass(std::move(other));  // Uses copy assignment.
```

Moved-from object values should be zero to ensure it is unusable.

<!-- 

Recall move semantics.

We can move an object's resources to another object upon construction.

std::exchange was made just for move constructors.

Show cpp5-08.

 -->

-------------------
## Copy Constructor

Copying data from an old to a newly-constructed object.

```cpp
class MyClass {
    MyClass(MyClass const& other) : data_(other.data_) {}
};

MyClass myClass(other);
auto myClass = MyClass(other);  // Uses copy assignment.
```

<!-- 

It's as simple as it is. Use it when you want a copy of an object.

We pass in reference because it's efficient and const because we don't want to modify other.

Show cpp5-09.

 -->

-------------------
## Move Assignment

Moving data from one object to another.

```cpp
class MyClass {
    auto operator=(MyClass&& other) noexcept -> MyClass& {
        data_ = std::exchange(other.data_, {});
        return *this;
    }
};

myClass = std::move(other);  // myClass defined somewhere earlier on.
```

<!-- 

Move an object's resources to another object using the assignment operator.

The moved-to object does not have to be newly-constructed.

It's basically the same process as move constructor but you can't use an initialiser list here.

Show cpp5-10.

 -->


-------------------
## Copy Assignment

Copying data from one object to another.

```cpp
class MyClass {
    auto operator=(MyClass const& other) -> MyClass& {
        return MyClass(other).swap(*this);
    }

    auto swap(MyClass& other) -> MyClass& {
        std::swap(data_, other.data_);
        return *this;
    }
};

myClass = other;  // myClass defined somewhere earlier on.
```

Implement copy assignment with copy-and-swap idiom.

<!-- 

Can use assignment operator to copy data from one object to another.

The copied-to object does not have to be newly-constructed.

Copy-and-swap idiom is one implementation of the copy assignment operator.
    Avoids code duplication.
    Provides strong exception guarantee.
        By performing the construction first then do the destruction of temporary object.
    Swap data with the temporary object which destructs with the old data.
    Requires you to implement your own swap function.
        Manually swap all data in your swap function.
        Cannot use std::swap on your class because std::swap uses copy assignment operator.

There are other implementations of the copy assignment but copy-and-swap idiom is the best so far.

Show cpp5-11.

 -->

-------------------
## Explicitly Defaulted & Deleted Functions

Defaulted functions will use the default implementation.

Deleted functions can prevent improper use of your class.

```cpp
class MyClass {
    MyClass() = default;                                // Declare default constructor.
    MyClass(MyClass const&) = delete;                   // Delete copy constructor.
    MyClass& operator=(MyClass &&) noexcept = default;  // Declare default move assignment.
};
```

<!-- 

Whether you make your function default or delete it really depends on your use-cases.

Maybe you have a class called Server.
    It makes no sense to have 2 servers, so to be explicit and safe, you delete your copy constructor and assignment.

 -->

-------------------
## Rule of 5

If you define or `=delete` any copy, move, or destructor function, define them all.

```cpp
class MyClass {
public:
    ~MyClass() = default;
    MyClass(MyClass const& other) {...}
    MyClass(MyClass&& other) {...}
    MyClass operator=(MyClass const& other) = default;
    MyClass operator=(MyClass&& other) = delete;
private:
    int data_;
};
```

Compiler will not implicitly define all the special functions if any one of them is already defined.

<!-- 

If you need to define any of: destructor, move constructor, copy constructor, move assignment, or copy assignment.
    Then you need to define them all.

    If you don't define them all then the functions that aren't defined will not be implicitly created for you.
        Your own custom constructors don't count to this rule.

    It's clearer what your intentions are when you define and delete functions.

Show cpp5-12.

 -->

-------------------
## Rule of 0

If you can avoid defining default operations, avoid it.

```cpp
class MyClass {
public:
    // Let the compiler implicitly define copy, move, and destructor functions.
private:
    int data_;
}
```

In other words, if you can avoid managing your own memory.

<!-- 

If you're not managing your own memory i.e. implementing RAII and using new and delete in your constructor/destructor.

Then there's no need for you to define the move constructor, copy constructor, move assignment, copy assignment, and destructors.

Let the compiler implicitly define it for you.
    Because it's simple and clean.

Show cpp5-13.

 -->
