#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double polynomial (double a0, double a1, double a2, double a3, double a4, double a5, double x) { //Function to create f(x)
   
 return a5 * pow(x,5) + a4 * pow(x,4) + a3 * pow(x,3) +a2 * pow(x,2) +a1 * pow(x,1) +a0 ;
}

double derivative ( double a1, double a2, double a3, double a4, double a5, double x) { //Function to create f'(x)
    
   return 5*a5*pow(x,4) + 4*a4*pow(x,3) + 3*a3*pow(x,2) + 2*a2*pow(x,1) +a1 ;
}
// pow() function takes two arguments (base value and power value) and, returns the power raised to the base number




double newton (double a0, double a1, double a2, double a3, double a4, double a5, double root) {//Newton function that will calculate the roots of the polynomial
   double fx = polynomial (a0, a1, a2, a3, a4, a5, root); //Finding the value of f for x=root (the first root)
   double derivativefx = derivative (a1, a2, a3, a4, a5,root); //Finding the value of f' for x=root (the first root)
   
   
    int loopCount = 0; //Initialize the loop counter 
     while (loopCount < 1000) { //As long as 1000 repetitions have not been exceeded

        if (derivativefx == 0 || isinf(root) || isnanf(root)) { //If f'(root) is zero or root is infinite or is not a number then the function diverges.
             //and the program prints "nan"
            printf("nan\n"); 
            return 0;
        }

        if (root == 0.00 && fx == 0) { //if the root of the polynomial is 0 then it prints 0.00 
         printf("0.00\n");
         return 0;
        }


        double nextroot = root - fx / derivativefx ; //Finding the next root through the equation given
        if (fabs(nextroot - root) < 1e-6 ) { // If the absolute value of the difference of the next from the previous root is less than 10^-6
                 //the algorithm converges so root of the polynomial is returned
            return nextroot;
        }
       
        ++loopCount;
        root = nextroot; //The root used after the above process will be the new found root
        fx = polynomial (a0, a1, a2, a3, a4, a5, root); //Finding the new value of f.
        derivativefx = derivative (a1, a2, a3, a4, a5,root); //Finding the new value of f'



     }
    printf("incomplete\n"); //Outside the while loop, 1000 loops will have been exceeded
    return 0;   //so the program prints "incomplete"
     }
    


     int main (int argc, char **argv) {
     
        if (argc != 8) { //If the arguments are not correct (6 factors and 1 root)
            printf("Program needs to be called as: ./newton a0 a1 a2 a3 a4 a5 root \n");
            return 1;
        }
        double a0 = strtod(argv[1], NULL); //The strtod function needs 2 arguments so NULL is used as the second one which does not falsify the result
        double a1 = strtod(argv[2], NULL); //which does not falsify the result
        double a2 = strtod(argv[3], NULL);
        double a3 = strtod(argv[4], NULL);
        double a4 = strtod(argv[5], NULL);
        double a5 = strtod(argv[6], NULL);
        double root = strtod(argv[7], NULL);

    double result = newton (a0, a1,a2,a3,a4,a5,root); //Calling newton function
    if (result != 0) { 
      if (isinf(result) || isnan(result)) { //if result is infinite or is not a number then the function diverges.
         printf("nan\n");
      }else { //If nan and incomplete cases do not apply, i.e. 2 of the 3 termination conditions, then the result is printed
         printf("%.2lf\n" ,result); //.2 is for 2 decimal places precision
      }
    return 0;

     }
     }

