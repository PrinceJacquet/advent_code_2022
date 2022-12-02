//find max

#include <stdio.h>
#include <stdlib.h>

int manage_maxs(long long int top_three[],long long int lcl_max){
    long long int min =0, mid =0, max =0;
    if(lcl_max >= top_three[2] && lcl_max > top_three[1] && lcl_max > top_three[0] ){
        top_three[0] = top_three[1];
        top_three[1] = top_three[2];
        top_three[2]= lcl_max;
        return 0;
    }else if (lcl_max >= top_three[1] && lcl_max > top_three[0] ){
        top_three[0] = top_three[1];
        top_three[1]= lcl_max;
        return 0;
    }else if (lcl_max >= top_three[0] ){
        top_three[0]= lcl_max;
        return 0;
    }
    return -1;
}

int main (){
    long long int gen_max[3] ={0}, lcl_max =0, temp =0, cmp =0;
    char line_rd[100] = {0};
    int line_nbr = 10;
    FILE *fptr;

    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_1\\input.txt","r");

    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    int i = 0;
    while(1){
        lcl_max =0;
        i=0;
        while( fgets(line_rd,line_nbr,fptr) != NULL){
            cmp = sscanf(line_rd,"%d",&temp);
            printf("------------error = %d \n",cmp);
            if(cmp>0 && cmp != EOF){
                printf("line_rd = %s --",line_rd);
                printf("value = %d \n",temp);
                lcl_max += temp;
            }else{
                break;
            }
            //printf("total_read = %d --'\n'", sscanf(line_rd,"%d",&temp));

        }
        printf("lcl_max = %d \n",lcl_max);
        manage_maxs(gen_max,lcl_max);
        for(int p =0; p <=2;p++){
            printf("gen_max_%d = %d ", p, gen_max[p]); 
        }
        printf("\n\n"); 
        // if(lcl_max>gen_max) gen_max =lcl_max; 
        if(lcl_max == 0 )break;
        if(line_rd == NULL) break;
    }
    printf("gen_max = %d\n",gen_max[2]+gen_max[1]+gen_max[0]); 
    
    fclose(fptr);
    return 0;

   
}
