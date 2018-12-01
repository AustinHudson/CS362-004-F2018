#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>



int main () {

//    SelectStream(2);
//    PutSeed(3);

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int numFailures = 0;
    int numAdventurers = 0;
    int numCoinCards = 0;
    int newActions = 0;
    int usedActions = 1;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;

    int thisPlayer = 0;


   	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
   			sea_hag, tribute, smithy, council_room};

    int n;
    int p;

    int numPassed = 0;
    int numFailed = 0;

//    initializeGame(numPlayers, k, seed, &G);



        for (n = 0; n < 1; n++) {

            int numPlayers = floor(Random() * MAX_PLAYERS);
            int seed = Random() * 1000;

            struct gameState G;

            initializeGame(numPlayers, k, seed, &G);


            p = floor(Random() * numPlayers);
            G.deckCount[p] = floor(Random() * MAX_DECK+2);
            G.discardCount[p] = floor(Random() * MAX_DECK);
            G.handCount[p] = floor(Random() * MAX_HAND);

            printf("deckcount: %d, discardcount: %d, handcount: %d\n", G.deckCount[p], G.discardCount[p],
                   G.handCount[p]);

            int preHandCount = G.handCount[p];
            int preDeckCount = G.deckCount[p];
            int preDiscardCount = G.discardCount[p];

            cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);

            int postHandCount = G.handCount[p];
            int postDeckCount = G.deckCount[p];
            int postDiscardCount = G.discardCount[p];

            printf("pre: %d,  post: %d\n", preDiscardCount, postDiscardCount);
            printf("pre deck: %d,  post deck: %d\n", preDeckCount, postDeckCount);


            if ((preDeckCount - postDeckCount) == (postDiscardCount - preDiscardCount + 2)){
                printf("Correct amount being discarded and kept\n");
                if (postHandCount == preHandCount + 2){
                    printf("Draw 2 Cards Test Passed\n");
                    numPassed++;
                }else{
                    numFailed++;
                    printf("Draw 2 Cards Test Failed\n");
                }
            }
            else{
                printf("Not Enough Treasure cards to accurately test functionality.\n");
            }
        }

    printf("\n Total Test Passed: %d\n", numPassed);
    printf("\n Total Test Failed: %d\n\n", numFailed);

    return 0;
}