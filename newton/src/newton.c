#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double polynomial (double a0, double a1, double a2, double a3, double a4, double a5, double x) { //Συνάρτηση για τη δημιουργία του f(x).
   
 return a5 * pow(x,5) + a4 * pow(x,4) + a3 * pow(x,3) +a2 * pow(x,2) +a1 * pow(x,1) +a0 ;
}

double derivative ( double a1, double a2, double a3, double a4, double a5, double x) { //Συνάρτηση για τη δημιουργία της f'(x).
       
   return 5*a5*pow(x,4) + 4*a4*pow(x,3) + 3*a3*pow(x,2) + 2*a2*pow(x,1) +a1 ;
}
//Η συνάρτηση pow()δέχεται δύο ορίσματα (τιμη βάσης και τιμή εκθέτη) και επιστρέφει τη βάση υψωμένη στον εκθέτη.




double newton (double a0, double a1, double a2, double a3, double a4, double a5, double root) {//Συνάρτηση newton.
   double fx = polynomial (a0, a1, a2, a3, a4, a5, root); //Υπολογισμός της τιμής της f(x) για x=root.
   double derivativefx = derivative (a1, a2, a3, a4, a5,root); //Υπολογισμός της τιμής της f'(x) για x=root.   
   
    int loopCount = 0; //Αρχικοποίηση του μετρητή των επαναλήψεων.
     while (loopCount < 1000) { //Όσο δεν έχουν ξεπεραστεί οι 1000 επαναλήψεις.

        if (derivativefx == 0 || isinf(root) || isnanf(root)) { //Αν f'(root) είναι μηδέν ή η ρίζα ειναι infinite ή not a number τότε ο αλγόριθμος αποκλίνει και το πρόγραμμα τυπώνει *nan*.
             
            printf("nan\n"); 
            return 0;
        }

        if (root == 0.00 && fx == 0) { // Αν η ρίζα του πολυωνύμου είναι 0 τότε τυπώνεται 0.00
         printf("0.00\n");
         return 0;
        }


        double nextroot = root - fx / derivativefx ; //Εύρεση της επόμενης ρίζας μέσω της εξίσωσης που δίνεται.
        if (fabs(nextroot - root) < 1e-6 ) { // Αν η απόλυτη τιμή της διαφοράς της επόμενης από τη προηγούμενη ρίζα είναι μικρότερη από 10^(-6),
                 //ο αλγόριθμος συγκλίνει και επιστρέφεται η ρίζα.
            return nextroot;
        }
       
        ++loopCount;
        root = nextroot; //Η ριζα που θα χρησιμοποιηθεί μετά την παραπάνω διαδικασία είναι η επόμενη ρίζα που βρέθηκε. 
        fx = polynomial (a0, a1, a2, a3, a4, a5, root); //Εύρεσης της νέας τιμής της f(x).
        derivativefx = derivative (a1, a2, a3, a4, a5,root); //Εύρεση της νέας τιμής της f'(x).



     }
    printf("incomplete\n"); //Εξω απο το while loop, θα έχουν ξεπεράσει οι 1000 επαναλήψεις 
    return 0;   //οπότε το πρόγραμμα τυπώνει  "incomplete"
     }
    


     int main (int argc, char **argv) {
     
        if (argc != 8) { //Αν τα ορίσματα δεν ειναι σωστα (5 συντελεστές, 1 σταθερος ορος και 1 ριζα)
            printf("Program needs to be called as: ./newton a0 a1 a2 a3 a4 a5 root \n");
            return 1;
        }
        double a0 = strtod(argv[1], NULL); //Strtod function χρειάζεται 2 ορίσματα οπότε ως δεύτερο χρησιμοποιείται το NULL,
        double a1 = strtod(argv[2], NULL); //που δεν παραποιει το αποτέλεσμα.
        double a2 = strtod(argv[3], NULL);
        double a3 = strtod(argv[4], NULL);
        double a4 = strtod(argv[5], NULL);
        double a5 = strtod(argv[6], NULL);
        double root = strtod(argv[7], NULL);

    double result = newton (a0, a1,a2,a3,a4,a5,root); //Κλήση της συνάρτησης newton.
    if (result != 0) { 
      if (isinf(result) || isnan(result)) { //Αν το αποτέλεσμα ειναι infinite ή not a number τότε ο αλγόριθμος αποκλίνει.
         printf("nan\n");
      }else { //Αν δεν ισχύει το nan ή το incomplete(2 από 3 συνθήκες τερματισμού) τυπώνεται η ρίζα με ακρίβεια 2 δεκαδικών ψηφίων.
         printf("%.2f\n" ,result); //.2 είναι για την ακρίβεια 2 δεκαδικών ψηφίων. 
      }
    return 0;

     }
     }

