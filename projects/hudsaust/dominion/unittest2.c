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
#include "rngs.h"

int main() {
    int i;
    int numOfFailures = 0;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus, expectedScore, actualScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 6;


    printf("-------------------------------------------\n\n");
    printf("Testing scoreFor():\n\n");
    printf("-------------------------------------------\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game


    printf("Testing to see if hand score being calculated correctly (Empty deck/discard)\n\n");

    G.handCount[0] = maxHandCount;
    G.hand[0][0] = curse;
    G.hand[0][1] = estate;
    G.hand[0][2] = duchy;
    G.hand[0][3] = province;
    G.hand[0][4] = great_hall;
    G.hand[0][5] = gardens;

    G.discardCount[0] = 0;
    G.deckCount[0] = 0;

    expectedScore = 10;
    printf("Expected score value: %d\n", expectedScore);
    actualScore = scoreFor(0, &G);
    printf("Actual Score: %d\n", actualScore);
    printf ("\n\n");

    if (expectedScore == actualScore){
        printf("PASSED\n\n");
    }
    else{
        numOfFailures++;
        printf("FAILED\n\n");
    }
    printf("-------------------------------------------\n\n");

    printf("Testing to see if deck score being calculated correctly (Empty hand/discard)\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game

    G.deckCount[0] = maxHandCount;
    G.deck[0][0] = curse;
    G.deck[0][1] = estate;
    G.deck[0][2] = duchy;
    G.deck[0][3] = province;
    G.deck[0][4] = great_hall;
    G.deck[0][5] = gardens;
    G.discardCount[0] = 0;
    G.handCount[0] = 0;
    expectedScore = 10;
    printf("Expected score value: %d\n", expectedScore);
    actualScore = scoreFor(0, &G);
    printf("Actual Score: %d\n", actualScore);
    printf ("\n\n");
    if (expectedScore == actualScore){
        printf("PASSED\n\n");
    }
    else{
        numOfFailures++;
        printf("FAILED\n\n");
    }
    printf("-------------------------------------------\n\n");

    printf("Testing to see if discard score being calculated correctly (Empty deck/hand)\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game
    G.discardCount[0] = maxHandCount;
    G.discard[0][0] = curse;
    G.discard[0][1] = estate;
    G.discard[0][2] = duchy;
    G.discard[0][3] = province;
    G.discard[0][4] = great_hall;
    G.discard[0][5] = gardens;
    G.handCount[0] = 0;
    G.deckCount[0] = 0;
    expectedScore = 10;
    printf("Expected score value: %d\n", expectedScore);
    actualScore = scoreFor(0, &G);
    printf("Actual Score: %d\n", actualScore);
    printf ("\n\n");
    if (expectedScore == actualScore){
        printf("PASSED\n\n");
    }
    else{
        numOfFailures++;
        printf("FAILED\n\n");
    }


    printf("-------------------------------------------\n");
    if (numOfFailures == 0){
        printf("All tests passed!\n");
    } else {
        printf ("%d tests failed\n", numOfFailures);
    }
    printf("-------------------------------------------\n\n");


    return 0;

}