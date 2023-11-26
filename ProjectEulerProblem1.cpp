// Project Euler Problem 1
// Problem 1

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

bool checkIfMultipleOf3Or5(int);
int sumUpMultiples(int);

int main(){
  int result10 = sumUpMultiples(10);
  std::cout << result10 << std::endl; // Should be 23
  int result1000 = sumUpMultiples(1000);
  std::cout << result1000 << std::endl; // Should be 233168
  return 0;
}

bool checkIfMultipleOf3Or5(int someInt){
  bool is_multiple = false;
  if(someInt % 3 == 0 || someInt % 5 == 0){
    is_multiple = true;
  }
  return is_multiple;
}

int sumUpMultiples(int upperBound){
  int natNumberNow = 1;
  int summed = 0;
  while(natNumberNow < upperBound){
    if(checkIfMultipleOf3Or5(natNumberNow)){
      summed += natNumberNow;
      natNumberNow += 1;
    }
    else{
      natNumberNow += 1;
    }
  }
  return summed;
}
