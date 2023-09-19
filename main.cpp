#include <iostream>
#include "lib.h"

auto print(auto x) { std::cout << x << std::endl; }

auto input(char symbol, auto x) {
   std::cout << symbol << ": ";
   std::cin >> x;
   return x;
}

int main() {

   print("lab0>>>");

   std::string a, b;
   long long int res;
   a = input('a', a);
   b = input('b', b);
   res = lab0(a, b);
   if (res < 0)
      print(check_error(res));
   else
      print(res);
   return 0;
}