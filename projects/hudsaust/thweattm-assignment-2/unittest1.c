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

    int i, j;
    int generateCardNum;


    srand(time(0));

    int testsFailed = 0;


    //The number of cards that are passed into kingdom cards function
    const int NUM_ARGUMENTS = 10;

    int testArray [NUM_ARGUMENTS];

    // Num of possible cards that can go into kingdom cards (0-26)
    const int NUM_CARDS = treasure_map;
    printf("-------------------------------------------\n\n");
    printf("Testing kingdomCards():\n\n");
    printf("-------------------------------------------\n");

    //run 5 tests
    for (i = 0; i < 5; i++){

        printf("Testing with the following arguments: \n");
                for (j = 0; j < NUM_ARGUMENTS; j++) {
                    generateCardNum = rand() % (NUM_CARDS) + 1;
                    testArray[j] = generateCardNum;


                    printf("%d, ", generateCardNum);
                }
                printf("\n\n");

                int* kingdomCardsResults;
                printf("Expected Values of Kingdom cards array: \n");
                printf("[");
                for (j = 0; j < NUM_ARGUMENTS; j++){
                    printf("%d, ", testArray[j]);
                }
                printf("]\n");

                kingdomCardsResults = kingdomCards(testArray[0], testArray[1], testArray[2], testArray[3], testArray[4],
                                                   testArray[5], testArray[6], testArray[7], testArray[8], testArray[9]);

                printf("Actual Values after running kingdomCards(): \n");
                        printf("[");
                        for (j = 0; j < NUM_ARGUMENTS; j++){
                            printf("%d, ", kingdomCardsResults[j]);
                        }
                        printf("]\n");

                int allMatch = 1;
                for (j = 0; j < NUM_ARGUMENTS; j++){
                    if (testArray[j] != kingdomCardsResults[j]){
                        allMatch = 0;
                    }
                }

                if (allMatch == 1){
                    printf("PASSED\n");
                    printf("-------------------------------------------\n");
                }
                else{
                    printf("FAILED\n");
                    printf("-------------------------------------------\n");
                    testsFailed ++;
                }
            }


    if (testsFailed == 0){
        printf("All tests passed!\n");
    } else {
        printf ("%d tests failed\n", testsFailed);
    }
    printf("-------------------------------------------\n\n");


    return 0;
}