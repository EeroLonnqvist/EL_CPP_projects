// Project Euler Problem 9
// Special Pythagorean Triplet

/* 
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2.
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
using namespace std;

bool checkIfConditionsFulfilled(unsigned int, unsigned int);
unsigned int findProductOfSpecialTriple(unsigned int);

int main(){
  unsigned int upperLimitNow = 1000;
  unsigned int result = findProductOfSpecialTriple(upperLimitNow);
  cout << result << endl; // Should be 31875000
  return 0;
}

bool checkIfConditionsFulfilled(unsigned int a, unsigned int b){
  unsigned int c = 1000 - (a + b);
  if(a*a + b*b == c*c){
    return true;
  }
  else{
    return false;
  }
}

unsigned int findProductOfSpecialTriple(unsigned int upperLimit){
  unsigned int b = 1;
  unsigned int product = 1;
  bool foundAlready = false;
  while(!foundAlready && b < upperLimit){
    unsigned int a = 1;
    while(a < b){
      if(checkIfConditionsFulfilled(a, b)){
        foundAlready = true;
        unsigned int c = 1000 - (a+b);
        product = a * b * c;
        cout << "a = " << a << ", b = " << b << " & c = " << c << endl;
        // Found special triplet: a = 200, b = 375 & c = 425
        return product;
      }
      else{
        a += 1;
      }
    }
    b += 1;
  }
  return product;
}