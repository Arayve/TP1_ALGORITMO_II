#include "strutil.h"
#include <stdio.h>
#include <stdlib.h> 


int main(){
    char* cad1 = "3hola mundo 33 que tal biena33";
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
