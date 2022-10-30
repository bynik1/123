#include <stdio.h>

int comp_move(int* Num, int Count)
{
	//printf("\nХОД КОМПЬЮТЕРА\n");
	if (*Num > Count) {
		*Num = Count;
	}
	Count -= *Num;
	return Count;
}

int main()
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
                if(count != comp_move(&Num[i], Count[j])){
                    printf("Count[%d] = %d &Num[%d] = %d\n", j, Count[j], i, Num[i]);    
                }
            }
            else{   
                count = Count[j] - Num[i];
                if(count != comp_move(&Num[i], Count[j])){
                    printf("Bad\n");
                }
            } 
        }
    }
}