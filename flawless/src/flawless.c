#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfectsquare(unsigned long long  n){ //Συνάρτηση που ελέγχει αν ενάς αριθμός είναι τέλειο τετράγωνο.
    unsigned long root=(unsigned long)(sqrt(n));
        return root*root==n;  //Επιστρέφει αν το τετράγωνο της ρίζας ενός αριθμού ισούται με τον αριθμό.
}

int singledigits(unsigned long long n) {
    int sum = 0; //Aρχικοποίηση του αθροίσματος των ψηφίων
    while(n!= 0) { //Οσο δεν εχουν επεξεργασθεί όλα τα ψηφία
    int digit = n%10; //Ευρεση τελευταίου ψηφίου του αριθμού
    sum += digit;
    n /= 10; ///Ενημέρωση του αριθμού αφαιρώντας το τελευταίο ψηφίο
    }
    return sum;
}

unsigned long long doubledigits(unsigned long long n) {
    unsigned long long firstTwoDigits = n;
    while (firstTwoDigits >= 100) { //Αν είναι τριψήφιος αριθμός
        firstTwoDigits /= 10; //Κρατάει τα 2 πρώτα ψηφία
    }

    
    unsigned long long restDigits = n % 100; //Τα υπολοιπα ψηφία ειναι το υπολοιπο της διαιρεσης με το 100
    int sum = firstTwoDigits; //Το αθροισμα ειναι αρχικα τα 2 πρωτα ψηφία

    while (restDigits > 0) { //Χωρισμος των υπολοιπων ψηφίων οπως στη συνάρτηση singledigits
        int singleDigit = restDigits % 10;
        sum += singleDigit;
        restDigits /= 10;
    }

    return sum;
}

int DoubleDigits(unsigned long long n) {
    int sum = 0;
    if (n>999 && n <10000){ //Εφοσον ειναι τετραψήφιος αριθμός.
    int firsttwodigits = n/10; //Δυο πρωτα ψηφία
    int lasttwodigits = n %10; //Δυο τελευταία ψηφία
    sum = firsttwodigits + lasttwodigits;
    }
    return sum;
}

int TripleDigits(unsigned long long n) {
    int sum = 0;
    if(n > 999 ) {
    
    int threedigits = n / 100; //Πρωτα 3 ψηφία
    int remaindigits = n % 100; //υπολοιπα ψηφία
    sum = threedigits + remaindigits;
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
                int digitsum = singledigits(i*i);
                if((i*i) < 100){ //Αν ο αριθμός είναι διψήφιος χωρίζεται σε μονα ψηφία
                  if ((digitsum * digitsum) == i*i ) { //Αν το αθροισμα των ψηφίων στο τετράγωνο είναι ισο με τον αριθμό τοτε ο αριθμός είναι αψογο τετράγωνο.
                    FlawlessSum +=i*i;
                  }
                }else { //αλλιώς ελέγχονται και άλλες περιπτώσεις χωρισμού ψηφίων
                    int twodigitsum = doubledigits(i*i) ;
                        if (twodigitsum*twodigitsum == i*i) {
                        FlawlessSum += i*i;
                        }else {
                            int doubledigits = DoubleDigits(i*i);
                            int tripledigits = TripleDigits(i*i);
                            if((doubledigits*doubledigits == i*i) || (tripledigits*tripledigits == i*i)) {
                                FlawlessSum += i*i;
                            }
                        } 
                        

                    } 
            }
    }

    printf("%lld\n" ,FlawlessSum);
    return 0;
}
