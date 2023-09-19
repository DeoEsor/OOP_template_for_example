#include <iostream>
#include <typeinfo>

long long int check_num(std::string line) {
   long long int num;
   try {
      num = std::stoll(line);
   } catch (const std::exception) {
      return -3;
   }

   if (num < 0) return -1;
   return num;
}
bool compare_nums(long long int num1, long long int num2) {
   if (num2 <= num1) return false;
   return true;
}

long long int bin(long long int num) {
   long long int result{0}, position{1};

   while (num > 0) {
      result += num % 2 * position;
      num /= 2;
      position *= 10;
   }

   return result;
}

long long int count(long long int bin_number) {
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

long long int sum_bin(long long int a, long long int b) {

   long long int sum{0};

   while (a <= b) {
      sum += count(bin(a));
      a += 1;
   }

   return sum;
}

std::string check_error(long long int err_code) {
   switch (err_code) {
      case -1:
         return "Number must be unsignused";

      case -2:
         return "Number \"b\" must be more than number \"a\"";

      case -3:
         return "Please, input number, not string";

      default:
         return "";
   }
}

long long int lab0(std::string a, std::string b) {
   long long int num1, num2;
   num1 = check_num(a);
   if (num1 < 0) return num1;

   num2 = check_num(b);
   if (num2 < 0) return num2;
   if (compare_nums(num1, num2)) return sum_bin(num1, num2);
   return -2;
}