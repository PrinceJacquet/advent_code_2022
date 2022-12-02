//find max

#include <stdio.h>
#include <stdlib.h>

int calculate_score(char opp ,char me){
    int tab[5]={0,1,2,3,1};
    int me_val = (int)me - 39 ;
    int opp_val = (int)opp - 16;
    if(me_val == opp_val){
    	return (3 + me_val);
    }
    if(tab[me_val] == tab[opp_val+1]){
	return (6 + me_val);
    }else {
    	return me_val;
    }
}

int main (){
    long long int gen_max[3] ={0}, lcl_max =0, temp =0, opp =0, cmp =0;
    char line_rd[100] = {0};
    int line_nbr = 10;
    FILE *fptr;

    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_2\\input.txt","r");

    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    int i = 0;

    while( fgets(line_rd,line_nbr,fptr) != NULL){
        cmp = sscanf(line_rd,"%c %c",&opp, &temp);
        printf("------------error = %d \n",cmp);
        if(cmp>0 && cmp != EOF){
            printf("line_rd = %s --",line_rd);
            printf("value = %d \n",temp);
            lcl_max += calculate_score(opp,temp);
             printf("lcl_max = %d \n",lcl_max);
        }else{
            break;
        }
        //printf("total_read = %d --'\n'", sscanf(line_rd,"%d",&temp));
    }
    
    fclose(fptr);
    return 0;

   
}
