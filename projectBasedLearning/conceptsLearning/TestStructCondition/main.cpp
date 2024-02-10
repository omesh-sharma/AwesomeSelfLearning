//// C++ program to illustrate the
//// element access in vector
//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	vector<int> g1;
//
//	for (int i = 1; i <= 10; i++)
//		g1.push_back(i * 10);
//
//	cout << "\nReference operator [g] : g1[2] = " << g1[2];
//
//	cout << "\nat : g1.at(4) = " << g1.at(4);
//
//	cout << "\nfront() : g1.front() = " << g1.front();
//
//	cout << "\nback() : g1.back() = " << g1.back();
//
//	// pointer to the first element
//	int* pos = g1.data();
//
//	cout << "\nThe first element is " << *pos;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    struct player {
        char name[32];
        int scores[10];
    } one;
    int x;

    /* assign player name */
    strcpy(one.name,"Billy Zlotnick");

    /* create random scores */
    srand( (unsigned)time(NULL) );
    for( x=0; x<10; x++)
        one.scores[x] = rand() % 100;

    /* output results */
    printf("%s's scores:\n",one.name);
    for( x=0; x<10; x++)
        printf(" %3d",one.scores[x]);
    putchar('\n');

    return(0);
}