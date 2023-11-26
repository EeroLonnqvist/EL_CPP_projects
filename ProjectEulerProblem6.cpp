// Project Euler Problem 6
// Sum Square Difference

/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385.
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025.
Hence the difference between the sum of the squares of the first
ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred 
natural numbers and the square of the sum.
*/

#include <iostream>
using namespace std;

unsigned int getDifference(unsigned int);

int main(){
  cout << getDifference(10) << endl; // Should be 2640
  cout << getDifference(100) << endl; // Should be 25164150
  return 0;
}

unsigned int getDifference(unsigned int howMany){
  unsigned int sum = 0;
  unsigned int sumSquared = 0;
  for(unsigned int i = 0; i <= howMany; i++){
    sum += i;
    sumSquared += i*i;
  }
  unsigned int difference = sum*sum - sumSquared;
  return difference;
}