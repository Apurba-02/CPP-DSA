
// Binary Search for 1st occurance

#include<iostream>
using namespace std ;

int search(int arry[] , int terget , int start , int end ){
    int middle = end + (start-end)/2 , index =-1 ;
    while(start<end){
        if(terget>arry[middle]){
            start=middle+1 ;
        }
        else if(terget==arry[middle]){
            index= middle;
            end= middle-1 ;
        }
        else if(terget<arry[middle]){
            end = middle-1 ;
        }
    middle = end + (start-end)/2 ;
    }
    return index ;
}

int main(){

    int arry[]={1 , 3, 3 , 7 , 7 , 7 , 9 , 11 ,11 , 15}, terget ;
    cout<<"Enter the number to search : \n" ;
    cin>>terget ;
    cout<<search(arry ,terget , 0 , 9);
    return 0;
}