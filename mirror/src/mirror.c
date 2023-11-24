#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime (unsigned long long n){
    if (n == 1) { //1 is not prime
        return 1;
    }
    if (n == 2 || n == 3) { // 2 and 3 are prime numbers 
        return 0;
    }

    if (n % 2 == 0 || n % 3 == 0) { // If a number is divisible by 2 or 3 (and is not 2 or 3)
        return 1;   //then it is not prime. A significant amount of numbers is eliminated with this if statement.
    }

    for (unsigned long long i = 5; i * i <= n; i+=6){ //Starting from 5 because 4 is not prime and cases 1,2,3 have been checked.

         // n % i == 0: This checks if n is divisible by the value of i. 
        // n % (i + 2) == 0: This checks if n is divisible by i + 2, which is essentially checking for divisibility by the next possible divisor after i.               

        if (n % i == 0|| n % (i+2) == 0) { //for loop continues until i*i>n. Because if it has a divisor larger
            return 1;     //than its square root, it must also have a corresponding factor smaller than its square root, which means that the number is not prime. 
                          
        }
    }
    return 0;
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

unsigned long long FindRequiredRoot(unsigned long long number) {
    long double squarerootn = (long double)sqrt(number); //Find the squareroot of the number.
    if (prime(squarerootn) != 0) { //If the squareroot is not prime return 0.
        return 0; 
    }

    return number;  //Otherwise return the number
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
        //Creating the squares that will be added in the sum. (i <= (long double)sqrt(upper);)

        unsigned long long number1 = FindRequiredRoot(i*i); //Calling mirror function to check if the squareroot of i*i (which is a number in the range) is prime.
        unsigned long long reversenumber1 = mirror(i*i); //The mirror of a number (number =i*i because i create the squares that will be added)
        unsigned long long number2 = FindRequiredRoot(reversenumber1);//Calling mirror function to check if the squareroot of the mirror number is prime.



        long double squarerootn = (long double)sqrt(reversenumber1);
        if (squarerootn == floor(squarerootn)) { //Check if the mirror number is a perfect square (only if its root is an integer)
    
            if (number1 != 0  && number2 != 0   && number1 != number2) { //If the number and its mirror are prime and the number is not palindromic. 
                sum += number1; //Increase the sum by the number that is mirror prime number.
            }
        }
}
    printf("%lld\n" ,sum); 
    return 0;


}