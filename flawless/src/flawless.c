#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfectsquare(unsigned long long  n){ //Συνάρτηση που ελέγχει αν ενάς αριθμός είναι τέλειο τετράγωνο.
    unsigned long root=(unsigned long)(sqrt(n));
        return root*root==n;  //Επιστρέφει αν το τετράγωνο της ρίζας ενός αριθμού ισούται με τον αριθμό.
}

int flawless(unsigned long long n) {
    int sum = 0; //Aρχικοποίηση του αθροίσματος των ψηφίων
    while(n!= 0) { //Οσο δεν εχουν επεξεργασθεί όλα τα ψηφία
    int digit = n%10; //Ευρεση τελευταίου ψηφίου του αριθμού
    sum += digit;
    n /= 10; ///Ενημέρωση του αριθμού αφαιρώντας το τελευταίο ψηφίο
    }
    return sum;
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


    unsigned long long FlawlessSum = 0; //Αρχικοποίηση του sum
    for (unsigned long i = (unsigned long)sqrt(lower); i <= (unsigned long)sqrt(upper); i++) {
        //Δημιουργία τετραγώνων που θα προσθεθουν στο sum(i = (long double)sqrt(lower); i <= (long double)sqrt(upper);)
            if (perfectsquare(i*i) ) { //Έλεγχος αν το i*i είναι τέλειο τετράγωνο.
                int digitsum = flawless(i*i);
                if ((digitsum * digitsum) == i*i ) { //Αν το αθροισμα των ψηφίων στο τετράγωνο είναι ισο με τον αριθμό τοτε ο αριθμός είναι αψογο τετράγωνο.
                    FlawlessSum +=i*i;
                }
            }
    }

    printf("%lld\n" ,FlawlessSum);
    return 0;
}
