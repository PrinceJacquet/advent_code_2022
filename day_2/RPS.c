//find max

#include <stdio.h>
#include <stdlib.h>

int calculate_score(char opp ,char me){
    int tab[5]={3,1,2,3,1};
    int me_val = (int)me - 87 ;
    int opp_val = (int)opp - 64;

    if(me_val == 2){me_val = opp_val;}
    else if(me_val == 1){me_val = tab[opp_val-1];}
    else { me_val = tab[opp_val+1];}

    printf("opp_val = %d && me_val = %d \n",opp_val,me_val);
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
    long long int gen_max[3] ={0}, lcl_max =0, cmp =0;
    char line_rd[100] = {0}, temp =0, opp =0;
    int line_nbr = 10, result;
    
    FILE *fptr;
    fptr = fopen("C:\\Users\\Prince\\Seafile\\Projects\\advent_of_code\\day_2\\input.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");   
        return(1);             
    }
    

    while( fgets(line_rd,line_nbr,fptr) != NULL){
        cmp = sscanf(line_rd,"%c %c",&opp, &temp);
        printf("------------error = %d \n",cmp);
        if(cmp){
            printf("line_rd = %s --",line_rd);
            printf("value = %c %c \n",opp,temp);
            result = calculate_score(opp,temp);
            printf("result = %d \n",result);
            lcl_max += result;
            printf("lcl_max = %d \n",lcl_max);
        }else{
            break;
        }
        //printf("total_read = %d --'\n'", sscanf(line_rd,"%d",&temp));
    }
    
    fclose(fptr);
    return 0;

   
}
