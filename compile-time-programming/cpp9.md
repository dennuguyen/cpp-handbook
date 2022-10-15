-------------------
marp: true
theme: black
class: invert
paginate: true
-------------------

# C++

Compile Time Programming

<!--



-->

-------------------
## Learning Outcomes

- Understand how constexpr enables compile-time programming.

-------------------
## Constexpr

Like const but expression is evaluated at compile-time.

```cpp
constexpr int a = 101;
constexpr int b = (a * 3) + 4;
constexpr unsigned factorial(unsigned n) { return n <= 1 ? 1 : (n * factorial(n-1)); }
```

No run-time cost!

Let's test with [Google Benchmark](https://github.com/google/benchmark).

<table>
    <tr>
        <th>Factorial</th>
        <th>Run-time</th>
        <th>Compile-time</th>
    </tr>
    <tr>
        <td>100</td>
        <td>369 ns</td>
        <td>3.01 ns</td>
    </tr>
    <tr>
        <td>245</td>
        <td>907 ns</td>
        <td>2.49 ns</td>
    </tr>
    <tr>
        <td>512</td>
        <td>1842 ns</td>
        <td>2.83 ns</td>
    </tr>
</table>

<!-- 

Constexpr means constant expressions CAN be evaluated at compile-time but not certainly.

Constexpr is a significant keyword for compile-time programming.
    Explored in next tutorial.

Show cpp9-01.
Show cpp9-02.

 -->