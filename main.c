#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define TRIALS 10000  // number can be increased for better accuracy

// Fisher–Yates shuffle function
void shuffle(int deck[]) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1); // random index between 0 and i
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int deck[DECK_SIZE];
    int freq[DECK_SIZE][DECK_SIZE] = {0};  // freq[card][position]

    srand(time(NULL));

    for (int t = 0; t < TRIALS; t++) {

        // Initialize deck as 1 to 52
        for (int i = 0; i < DECK_SIZE; i++)
            deck[i] = i + 1;

        // Perform shuffle
        shuffle(deck);

        // Log frequencies
        for (int pos = 0; pos < DECK_SIZE; pos++) {
            int card = deck[pos] - 1; 
            freq[card][pos]++;  
        }
    }

    // Print results
    printf("=== Fair Card Shuffling Frequency Table ===\n");
    printf("Each value shows how many times a card appeared in a given position.\n\n");

    for (int card = 0; card < DECK_SIZE; card++) {
        printf("Card %2d: ", card + 1);
        for (int pos = 0; pos < DECK_SIZE; pos++) {
            printf("%4d ", freq[card][pos]);
        }
        printf("\n");
    }

    return 0;
}
