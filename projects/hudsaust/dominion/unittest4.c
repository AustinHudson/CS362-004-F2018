/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "interface.h"
#include <stdlib.h>
#include<time.h>
#include<time.h>
#include "rngs.h"

int main() {
    int i;
    int numOfFailures = 0;
    int seed = 1000;
    int numPlayer = 10;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus, expectedScore, actualScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 6;


    printf("-------------------------------------------\n\n");
    printf("Testing numHandCards():\n\n");
    printf("-------------------------------------------\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game

    srand(time(0));

    for (i = 0; i < numPlayer; i++){

        //Generate a random number between 1-50 for hand count
        int generateHandCount = rand() % 51;
        G.handCount[i] = generateHandCount;
        G.whoseTurn = i;
        int actualHandCount = numHandCards(&G);

        printf("Expected Hand Count: %d\n", generateHandCount);
        printf("Actual Hand CountL %d\n\n", actualHandCount);

        if (generateHandCount == actualHandCount){
            printf("PASSED\n");
        }else {
            printf("FAILED\n");
            numOfFailures++;
        }
        printf("-------------------------------------------\n\n");
    }

    printf("-------------------------------------------\n");
       if (numOfFailures == 0){
           printf("All tests passed!\n");
       } else {
           printf ("%d tests failed\n", numOfFailures);
       }
       printf("-------------------------------------------\n\n");

}