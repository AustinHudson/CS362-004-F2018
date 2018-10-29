
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int numFailures = 0;
    int numSmithy;
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

    G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = copper;
    G.hand[thisPlayer][2] = copper;
    G.hand[thisPlayer][3] = estate;
    G.hand[thisPlayer][4] = feast;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("TEST 1: Player has 5 cards in hand before smithy is played\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	newCards = 3;

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

    printf("TEST 2: Player is drawing 3 cards when playing smithy\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    newCards = 3;

    printf("Hand count before playing smithy:\n");
    printf("hand count = %d\n\n", testG.handCount[thisPlayer]);

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("Hand count after playing smithy:\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);

    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
        printf("PASSED\n");
        printf("-------------------------------------------\n");
    }
    else {
        numFailures++;
        printf("FAILED\n");
        printf("-------------------------------------------\n");
    }

    printf("TEST 3: Player has 5 cards in deck before playing card\n");

    	// copy the game state to a test case
    	memcpy(&testG, &G, sizeof(struct gameState));
    	newCards = 3;

        printf("deck count before playing smithy:\n");
    	printf("deck count = %d, expected = %d\n", testG.handCount[thisPlayer], 5);

        if (testG.handCount[thisPlayer] == 5) {
            printf("PASSED\n");
            printf("-------------------------------------------\n");
        }
        else {
            numFailures++;
            printf("FAILED\n");
            printf("-------------------------------------------\n");
        }

    printf("TEST4: Player is drawing cards from own deck\n");

    	// copy the game state to a test case
    	memcpy(&testG, &G, sizeof(struct gameState));
    	newCards = 3;

        printf("deck count before playing smithy:\n");
    	printf("deck count = %d\n", testG.deckCount[thisPlayer]);

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("deck count after playing smithy:\n");
        printf("deck count = %d, expected: < 5\n", testG.deckCount[thisPlayer]);


        if (testG.deckCount[thisPlayer] < 5) {
            printf("PASSED\n");
            printf("-------------------------------------------\n\n");
        }
        else {
            numFailures++;
            printf("FAILED\n");
            printf("-------------------------------------------\n\n");
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
