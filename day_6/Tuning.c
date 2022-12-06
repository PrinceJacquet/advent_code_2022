//Supply Stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areAllDifferent( char A[14]){
    for(int i = 0; i < 13; i++){
        for(int j = i+1; j<14;j++){
            printf("comparing %c to %c -- ",A[i],A[j]);
            if(A[i] == A[j]){
                printf("\n");
                return 0;
            } 
        }
    }
    return 1;
}

int main (){
    
    long int temp = 0, max_line =0, col= 0, my_eof = 1, pos_command = 0, pos_heading =0;
    char line_rd[100] = {0}, A[14]={' '};
    int line_nbr = 15, action[3];
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_6\\input.txt","r");
    // fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_5\\test.txt","r");

    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }

    
    // int count =0;
    while(my_eof){
        
        my_eof = fgets(line_rd,line_nbr,fptr) != NULL;
        if(my_eof <= 0){break;}
        printf("line_rd = %s ",line_rd);
        // sscanf(line_rd,"%c%c%c%c",&A[0],&A[1],&A[2],&A[3]);
        for(int b =0; b<14;b++){
            A[b]=line_rd[b];
            printf("A[%d] = %c , ",b,A[b]);
        }printf("\n");

        // printf("A[0],A[1],A[2],A[3] : %c %c %c %c \n",A[0],A[1],A[2],A[3]);

        pos_heading = ftell(fptr);
        printf("pos_heading = %d\n ",pos_heading);
        if(areAllDifferent(A)){break;}
        pos_heading-=13;
        fseek(fptr,pos_heading,SEEK_SET);
        // count++;
        // if(count == 3)break;
    } 
    

    fclose(fptr);
    return 0;

   
}
