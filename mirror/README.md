- Για την επίλυση της άσκησης 2:
    * Φτιάχνω μια συνάρτηση **prime** με την οποία ελέγχεται αν ένας αριθμός n είναι πρώτος. Αν ο αριθμός είναι 1 ή 2 τοτε είναι πρώτος (return 1). Επειτα αν διαιρείται με το 2 ή (και) έχει άλλους διαιρέτες στο εύρος [3 , τετραγωνική ρίζα n] τότε ο n **δεν** είναι πρώτος αριθμός και η συνάρτηση επιστρέφει 0. Αρκεί να ελέγξουμε για διαιρέτες μέχρι και τη τετραγωνική ρίζα του n γιατί αν ένας αριθμός έχει διαιρέτη μέχρι τη ρίζα του τότε σίγουρα έχει έναν αντίστοιχο διαιρέτη μετά τη ρίζα(επομένως αν **δεν** έχει διαιρέτες μέχρι τη ρίζα δεν θα έχει και μετά) Χρησιμοποιείται η διαίρεση με το 2 για να περιοριστούν οι έλεγχοι στο loop και να είναι πιο γρήγορο το πρόγραμμα (i+=2). 
    

    * Φτιάχνω μια συνάρτηση **mirror** η οποία επιστρέφει το κάτοπτρο ένος αριθμού. Λειτουργεί ως εξής: 
        - Αρχικοποιώ το κάτοπτρο (*reversed*) σε 0.
        - Η διαδικασία επαναλαμβάνεται όσο δεν έρχουν επεξεργαστεί όλα τα ψηφία του αριθμού: 
            - Κρατάω σε μια μεταβλητή *remain* το τελευταίο ψηφίου του αριθμού.
            - Εφόσον το τελευταίο θα γίνει πρώτο ψηφίο πολλαπλασιάζω τον αριθμό *reversed* με 10 και προσθέτουμε το *remain* (εκτος απο τη πρώτη φορα που 0 * 10 = 0 τις επόμενες τα τελευταια ψηφια πολλαπλασιάζονται επί 10 ώστε να δημιουργηθεί το κάτοπτρο του αριθμού.)
            - Ανανεώνουμε τον αριθμό n διαιρώντας τον με 10 και αφαιρώντας με αυτον τον τρόπο το τελευταίο ψηφίο το οποίο χρησιμοποιήθηκε.

    * Φτιάχνω μια συνάρτηση **perfect square** η οποία ελέγχει αν ενας αριθμός είναι τέλειο τετράγωνο. Βρίσκεται η ρίζα του αριθμού και επιστρέφεται η λογική τιμή της σχέσης *(ρίζα ενος αριθμού) ^ 2 = τον αριθμό*. Χρησιμοποιείται το (unsigned long) πρωτού τη συνάρτηση sqrt για να μετατραπεί το αποτέλεσμα απο double σε unsigned long.


    * Στη συνάρτηση **main**: 
        - Μετατρέπονται τα ορίσματα σε long long ακεραίους.
        - Ελέγχονται οι εκτός ορίων περιπτώσεις.
        - Αρχικοποιείται η μεταβλητή *sum* στην οποία θα προσθεθούν τα κατοπτρικά πρώτα τετράγωνα.
        - Το πρόγραμμα θα ***φτιάχνει*** τα κατοπτρικά πρώτα τετράγωνα και **δεν** θα τα αναζητεί (για οικονομία χρόνου) επομένως το for loop θα ξεκινάει απο τη τετραγωνική ρίζα του κάτω ορίου μέχρι και τη τετραγωνική ρίζα του άνω ορίου.
        - Eλέγχει αν το τετράγωνο του i είναι τέλειο τετράγωνο.
        - Επειτα βρίσκει το κάτοπτρο του τετραγώνου του i.
        - Ελέγχει αν το τετραγωνο του κατοπτρικού αριθμού του i είναι τέλειο τετράγωνο.
        - Ελέγχει αν το τετράγωνο του i δεν ειναι παλινδρομικός.
        - Ελέγχει αν ο i (το τετράγωνο του εν δυνάμει κατοπτρικού πρώτου τετραγώνου) ειναι πρώτος αριθμός
        - Ελέγχει αν η τετραγωνική ρίζα του κατοπτρικού αριθμού του i είναι πρώτος αριθμός
        - Εφόσον ισχύουν τα παραπάνω το τετράγωνο του αριθμού (που ειναι κατοπτρικό πρώτο τετράγωνο) προστίθεται στο *sum*.
        