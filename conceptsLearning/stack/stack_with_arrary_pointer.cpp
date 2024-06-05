#include<iostream>
#include <string>
using namespace std;

string *push(string arr[], int index, string value)
{

        arr[index] = value;
        //arr++;
        cout<<arr[index];
        return arr;
}


string *pop(string arr[], int size)
{
        for(int itr=0; itr<size; itr++)
        {
                cout<<arr[itr];
                
        }

}


int main()

{
int size = 2;
string arr[size];

string str;
string *newarr;

for(int itr=0; itr<size; itr++)
        {
                cin>>str; // omesh, sharma, 23, march, april
                //arr[itr] = str;
               newarr= push(arr, itr, str);
                //str.clear();  
        }
        //cout<<arr[1];
        cout<<"\n\nodone";
        pop(newarr, size);

}


