//#include <stdio.h>
//#include "vrg.h"
//
//char * msg_default = "How are you?";
//#define greet(...)   vrg(greet, __VA_ARGS__)
//#define greet1(n)    greetX(n, msg_default)
//#define greet2(n, m) greetX(n, m)
//
//void greetX(char *name, char *msg) {
//    printf("Hello %s. %s\n", name, msg);
//}
//
//int main(int argc, char *argv[]) {
//    greet("Alice", "How's your day?");
//    greet("Bob"); // too lazy to think of a greeting for Bob
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct player {
    char *name;
    int scores[10];
    int length;
} ;

int main()
{

    // *********************************************

    struct player slave_context;
    //slave_context.length = 78;
    void *data_stream = (void *)-1; //(void*) &slave_context; //(void *)-1;
    //data_stream = NULL;
    struct player* new_slave_context = (struct player*)data_stream;

    if(new_slave_context){printf("%d", new_slave_context->length);}

    // *********************************************

//     int x;
//    struct player *one = (struct player*) malloc(sizeof(struct player));

//    // uncomment below, it will work
//    //one* objFinal = malloc(sizeof(one));
//    one->length = (size_t)-1; //24;
//    if (one != NULL && one->name != NULL && one->length > 1)
//    {
//        printf("%s", "great\n\n");
//    }
//
//    /* assign player name */
//    strcpy(one->name,"Billy Zlotnick");
//
//    /* create random scores */
//    srand( (unsigned)time(NULL) );
//    for( x=0; x<10; x++)
//        one->scores[x] = rand() % 100;
//
//    /* output results */
//    printf("%s's scores:\n",one->name);
//    for( x=0; x<10; x++)
//        printf(" %3d",one->scores[x]);
//    putchar('\n');

    return(0);
}