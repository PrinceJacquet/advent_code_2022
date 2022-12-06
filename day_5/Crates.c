//Supply Stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max_col(char A[100][100], int col){
    int max =0;
    for(int i = 0; i < col; i++){
        if (A[i][0] >= max) max = A[i][0]; 
    }
    return max;
}

void print_table(char A[100][100], int max_line, int col){
    
    for(int l = max_line ; l > 0; l--){
        for(int c = 0; c < col; c++){
            printf("[%c] ",A[c][l]);
        }
        printf("\n ");
    }
    for(int c = 0; c < col; c++){
            printf("[%d] ",A[c][0]);
        }
    printf("\n ");
}


void move_array_element(char A[100][100],int max_line, int col,int action[3]){

    for(int i = 0; i < action[0];i++){
        
        A[action[2]-1][A[action[2]-1][0]+1] = A[action[1]-1][A[action[1]-1][0]];

        A[action[1]-1][A[action[1]-1][0]] = ' ';

        A[action[1]-1][0]--;

        A[action[2]-1][0]++;

    }

    print_table(A, max_col(A,col), col);
}



int main (){
    
    long int temp = 0, max_line =0, col= 0, my_eof = 1, pos_command = 0, pos_heading =0;
    char line_rd[100] = {0}, A[100][100];// , B[100];
    int line_nbr = 50, action[3];

    //A = (char) calloc(2,sizeof(char));
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_5\\input.txt","r");
    // fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_5\\test.txt","r");

    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }

    while(my_eof){
        
        my_eof = fgets(line_rd,line_nbr,fptr) != NULL;
        pos_heading = ftell(fptr);
        if(my_eof <= 0){break;}
        printf("line_rd = %s ",line_rd);
        sscanf(line_rd," %d",&temp);
        printf("did i get a number : %d \n",temp);
        printf("pos_heading = %d\n strlen(line_rd) = %d ",pos_heading, strlen(line_rd));
        col = strlen(line_rd) /4;
        if(temp >0) break;
        max_line++;
        
    } 
    
    printf("max_line : %d \n",max_line);
    printf("col : %d \n",col);

    pos_command = pos_heading;
    pos_heading = 288;
    int i =1;
    while(my_eof){
        //if((pos_heading  - (i *(col * 4 + 1)) )<0) break;
        pos_heading = pos_heading - 36;
        fseek(fptr,pos_heading,SEEK_SET);
        
        for(int c =0; c < col;c++){
            my_eof = fgets(line_rd,5,fptr) != NULL;
            if(my_eof <= 0){break;}
            printf("line_rd =%s\n ",line_rd);
            sscanf(line_rd,"[%c",&A[c][i]);
            if(A[c][i] >0) A[c][0]++;
        }

        if(my_eof <= 0){break;}
        i++;
    }
    print_table(A, max_line, col);
    
        

    fseek(fptr,325,SEEK_SET);
    my_eof=1;
    while(my_eof){

        my_eof = fgets(line_rd,line_nbr,fptr) != NULL;
        if(my_eof <= 0){break;}
        printf("line_rd =%s --  test %c\n",line_rd, A[0][1]);
        sscanf(line_rd,"move %d from %d to %d",&action[0],&action[1],&action[2]);
        printf("the actions : %d %d %d \n",action[0],action[1],action[2] );
        move_array_element(A,max_line,col,action);
        

        if(my_eof <= 0){break;}
    }


    fclose(fptr);
    return 0;

   
}
