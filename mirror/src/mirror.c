#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime( unsigned long long n){
   if (n < 3) {
    return 1; // Το 1 και το 2 είναι πρωτοι αριθμοί
   }

   else if ((n % 2)== 0){
    return 0; // Αν ο n διαιρείται με το 2 δεν είναι πρώτος.
   }

   for(unsigned long i = 3 ; i <= (unsigned long)sqrt(n); i+=2){ //i+=2 γιατί ελέγχθηκε αν ο αριθμός είναι άρτιος.
    if((n % i) == 0){   //Αν ο n διαιρείται με κάποιον αριθμό απο το 3 μέχρι τη τετραγωνική του ρίζα δεν είναι πρωτος.
        return 0;
    }
   }
   return 1; //Είναι πρώτος.
}

unsigned long long mirror (unsigned long long n) { //Συνάρτηση που επιστρέφει το κάτοπτρο ενός αριθμού n.
    unsigned long long reversed = 0; //Αρχικοποίηση κατοπτρου σε 0
    unsigned long long remain ;
    while (n != 0) { //Επαναλαβε όσο δεν έχουν επεξεργασθεί όλα τα ψηφία 
        remain = n % 10; //Εύρεση τελευταίου ψηφίου του n.
        reversed = 10 * reversed + remain;//Πολλαπλασιαζω το κάτοπτρο με 10 και προσθέτω το τελευταίο ψηφίο του n
        n /= 10; //Ενημέρωση του n αφαιρώντας το τελευταίο ψηφίο.
    }
    return reversed; //Επιστρέφεται το κάτοπτρο. 

}

 int perfectsquare(unsigned long long  n){ //Συνάρτηση που ελέγχει αν ενάς αριθμός είναι τέλειο τετράγωνο.
    unsigned long root=(unsigned long)(sqrt(n));
        return root*root==n;  //Επιστρέφει αν το τετράγωνο της ρίζας ενός αριθμού ισούται με τον αριθμό.
}




int main (int argc, char **argv) {
    if (argc != 3) {
        printf("Program needs to be called as: ./mirror lower upper\n"); //Αν ο αριθμός των ορισμάτων δεν είναι σωστός το πρόγραμμα τερματίζει με κωδικό εξόδου 1.
        return 1;
    }

    unsigned long long lower = atoll(argv[1]);
    unsigned long long upper = atoll(argv[2]);


    if (lower > upper || lower < 1 || upper > 1e15) {//Εκτος ορίων περιπτώσεις τερματίζουν το πρόγραμμα με κωδικό εξόδου 1.
            return 1;
        }


    unsigned long long sum = 0; //Αρχικοποίηση του sum
    for (unsigned long i = (unsigned long)sqrt(lower); i <= (unsigned long)sqrt(upper); i++) {
        //Δημιουργία τετραγώνων που θα προσθεθουν στο sum(i = (long double)sqrt(lower); i <= (long double)sqrt(upper);)
            if (perfectsquare(i*i) ) { //Έλεγχος αν το i*i είναι τέλειο τετράγωνο.
                unsigned long long mirrornumber = mirror(i*i);
                if (perfectsquare(mirrornumber)){  //Έλεγχος αν το κάτοπτρο του i*i είναι τέλειο τετράγωνο 
                    if ((i*i) != mirrornumber)   {//Έλεγχος αν το i*i είναι παλινδρομικος αριθμός.
                        if (prime ((unsigned long)sqrt(mirrornumber))) {//Ελεγχος αν  η τετραγωνική ρίζα του κατοπτρου είναι πρώτος αριθμός 
                            if (prime(i)){//Έλεγχος αν το i είναι πρώτος αριθμός 
                            sum += i*i;
                            }
                        }
                    }
                }
            }

    }
    printf("%lld\n" ,sum); //Εκτύπωση του αθροίσματος.
    return 0;
}
