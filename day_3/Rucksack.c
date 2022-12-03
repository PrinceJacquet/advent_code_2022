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

void common_items(char * str, char *dst, char *mid, int *cmm){
    //cmm size 53 and full of zero
    int mem[53] = {0};

    for(int i =0;str[i]!='\0';i++){
        if((str[i] >= 'a') && (str[i] <= 'z')){
            mem[str[i]-'a'+1]=1;
        }else{
            mem[str[i]-'A'+27]=1;

        }
    }

    for(int i =0;dst[i]!='\0';i++){
        if((dst[i] >= 'a') && (dst[i] <= 'z')){
            if(mem[dst[i]-'a'+1] == 1){
                mem[dst[i]-'a'+1]=2;
            }

        }else{
            if(mem[dst[i]-'A'+27]==1){
                mem[dst[i]-'A'+27]=2;
            }          
            

        }
    }

    for(int i =0;mid[i]!='\0';i++){
        if((mid[i] >= 'a') && (mid[i] <= 'z')){
            if(mem[mid[i]-'a'+1] == 2){
                cmm[mid[i]-'a'+1]=1;
            }
            
        }else{
            if(mem[mid[i]-'A'+27] ==2){
                cmm[mid[i]-'A'+27]=1;
            }
        }
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
    
    int max = 0, cmp =0, cmm[53]={0}, my_eof = 1;
    char line_rd[100] = {0}, A[3][100]={0};// , B[100];
    int line_nbr = 50;
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_3\\input.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    

    while(my_eof){
        
        int i =0;
        do{
            my_eof = fgets(line_rd,line_nbr,fptr) != NULL;
            if(my_eof <= 0){break;}
            printf("line_rd = %s ",line_rd);
            sscanf(line_rd,"%s \n",A[i]);
            printf("A[%d] = %s \n\n",i,A[i]);
            i++;
            
        }while(i<=2);

        if(my_eof <= 0){break;}

        common_items(A[0],A[1],A[2],cmm);
        
        max += calculate_priority(cmm);
        printf("total prio = %d\n\n",max);
        for(int k =0; k<=52;k++){ cmm[k]=0;}
        printf(" reset cmm[ALL] = 0! \n");

    
    }
    
    fclose(fptr);
    return 0;

   
}
