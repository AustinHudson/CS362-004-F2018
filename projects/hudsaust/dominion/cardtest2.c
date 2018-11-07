
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int numFailures = 0;
    int numAdventurers = 0;
    int numCoinCards = 0;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

    G.hand[thisPlayer][0] = adventurer;
    G.hand[thisPlayer][1] = copper;
    G.hand[thisPlayer][2] = copper;
    G.hand[thisPlayer][3] = silver;
    G.hand[thisPlayer][4] = feast;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("TEST 1: Player has 5 cards in hand before adventurer is played\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], 5);

    if (testG.handCount[thisPlayer] == 5) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }

    printf("TEST 2: The player has 2 additional cards in their deck after adventurer played\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    newCards = 2;

    printf("hand count before adventurer = %d\n", testG.handCount[thisPlayer]);
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("hand count after adventurer = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]
                                                                                              + newCards - discarded);
    if (testG.handCount[thisPlayer] == testG.handCount[thisPlayer] + newCards- discarded) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }
    printf("TEST 3: The adventurer card is being discarded after being played\n");

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        newCards = 2;

        for (i = 0; i < testG.handCount[thisPlayer]; i++){
            if (testG.hand[thisPlayer][i] == adventurer){
                numAdventurers++;
            }
        }

        printf("number of adventurers in hand before play = %d, expected = 1\n", numAdventurers);

        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        numAdventurers = 0;

        for (i = 0; i < testG.handCount[thisPlayer]; i++){
                if (testG.hand[thisPlayer][i] == adventurer){
                    numAdventurers++;
                }
            }

        printf("number of adventurers in hand after play = %d, expected = 0\n", numAdventurers);

        if (numAdventurers == 0) {
            printf("PASSED\n");
            printf("-------------------------------------------\n");
        }
        else {
            numFailures++;
            printf("FAILED\n");
            printf("-------------------------------------------\n");
        }

    printf("TEST 4: The new cards in the players hand are treasure cards\n");

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        newCards = 2;

        for (i = 0; i < testG.handCount[thisPlayer]; i++){
            if ((testG.hand[thisPlayer][i] == copper) || (testG.hand[thisPlayer][i] == silver) ||
                    testG.hand[thisPlayer][i] == gold){
                numCoinCards++;
            }
        }

        printf("number of treasure cards in hand before play = %d, expected = 3\n", numCoinCards);

        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        numCoinCards = 0;

        for (i = 0; i < testG.handCount[thisPlayer]; i++){
                if ((testG.hand[thisPlayer][i] == copper) || (testG.hand[thisPlayer][i] == silver) ||
                        testG.hand[thisPlayer][i] == gold){
                    numCoinCards++;
                }
            }

        printf("number of treasure cards in hand after play = %d, expected = 5\n", numCoinCards);

        if (numCoinCards == 5) {
            printf("PASSED\n");
            printf("-------------------------------------------\n");
        }
        else {
            numFailures++;
            printf("FAILED\n");
            printf("-------------------------------------------\n");
        }


    printf("-------------------------------------------\n");
             if (numFailures == 0){
                 printf("All tests passed!\n");
             } else {
                 printf ("%d tests failed\n", numFailures);
             }
             printf("-------------------------------------------\n\n");

	return 0;
}
