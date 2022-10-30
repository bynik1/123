#include "ctest.h"
#include "function.h"
#include <string.h>
#include <stdio.h>


CTEST(ctest, correct_move1)
{
    int Num[] = {1,2,3,4,5,6,7,8,9,10};
    int Count = 10;
    for(int i = 0;i<10;i++){
        int flag = correct_move(Num[i], Count);
        ASSERT_EQUAL(1, flag);
    } 
}

CTEST(ctest, player_move1){
    int Num[] = {1,2,3,4,5,6,7,8,9,10};
    int Count[100];
    for(int i = 0;i<100;i++){
        Count[i] = i+1;
    }

    for(int i = 0;i<10;i++){
        for(int j = i;j<100;j++){
            int count = Count[j]- Num[i];
            ASSERT_EQUAL(count, player_move(Num[i], Count[j], 1));
        }
    }
}

CTEST(ctest, comp_move1)
{
    int Num[] = {1,2,3,4,5,6,7,8,9,10};
    int Count[100];
    int count;
    for(int i = 0;i<100;i++){
        Count[i] = i+1;
    }

    for(int i = 0;i<10;i++){
        for(int j = 0;j<100;j++){
            if(Num[i] > Count[j]){
                count = Count[j];
                ASSERT_EQUAL(0, comp_move(&Num[i], Count[j]));
            }
            else{   
                count = Count[j] - Num[i];
                ASSERT_EQUAL(count, comp_move(&Num[i], Count[j]));
            } 
        }
    }
}

