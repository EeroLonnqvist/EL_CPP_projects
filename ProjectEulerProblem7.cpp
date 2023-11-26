// Project Euler Problem 7
// 10001st Prime

/*
By listing the first six prime numbers: 2,3,5,7,11, and 13,
we can see that the 6th prime is 13.
What is the 10001st prime number?
*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkIfPrime(unsigned int);
unsigned int getNthPrime(unsigned int);

int main(){
  cout << getNthPrime(6) << endl; // Should be 13
  cout << getNthPrime(10001) << endl; // Should be 104743
  return 0;
}

bool checkIfPrime(unsigned int intToBeTested){
  if(intToBeTested == 2 || intToBeTested == 3 || intToBeTested == 5 || intToBeTested == 7){
    return true;
  } 
  else if (intToBeTested % 2 == 0){
    return false; 
  }
  else if (intToBeTested % 3 == 0){
    return false; 
  }
  else if (intToBeTested % 5 == 0){
    return false; 
  }
  else if (intToBeTested % 7 == 0){
    return false; 
  }
  else{
    unsigned int divisorTest = 3;
    unsigned int upperBound = ceil(sqrt(intToBeTested));
    if(upperBound % 2 == 0){
      upperBound += 1;
    }
    while(divisorTest <= upperBound){
      if(intToBeTested % divisorTest == 0){
        return false;
      }
      else{
        divisorTest += 2;
      }
    }
    return true;
  }
}

unsigned int getNthPrime(unsigned int N){
  unsigned int primeCounter = 0;
  unsigned int latestPrime;
  unsigned int testingNow = 2;
  while(primeCounter < N){
    if(checkIfPrime(testingNow)){
      primeCounter += 1;
      latestPrime = testingNow;
      testingNow += 1;
    }
    else{
      testingNow += 1;
    }
  }
  return latestPrime;
}
  