#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int* enforce_shuffle();
int* swap_shuffle();
int* fy_shuffle();

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int repeat = 1000000;
    
    /* Store data */
    FILE *fp_enf = fopen("enforce_shuffle.txt", "w");
    FILE *fp_swa = fopen("swap_shuffle.txt", "w");
    FILE *fp_fis = fopen("fisher_shuffle.txt", "w");

    /* Record data */
    int **enforce_report = malloc(52*sizeof(int*));
    int **swap_report = malloc(52*sizeof(int*));
    int **fisher_report = malloc(52*sizeof(int*));
    
    /* Initialize */
    for (int i = 0; i < 52 ; i++){
        enforce_report[i] = malloc(52*sizeof(int));
        swap_report[i] = malloc(52*sizeof(int));
        fisher_report[i] = malloc(52*sizeof(int));
    }

    /* Start simulating. */
    for (int i = 0; i < repeat; i++) {
        int *deck_enf = enforce_shuffle();
        int *deck_swa = swap_shuffle();
        int *deck_fis = fy_shuffle();
        for (int i = 0; i < 52; i++) {
            enforce_report[i][deck_enf[i]]++;            
            swap_report[i][deck_swa[i]]++;            
            fisher_report[i][deck_fis[i]]++;            
        }
    }

    /* Record the results */
    for (int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++){
            fprintf(fp_enf,"%d ", enforce_report[i][j]);        
            fprintf(fp_swa,"%d ", swap_report[i][j]);        
            fprintf(fp_fis,"%d ", fisher_report[i][j]);        
        }
        fprintf(fp_enf, "\n");
        fprintf(fp_swa, "\n");
        fprintf(fp_fis, "\n");
    } 
    return 0;
}


int* enforce_shuffle(){
    int *deck = malloc(52*sizeof(int));
    bool check[52];
    for (int i = 0; i < 52; i++) {
        check[i] = false;        
    }
    for (int i = 0; i < 52; i++) {
        bool stop = false;
        while(!stop){
            int r = rand()%52;
            if(!check[r]){
                check[r] = true;
                stop = true;
                /* printf("%d %d\n", i, r); */
                deck[i] = r;
            }
        }
    }
    return deck;
}

int* swap_shuffle(){
    int *deck = malloc(52*sizeof(int));
    for (int i = 0; i < 52; i++) {
        deck[i] = i;        
    }
    int changes = 1000;
    for (int i = 0; i < changes; i++) {
        int x = rand()%52;
        int y = rand()%52;
        int tmp = deck[x];
        deck[x] = deck[y];
        deck[y] = tmp;
    }
    return deck;
}

int* fy_shuffle(){
    int *deck = malloc(52*sizeof(int));
    for (int i = 0; i < 52; i++) {
        deck[i] = i;        
    }
    for (int i = 0; i < 52; i++) {
        int rand_to_swap = rand()%(52-i);
        int tmp = deck[51-i];
        deck[51-i] = deck[rand_to_swap];
        deck[rand_to_swap] = tmp;
    } 
    return deck;
} 
