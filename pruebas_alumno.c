#include "strutil.h"
#include <stdio.h>
#include <stdlib.h> 


int main(){
    char* cad1 = "hola mundo que tal biena";
    char ** vec = split(cad1,'3');
    int i = 0;
    while (vec[i]){
        printf("%s\n",vec[i]);
        i++;
    }
    char* cad2 =join(vec,'3');
    printf("%s\n", cad2);

    free_strv(vec);
    free(cad2);
    
}

