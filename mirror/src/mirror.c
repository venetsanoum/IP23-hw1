#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime( long long int n){
   if(!(n % 2)){ 
    return 0;
   }
   for(int i = 3 ; i <= sqrt(n); i+=2){
    if(!(n % i)){
        return 0;
    }
   }
   return 1; //If n is not divisible by 2 and does not have other divisitors until its square root then is prime.
}

unsigned long long mirror (unsigned long long n) { //Function that returns the mirror of a number.
    unsigned long long reversed = 0; //Initialize mirror number to 0.
    unsigned long long remain ;
    while (n != 0) { //Repeat until all digits have been processed.
        remain = n % 10; //Find the last digit of n
        reversed = 10 * reversed + remain;//I multiply the reversed number by 10 and add the remainder of dividing n by 10 to create the mirror number.
        n /= 10; //I update n by removing its last digit.
    }
    return reversed; //Return mirror number.

}

 int perfectsquare(unsigned long long  n){ //Function to check if a number n is a perfect square.
    unsigned long long root=(long long)(sqrt(n));
        return root*root==n;
}




int main (int argc, char **argv) {
    if (argc != 3) {
        printf("Program needs to be called as: ./mirror lower upper\n"); //If the number of arguments is not correct the program terminates
        return 1;
    }

    unsigned long long lower = atoll(argv[1]);
    unsigned long long upper = atoll(argv[2]);


    if (lower > upper || lower < 1 || upper > 1e15) {//Out of bounds cases terminate the program with exit code 1.
            return 1;
        }


    unsigned long long sum = 0; //Initialize the sum
    for (unsigned long long i = (long double)sqrt(lower); i <= (long double)sqrt(upper); i++) {
        //Creating the squares that will be added in the sum. (i = (long double)sqrt(lower); i <= (long double)sqrt(upper);)
            if (perfectsquare(i*i) ) { //check if i squared is perfect square.
                unsigned long long mirrornumber = mirror(i*i);
                if (perfectsquare(mirrornumber)){  //check if mirror  i squared is perfect square
                    if ( (i*i) != mirrornumber )   {//check if squared i and its mirror are not palindromic
                    if (prime ((long double)sqrt(mirrornumber))){ //check if the square root of mirror number is prime
                        if (prime(i)) { //check if i is prime 
                            sum += i*i;
                        }
                    }
                    }
                }
            }

    }
    printf("%lld\n" ,sum);
    return 0;
}