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
    int expectedCounts [4];
    int actualCounts[4];

    int p, r, handCount;
    int bonus, expectedScore, actualScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 6;

    expectedCounts[0] = 2;
    expectedCounts[1] = 1;
    expectedCounts[2] = 3;
    expectedCounts[3] = 0;


    printf("-------------------------------------------\n\n");
    printf("Testing fullDeckCount():\n\n");
    printf("-------------------------------------------\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game


    printf("Testing to see if cards in hand being counted correctly (Empty deck/discard)\n\n");

    G.handCount[0] = maxHandCount;
    G.hand[0][0] = curse;
    G.hand[0][1] = curse;
    G.hand[0][2] = duchy;
    G.hand[0][3] = province;
    G.hand[0][4] = province;
    G.hand[0][5] = province;
    G.discardCount[0] = 0;
    G.deckCount[0] = 0;



    printf("Expected count values:\n");
    printf("curse: %d, duchy: %d, province: %d, estate: %d\n", expectedCounts[0], expectedCounts[1],
           expectedCounts[2], expectedCounts[3]);

    int countCurse = fullDeckCount(0, curse, &G);
    actualCounts[0] = countCurse;

    int countDuchy = fullDeckCount(0, duchy, &G);
    actualCounts[1] = countDuchy;

    int countProvince = fullDeckCount(0, province, &G);
    actualCounts[2] = countProvince;

    int countEstate = fullDeckCount(0, estate, &G);
    actualCounts[3] = countEstate;

    printf("Actual count values:\n");
    printf("curse: %d, duchy: %d, province: %d, estate: %d\n", countCurse, countDuchy, countProvince, countEstate);
    printf ("\n\n");

    int notEqual = 0;

    for (int i = 0; i < 4; i++){
        if (actualCounts[i] != expectedCounts[i]){
            notEqual++;
        }
    }

    if (notEqual == 0){
        printf("PASSED\n\n");
    }
    else{
        numOfFailures++;
        printf("FAILED\n\n");
    }


    printf("-------------------------------------------\n\n");

    printf("Testing to see if cards in deck being counted correctly (Empty hand/discard)\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G);     // initialize a new game

    G.deckCount[0] = maxHandCount;
    G.deck[0][0] = curse;
    G.deck[0][1] = curse;
    G.deck[0][2] = duchy;
    G.deck[0][3] = province;
    G.deck[0][4] = province;
    G.deck[0][5] = province;
    G.discardCount[0] = 0;
    G.handCount[0] = 0;



    printf("Expected count values:\n");
    printf("curse: %d, duchy: %d, province: %d, estate: %d\n", expectedCounts[0], expectedCounts[1],
           expectedCounts[2], expectedCounts[3]);

    countCurse = fullDeckCount(0, curse, &G);
    actualCounts[0] = countCurse;

    countDuchy = fullDeckCount(0, duchy, &G);
    actualCounts[1] = countDuchy;

    countProvince = fullDeckCount(0, province, &G);
    actualCounts[2] = countProvince;

    countEstate = fullDeckCount(0, estate, &G);
    actualCounts[3] = countEstate;

    printf("Actual count values:\n");
    printf("curse: %d, duchy: %d, province: %d, estate: %d\n", countCurse, countDuchy, countProvince, countEstate);
    printf ("\n\n");

    notEqual = 0;

    for (int i = 0; i < 4; i++){
        if (actualCounts[i] != expectedCounts[i]){
            notEqual++;
        }
    }

    if (notEqual == 0){
        printf("PASSED\n\n");
    }
    else{
        numOfFailures++;
        printf("FAILED\n\n");
    }

    printf("-------------------------------------------\n\n");

    printf("Testing to see if cards in discard being counted correctly (Empty deck/hand)\n\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
       initializeGame(numPlayer, k, seed, &G);     // initialize a new game

       G.discardCount[0] = maxHandCount;
       G.discard[0][0] = curse;
       G.discard[0][1] = curse;
       G.discard[0][2] = duchy;
       G.discard[0][3] = province;
       G.discard[0][4] = province;
       G.discard[0][5] = province;
       G.deckCount[0] = 0;
       G.handCount[0] = 0;



       printf("Expected count values:\n");
       printf("curse: %d, duchy: %d, province: %d, estate: %d\n", expectedCounts[0], expectedCounts[1],
              expectedCounts[2], expectedCounts[3]);

       countCurse = fullDeckCount(0, curse, &G);
       actualCounts[0] = countCurse;

       countDuchy = fullDeckCount(0, duchy, &G);
       actualCounts[1] = countDuchy;

       countProvince = fullDeckCount(0, province, &G);
       actualCounts[2] = countProvince;

       countEstate = fullDeckCount(0, estate, &G);
       actualCounts[3] = countEstate;

       printf("Actual count values:\n");
       printf("curse: %d, duchy: %d, province: %d, estate: %d\n", countCurse, countDuchy, countProvince, countEstate);
       printf ("\n\n");

       notEqual = 0;

       for (int i = 0; i < 4; i++){
           if (actualCounts[i] != expectedCounts[i]){
               notEqual++;
           }
       }

       if (notEqual == 0){
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