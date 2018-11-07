
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Great Hall"

int main() {
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
    G.hand[thisPlayer][2] = village;
    G.hand[thisPlayer][3] = silver;
    G.hand[thisPlayer][4] = feast;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("TEST 1: Player has 5 cards in hand before Great Hall is played\n");

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

    printf("TEST 2: Player has 1 action before Great Hall is played\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    printf("action count = %d, expected = %d\n", testG.numActions, 1);

    if (testG.numActions == 1) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }

    printf("TEST 3: Player draws a new card after playing/discarding the Great Hall card\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    printf("hand count before playing the village card:\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], 5);

    cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
    newCards = 1;

    printf("hand count after playing the village card:\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]
                                                                            + newCards - discarded);
    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }

    printf("TEST 4: Player gains 1 action after playing village card\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    printf("action count before playing the village card:\n");
    printf("action count = %d, expected = %d\n", testG.numActions, 1);

    cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
    newActions = 2;

    printf("action count after playing the village card:\n");
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions + newActions - usedActions);

    if (testG.numActions == G.numActions + newActions - usedActions) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }

    printf("TEST 5: Player gains 1 victory point from Great Hall card\n");

       memcpy(&testG, &G, sizeof(struct gameState));
       printf("victory point count from hand without Great Hall card:\n");
       testG.discardCount[thisPlayer] = 0;
       testG.deckCount[thisPlayer] = 0;
       int playerScore = scoreFor(thisPlayer, &testG);
       printf("victory point count = %d, expected = %d\n", playerScore, 0);


        memcpy(&testG, &G, sizeof(struct gameState));
        printf("victory point count from hand with Great Hall card:\n");

        testG.hand[thisPlayer][0] = great_hall;
        testG.hand[thisPlayer][1] = copper;
        testG.hand[thisPlayer][2] = copper;
        testG.hand[thisPlayer][3] = copper;
        testG.hand[thisPlayer][4] = copper;

        testG.discardCount[thisPlayer] = 0;
        testG.deckCount[thisPlayer] = 0;
        playerScore = scoreFor(thisPlayer, &testG);
        printf("victory point count = %d, expected = %d\n", playerScore, 1);

//       cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
//       newActions = 2;
//       printf("action count after playing the village card:\n");
//       printf("action count = %d, expected = %d\n", testG.numActions, G.numActions + newActions - usedActions);
       if (playerScore == 1) {
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
