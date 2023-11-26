// Project Euler Problem 10
// Summation of Primes

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkIfPrime(const unsigned int);
unsigned long sumUpPrimes(const unsigned int);

int main() {
  cout << sumUpPrimes(10) << endl; // Should be 17
  cout << sumUpPrimes(2000000) << endl; // Should be 142913828922
  return 0;
}

bool checkIfPrime(const unsigned int intToBeTested){
  if(intToBeTested == 2 || intToBeTested == 3){
    return true;
  }
  else{
    unsigned int divisorTest = 2;
    unsigned int upperBound = ceil(sqrt(intToBeTested));
    while(divisorTest <= upperBound){
      if(intToBeTested % divisorTest == 0){
        return false;
      }
      else{
        divisorTest += 1;
      }
    }
    return true;
  }
}

unsigned long sumUpPrimes(const unsigned int upperBound){
  unsigned long sum = 0;
  unsigned int currentNatNumber = 2;
  while(currentNatNumber < upperBound){
    if(checkIfPrime(currentNatNumber)){
      sum += currentNatNumber;
    }
    currentNatNumber += 1;
  }
  return sum;
}