input/code.cpp: In function 'int main()':
input/code.cpp:34:9: warning: unused variable 'n' [-Wunused-variable]
   34 |     int n = (int)s.size();
      |         ^
input/code.cpp: In instantiation of 'int max_suffix(T, bool) [with T = std::__cxx11::basic_string<char>]':
input/code.cpp:21:19:   required from 'int max_cyclic_shift(T) [with T = std::__cxx11::basic_string<char>]'
input/code.cpp:26:25:   required from 'int min_cyclic_shift(T) [with T = std::__cxx11::basic_string<char>]'
input/code.cpp:35:33:   required from here
input/code.cpp:8:27: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
    8 |         for (int i = 1; i < s.size(); i++) {
      |                         ~~^~~~~~~~~~
input/code.cpp:12:38: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-com...
