//Camp Cleanup

#include <stdio.h>
#include <stdlib.h>

int str_len(char * strg){
    int i =0;
    while(strg[i]!='\0'){
        i++;
    }
    return i;
}

void cp_string(char * str, char *dst, int val){
    
    if(val){
        for(int i=0; i< val;i++){
            dst[i]=str[i];
        }
        dst[val]='\0';
    }
}

int include_part(int * A){

    if(A[0] >= A[2] && A[1] <= A[3]){
        return 1;
    }else if(A[2] >= A[0] && A[3] <= A[1]){
        return 1;
    }else{
        return 0;
    }

}


int calculate_priority(int *p){
    int tot_priority =0;
    for(int i =1; i<53;i++){
        if(p[i]){
            tot_priority+=i;
            printf("-- found cmm ! at cmm[%d] --",i);
        }
    }
    printf("line priority = %d \n", tot_priority);
    return tot_priority;
}

int main (){
    
    int sum = 0, cmp =0, cmm[53]={0}, my_eof = 1, A[4]={0};
    char line_rd[100] = {0};// , B[100];
    int line_nbr = 50;
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_4\\input.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    

    while(my_eof){
        

        my_eof = fgets(line_rd,line_nbr,fptr) != NULL;
        if(my_eof <= 0){break;}
        printf("line_rd = %s ",line_rd);
        sscanf(line_rd,"%d-%d,%d-%d",&A[0],&A[1],&A[2],&A[3]);
        for(int i =0; i<4;i++){printf("A[%d] = %d \n\n",i,A[i]);}
        sum += include_part(A);

    
    }

    printf("sum = %d ",sum);
    
    fclose(fptr);
    return 0;

   
}
