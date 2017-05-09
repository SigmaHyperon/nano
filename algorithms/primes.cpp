#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXPRIMES 1000

void fillprimes(int *ptr);
void menu(int *primes);
void printpage();
void divideintoprimes(int *primes);
void ggt(int a, int b, int *answer);
void kgv(int a, int b);

int main(){
  int *primes = new int[MAXPRIMES];

  for(int i = 0; i<MAXPRIMES; i++){
    primes[i] = 0;
  }
  fillprimes(primes);
  menu(primes);
  return 0;
}


//Displaying the menu and taking over the choosen function
//IN: *primes <-- taking in an array of primes to work with later!
void menu(int *primes){
  int i1, i2;
  bool run = true;
  while(run){
  system("CLS");
  cout << "Please select a number..." << endl;
  printpage();
  int c;
  cin >> c;
  switch (c){
    case 0:
      run = false;
    break;
    case 1:
      divideintoprimes(primes);
    break;
    case 2:
      cout << "Enter first number" << endl;
      cin >> i1;
      cout << "Enter second number" << endl;
      cin >> i2;
      ggt(i1, i2, NULL);
      break;
    case 3:
      cout << "Enter first number" << endl;
      cin >> i1;
      cout << "Enter second number" << endl;
      cin >> i2;
      kgv(i1, i2);
    break;
  }
  system("PAUSE");
}
}

/* Calculates the least common multiple
  IN: a <-- Number 1
  IN: b <-- Number 2
  NO return!; Only Displays the answer
*/
void kgv(int a, int b){
  int *ptr = new int;
  ggt(a, b, ptr);
  int r = (a * b)/(*ptr);
  cout << r << " ist das kleinste gemeinsame Vielfache von " << a << " und " << b <<endl;
  delete ptr;
}

//Calculates the Greates common divisor
/*
  IN: a <-- Number 1
  IN: b <-- NUmber 2
  IN: *answer <-- var to store the result if needed
  If the answer is not needed just hand over NULL for *answer!
  OUT: *answer
*/
void ggt(int a, int b, int *answer){
  if(a > b){
    int t = a;
    a = b;
    b = t;
  }
  int ggt = 1;
  for(int i = 1; i < a; i++){
    if(a%i == 0 && b%i == 0){
      ggt = i;
    }
  }
  cout << ggt << " ist der groesste gemeinsame Teiler von " << a << " und " << b << endl;
  *answer = ggt;
}

//Calculates from a requested number the prime factorization
//IN: *primes <-- array of primes
//Function needs a defined var "MAXPRIMES" that stores the size of the primes array
//No return; only display the primes!
void divideintoprimes(int *primes){
  int var;
  int x;
  cout << "Please enter your number to disassemble!" << endl;
  cin >> var;
  while(var != 1){
    for(int i = 0; i < MAXPRIMES; i++){
      if(var%primes[i] == 0){
        var /= primes[i];
        cout << primes[i] << " x ";
        break;
      }
    }
  }
  cout << endl;
}

//Print the page
void printpage(){
  cout << "1 - Primfaktorzerlegung\n2 - Groesster gemeinsamer Teiler\n3 - Kleinstes gemeinsames Vielfaches\n0 - Exit" << endl;
}

//Calculates prime numbers and stores them into a given ptr-array
//IN: max --> how many primes should be calculated
//IN: *ptr --> Array to save the primes
void fillprimes(int *ptr){
  *ptr = 2;
  ptr[1] = 3;
  int c = 5;
  bool isprime = true;
  for(int i = 2; i < MAXPRIMES; i++){
    while(true){
      for(int x = 0; x < i; x++){
        if(c%ptr[x] == 0){
          isprime = false;
          break;
        }
      }
      if(isprime){
        ptr[i] = c;
        break;
      }
      isprime = true;
      c++;
    }
  }
}
