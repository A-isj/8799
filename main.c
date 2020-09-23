#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 32

struct LinkedList{
  char *str;
  struct LinkedList *point;
};

void dobavit(struct LinkedList **L, char *str){
    struct LinkedList *L2 = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    char *str2 = calloc(size, sizeof(char));
    strncat(str2, str, size);
    
    L2->str = str2;
    L2->point = *L;
    *L = L2;
}

struct LinkedList *udalit(struct LinkedList *L, int n){
    if(L == NULL){
        return NULL;
    }
    if(n==1){
        free(L->str);
        if(L->point == NULL){
            free(L);
            return NULL;
        } else {
            struct LinkedList *p = L->point;
            free(L);
            return p;
        }
    } else {
        n--;
        L->point = udalit(L->point, n);
    }
    return L;
}

void vivod(struct LinkedList *L){
    while(L != NULL){
        printf("%s\n", L->str);
        L = L->point;
    }
    
    
}

int main(){
    struct LinkedList *L = NULL;
    int i=0;
    while(1){
        printf("1-dobavlenie\n2-udalenie\n3-vivod\n");
        scanf("%d", &i);
        
        if(i == 1){
            printf("vvedite stroku\n");
            char str[size];
            scanf("%s", str);
            dobavit(&L, str);
        } else if(i == 2){
            printf("vvedite nomer\n");
            int n;
            scanf("%d", &n);
            L = udalit(L, n);
        } else if (i == 3){
            vivod(L);
        }
    }
    
    return 0;
}
