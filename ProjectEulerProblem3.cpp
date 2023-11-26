// Project Euler Problem 3
// Largest Prime Factor

/*
The prime factors of 13195 are 5,7,13 and 29.
What is the largest prime factor of the number 600851475143?
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool checkPrime(unsigned int);
long getLargestPrimeFactor(long);

int main(){
  long largestPrimeFactorFor13195 = getLargestPrimeFactor(13195);
  cout << largestPrimeFactorFor13195 << endl; // Should be 29
  long largestPrimeFactorFor600851475143 = getLargestPrimeFactor(600851475143);
  cout << largestPrimeFactorFor600851475143 << endl; // Should be 6857
  return 0;
}

bool checkPrime(unsigned int intToBeTested){
  bool isPrime = true;
  long divisorTest = 3;
  while(divisorTest <= ceil(sqrt(intToBeTested))){
    if(intToBeTested % divisorTest == 0){
      isPrime = false;
    }
    divisorTest += 2;
  }
  return isPrime;
}

long getLargestPrimeFactor(long intToBeFactorized){
  bool foundIt = false;
  long largestPrimeFactor = 0;
  long possibleLargestFactor = ceil(sqrt(intToBeFactorized));
  if(possibleLargestFactor % 2 == 0){
    possibleLargestFactor += 1;
  }
  while(!foundIt && possibleLargestFactor >= 3){
    if(intToBeFactorized % possibleLargestFactor == 0 && checkPrime(possibleLargestFactor)){
      largestPrimeFactor = possibleLargestFactor;
      foundIt = true;
    }
    possibleLargestFactor -= 2;
  }
  return largestPrimeFactor;
}
