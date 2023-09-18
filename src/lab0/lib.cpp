#include <iostream>
#include <string>
#include <typeinfo>

auto print(auto x) { std::cout << x << std::endl; }

auto input(std::string symbol, auto x) {
   std::cout << symbol << ": ";
   std::cin >> x;
   return x;
}

void error(int err_code) {
   switch (err_code) {
      case 0:
         print("Number must be unsignused");
         exit(0);

      case 1:
         print("Number \"b\" must be more than number \"a\"");
         exit(0);
      case 2:
         print("Please, input number, not string");
         exit(0);
      default:
         break;
   }
}

auto check_line(std::string line) {
   long long int num;
   try {
      num = std::stoll(line);
   } catch (const std::exception) {
      error(2);
   }

   if (num < 0) error(0);
   return num;
}

auto input_num(char symbol) {
   std::string line;
   long long int num;
   num = check_line(input(": ", line));
   return num;
}

auto bin(long long int num) {
   long long int result{0}, position{1};

   while (num > 0) {
      result += num % 2 * position;
      num /= 2;
      position *= 10;
   }

   return result;
}

auto count(long long int bin_number) {
   long long int result{0};

   while (bin_number) {
      if (bin_number % 10 == 1) {
         result += 1;
         bin_number -= 1;
      }
      bin_number /= 10;
   }

   return result;
}

auto sum_bin(long long int a, long long int b) {
   if (b <= a) error(1);

   long long int sum{0};

   while (a <= b) {
      sum += count(bin(a));
      a += 1;
   }

   return sum;
}

int lab0() {
   long long int a, b;

   a = input_num('a');
   b = input_num('b');
   print(sum_bin(a, b));

   return 0;
}