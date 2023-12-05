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
   return 1; //Αν ο n δεν διαιρείται με το 2 και δεν έχει άλλους διαιρέτες μέχρι τη τετραγωνική ρίζα του τοτε είναι πρώτος αριθμός(return 1) αλλιώς δεν είναι (return 0).
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
    unsigned long long root=(long long)(sqrt(n));
        return root*root==n;
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
    for (unsigned long long i = (long double)sqrt(lower); i <= (long double)sqrt(upper); i++) {
        //Δημιουργία τετραγώνων που θα προσθεθουν στο sum(i = (long double)sqrt(lower); i <= (long double)sqrt(upper);)
            if (perfectsquare(i*i) ) { //Έλεγχος αν το i*i είναι τέλειο τετράγωνο.
                unsigned long long mirrornumber = mirror(i*i);
                if (perfectsquare(mirrornumber)){  //Έλεγχος αν το κάτοπτρο του i*i είναι τέλειο τετράγωνο 
                    if ( (i*i) != mirrornumber )   {//Έλεγχος αν το i*i είναι παλλινδρομικος αριθμός.
                        if (prime ((long double)sqrt(mirrornumber))){ //Ελεγχος αν  η τετραγωνική ρίζα του κατοπτρου είναι πρώτος αριθμός 
                            if (prime(i)) { //Έλεγχος αν το i είναι πρώτος αριθμός 
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
