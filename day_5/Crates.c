//Supply Stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int include_part(int * A){

    if(A[0] >= A[2] && A[1] <= A[3]){
        return 1;
    }else if(A[2] >= A[0] && A[3] <= A[1]){
        return 1;
    }else{
        return 0;
    }

}

int detected_overlap(int * A){

    if((A[0] >   A[3]) || (A[1] < A[2] )){
        return 0;
    }else {
        printf("detected overlap !\n");
        return 1;        
    }

}




int main (){
    
    long int temp = 0, max_line =0, col= 0, my_eof = 1, pos_cursor = 0;
    char line_rd[100] = {0}, **A;// , B[100];
    int line_nbr = 50;

    //A = (char) calloc(2,sizeof(char));
    
    FILE *fptr;
    //fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_5\\input.txt","r");
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_5\\test.txt","r");

    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }

    pos_cursor = ftell(fptr);

    long int pos_heading =0;
    printf("pos_cursor = %d \n",pos_cursor);
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

    A = (char **) calloc(col,sizeof(char *));
    for(int i = 0; i < col; i++){
        A[i] = (char *) calloc(max_line + 1,sizeof(char));
    }
       

    
    int i =1;
    while(my_eof){
        fseek(fptr,pos_heading - (col * 4 ) - (i *(col * 4 ) ),SEEK_SET);
        for(int c =0; c < col;c++){
            my_eof = fgets(line_rd,4,fptr) != NULL;
            if(my_eof <= 0){break;}
            printf("line_rd = %s ",line_rd);
            sscanf(line_rd," [%c]",&A[c][i]);
            if(A[c][i] >0) A[c][0]++;
        }

        if(my_eof <= 0){break;}
        printf("did i get a number : %d \n",temp);
        i++;
    }

    print_table(A);

    fclose(fptr);
    return 0;

   
}
