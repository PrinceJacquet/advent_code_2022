//Rucksack Reorganization

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

void common_items(char * str, char *dst, int *cmm){
    //cmm size 53 and full of zero
    int mem[53] = {0};

    for(int i =0;str[i]!='\0';i++){
        if((str[i] >= 'a') && (str[i] <= 'z')){
            mem[str[i]-'a'+1]++;
        }else{
            mem[str[i]-'A'+27]++;
        }
    }

    for(int i =0;dst[i]!='\0';i++){
        if((dst[i] >= 'a') && (dst[i] <= 'z')){
            if(mem[dst[i]-'a'+1] ){
                cmm[dst[i]-'a'+1]++;
            }
            
        }else{
            if(mem[dst[i]-'A'+27]){
                cmm[dst[i]-'A'+27]++;
            }
        }
    }

}


int calculate_priority(int *p){
    int tot_priority =0;
    for(int i =1; i<53;i++){
        if(p[i]>0){
            tot_priority+=i;
            printf("-- found cmm ! at cmm[%d] --",i);
        }
    }
    printf("line priority = %d \n", tot_priority);
    return tot_priority;
}

int main (){
    
    int max = 0, cmp =0, cmm[53]={0};
    char line_rd[100] = {0}, A[100] ={0}, *B;
    int line_nbr = 50;
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_3\\input.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    

    while( fgets(line_rd,line_nbr,fptr) != NULL){
                
        printf("line_rd = %s",line_rd);
        cmp = str_len(line_rd)/2;
        cp_string(line_rd,A,cmp);
        B=line_rd+cmp;
        B[cmp]='\0';
        printf("cmp = %d _\n A = %s && B = %s && line_rd =%s \n\n", cmp,A, B, line_rd);
        common_items(A,B,cmm);
        
        for(int k =0; k<53;k++){ printf(" -> cmm[%d] = %d \n",k,cmm[k]);}
        max += calculate_priority(cmm);
        printf("total prio = %d\n\n",max);
        for(int k =0; k<53;k++){ cmm[k]=0;}
        printf(" reset cmm[ALL] = 0! \n");

    
    }
    
    fclose(fptr);
    return 0;

   
}
