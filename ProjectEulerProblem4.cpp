// Project Euler Problem 4
// Largest Palindrome Product

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm> 
using namespace std;

bool checkIfPalindrome(unsigned int);
unsigned int findLargestPalindromicNumber(unsigned int);

int main(){
  cout << findLargestPalindromicNumber(100) << endl; // Should be 9009
  cout << findLargestPalindromicNumber(1000) << endl; // Should be 906609
  return 0;
}

bool checkIfPalindrome(unsigned int palindromeCandidate){
  string palindromeCandidateStr = to_string(palindromeCandidate);
  string palindromeCandidateStrReversed = string(palindromeCandidateStr.rbegin(), palindromeCandidateStr.rend());
  unsigned int palindromeCandidateReversed = stoi(palindromeCandidateStrReversed);
  if(palindromeCandidate == palindromeCandidateReversed){
    return true;
  }
  else{
    return false;
  }
}

unsigned int findLargestPalindromicNumber(unsigned int upperBound){
  unsigned int candidateNow;
  unsigned int largestUntilNow = 0;
  for(unsigned int factorOne=0; factorOne < upperBound; factorOne++){
    for(unsigned int factorTwo=0; factorTwo < upperBound; factorTwo++){
      candidateNow = factorOne * factorTwo;
      if(checkIfPalindrome(candidateNow) && candidateNow > largestUntilNow){
        largestUntilNow = candidateNow;
      }
    }
  }
  return largestUntilNow;
}
