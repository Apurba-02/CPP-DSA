
//Binary Search By Recursion

#include<iostream>
using namespace std ;

int search(int arry[] , int terget , int start , int end){
     int length = sizeof(arry)/sizeof(int), middle = end + (start-end)/2;
     if(start>end){
        return -1 ;
     }

     if(terget==arry[middle]){
        return middle ;
     }

     else if(terget>arry[middle]){
        return search(arry , terget ,middle+1 , end);
     }

     else if(terget<arry[middle]){
        return search(arry , terget ,start , middle-1);
     }
}

int main(){
    int numbers[]= {1 , 7  ,9 , 11, 13 , 15 , 17 , 19 , 21 , 25} , terget ,index ;
    cout<<"Enter The number to search : \n";
    cin>>terget ;
    index= search(numbers , terget , 0 ,9 );
    if(index== -1){
        cout<<"Not Found!!" ;
    }
    else{
        cout<<"index : "<<index ;
    }
    return 0 ;
}