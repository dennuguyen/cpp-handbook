#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << std::boolalpha;

    {  // all_of, none_of, any_of.
        auto vec = std::vector<int>({1, 1, 1});
        auto is_equal_1 = [](auto const& i){ return i == 1; };
        
        // Check all of i of vec == 1.
        std::cout << std::all_of(vec.begin(), vec.end(), is_equal_1) << std::endl;
        
        // Check none of i of vec == 1.
        std::cout << std::none_of(vec.begin(), vec.end(), is_equal_1) << std::endl;

        // Check any of i of vec == 1.
        std::cout << std::any_of(vec.begin(), vec.end(), is_equal_1) << std::endl;
    }

    {  // for_each.
        auto sentence = std::vector<std::string>({"hello", "this", "is", "a", "sentence"});
        std::for_each(sentence.begin(), sentence.end(), [](auto const& s){ std::cout << s << " "; });
        std::cout << std::endl;
        // Prefer for_each over for loops if what you want to do something to each element.

        auto str = std::string("upper");
        std::for_each(str.begin(), str.end(), [](auto& c){ c = std::toupper(c); });
        std::cout << str << std::endl;
    }

    return 0;
}