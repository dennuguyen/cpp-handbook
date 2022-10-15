-------------------
marp: true
theme: black
class: invert
paginate: true
-------------------

# C++

Templates

<!--


-->

-------------------
## Learning Outcomes

- Understand what typename keyword is.
- Understand what templates are and how they are implemented in classes and functions.
- Understand the different types of template parameters i.e. type, non-type, template.
- Can use default template arguments.
- Understand the importance of the inclusion compilation model.

-------------------
## Learning Outcomes

- Understand the purpose of partial template specialisation and how it is implemented.
- Understand the purpose of explicit template specialisation and how it is implemented.
- Understand what variadic templates are and how it is implemented.
- Understand what decltype keyword is and its applications.

-------------------
## Typename

Declare that something is a type.

```cpp
using type_t = typename std::unordered_map<int, int>
type_t my_map;  // type_t is std::unordered_map.
```

<!-- 

This will be used frequently throughout templates.

It literally states that whatever follows is a type.

 -->

-------------------
## Templates

Templates are not new, recall STL library.
```cpp
std::vector<double> v1;
std::vector<int> v2;
std::vector<std::string> v3;

// Possible std::vector header.
template<typename T>
class vector {...};
```

Templates enable *parametric polymorphism* which gives support for other types generically.

-------------------
### Function Templates

Instead of function overloading, templates allow a generic `multiply` function which takes in any datatype.

```cpp
template<typename T>                    // T is a template type parameter.
T multiply(T a, T b) { return a * b; }  // Provided T::operator* is defined.

auto m = multiply<int>(2, 3); // Using templated function.
```

<!-- 

Templates can be applied to functions.

Recall function overloading, you'd have to create a new function signature for each datatype you want to support.
    Templates turn all of that into boilerplate.
    Much easier to maintain code and cleaner.

How do templates actually work?
    Compiler will generate an overload of your template function/class at COMPILE-TIME.

 -->

-------------------
### Class Templates

Templates can be applied to classes.

```cpp
template<typename T>
class stack {
public:
    void push(T t);
    T pop();

    template<typename U>
    void some_templated_method(U u);

private:
    std::vector<T> list_;
};

stack<int> l;  // Instantiating templated class.
```

<!-- 

Templates can be applied to classes.

Can have templated functions within templated classes.
    Note that type parameters must be different i.e. cannot use same symbols.

Show cpp8-01.

 -->

-------------------
### Type Template Parameters

Type parameters specify an unknown type.

```cpp
template<typename A, typename B, class C>
class MyClass {...};

auto m = MyClass<int, float, std::vector<int>>();
```

`typename` and `class` are equivalent.

<!-- 

The template parameters A, B, C together make up the template parameter list.

Typename and class are equivalent.
    Typename was introduced later to reduce confusion behind the use of class keyword in templates.
    Class is still in the standard to maintain backwards compatability.

 -->

-------------------
### Non-Type Template Parameters

Non-type parameters specify a known type with unknown value.

```cpp
template<std::size_t size, int num>
class MyClass {...};

auto m = MyClass<3>();  // Instantiating templated class.
```

<!-- 

Can use templates to specify a known type but with an unknown value.

Especially useful when dealing with containers with a fixed size.

When to use non-type template parameters?
    It's pretty good for fixing the size of the container.
    Think about std::array.

Show cpp8-02.

 -->

-------------------
### Default Template Arguments

Template parameters can have a default type or value.

```cpp
template<typename A = std::string, int length = 3>
class MyClass {...};

auto m1 = MyClass<>();            // A = int, length = 3.
auto m2 = MyClass<double>();      // A = double, length = 3.
auto m3 = MyClass<double, 21>();  // A = double, length = 21.
auto m4 = MyClass<, 21>();        // Illegal.
```

<!-- 

Templates can have default arguments for both type and non-type parameters.

Show cpp8-03.

 -->

-------------------
### Template Template Parameters

Template template parameters specify a template.

```cpp
template <template <typename> typename U, typename V>
struct array {
    U<V> type_;
};
```

Use when your template parameter depends on another template parameter.

<!-- 

It is possible to have a template as a template parameter.

U is dependent on V to be fully defined.

Show cpp8-04.

 -->

-------------------
## Inclusion Compilation Model

Anything templated must be fully defined in the header file.

Give compiler access to everything at compile-time to generate required template instantiations.

<!-- 

The inclusion compilation model states that your templates should be defined/implemented in the header file.

Typical compilation flow for a function is.
    Compiler parses header files and source files to build a list of functions that have been declared.

    Linker then links the function declarations with their implementations.

Compilation flow for templated functions.
    Templated functions need to be defined in the header.

    Compiler can see entire template definition and instantiate templates when required for any type.

    When definition is separated, compiler will not know what the implementation is, and required instantiations of templates will not generated by the linker time.

 -->

-------------------
## Partial Template Specialisation

Can provide specialised behaviour by partially filling out the template parameter list with known types.

```cpp
template<typename U, typename V>  // Primary template.
class MyClass {...};

template<typename U>          // Partial template specialisation.
class MyClass<U, int> {...};  // This will be used if V is an int.

template<typename U, typename V>  // Partial template specialisation.
class MyClass<U*, V> {...};       // This will be used if U is U*.
```

Can only be used for classes.

*Partial ordering* states that if there exists multiple matching partial specialisations, the more specialised template is used.

<!-- 

What if you know some types of your parameter list and the implementation needs to be overriden?
    Partial template specialisation allows you to define more templates for the same class.

    Lets you override the generic behaviour.

    Partial template specialisation must be more specialised than the most general template.
        Partially uses the template parameter list.
        It is more specialised.

Can only apply to classes.

There is a concept called partial ordering which chooses which partial templates to use if there are multiple matching ones.
    Pick most specialised template.
    Else if no specialisations match, pick the primary template.

Show cpp8-05.

 -->

-------------------
## Explicit Template Specialisation

Same as partial template specialisation but all template arguments are provided.

```cpp
template<typename T>
class MyClass {
    T val_;
};

template<>            // Empty parameter list.
class MyClass<int> {  // Explicit specialisation for T = int.
    int val_;
};
```

<!-- 

What if you knew exactly what types you wanted?
    Can provide an empty template parameter list and specify each type.

Can apply explicit template specialisation to classes and functions.

Everything else is equivalent to partial template specialisation.

Show cpp8-06.

 -->

-------------------
## Variadic Templates

Can have a template parameter list with zero or more template parameters.

```cpp
template<typename... T>  // Variadic templates.
class MyClass {
    void foo(T...);  // Pack expansion.
};

auto m = MyClass<int, int, double, std::string>();  // Valid.
```

<!-- 

Can pass in zero or more template arguments.
    T... is a pack expansion.

This is how tuples are implemented.

Show cpp8-07.

 -->

-------------------
## Decltype

*Inspects the declared type of an entity or the type and value category of an expression.*

```cpp
int a = 3;
decltype(a) b = 10;  // b is int type.

template<typename A>
auto foo(A a) -> decltype(a);  // Trailing-return syntax.
```

Useful for declaring types that are usually difficult to declare or don't know.

<!-- 

Decltype gets declared type of some object.

Decltype is used often with templates since types can be difficult to determine or simply don't know what the type is.

This is where trailing return syntax makes sense.
    Functions are read left-to-right.
    decltype at beginning of a function does not know what the type is.

 -->
