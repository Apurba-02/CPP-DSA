
//Time Complexcity : O(N)

#include<iostream>
using namespace std;
int main(){
    int arry[10] , i , x , index=-1;
    cout<<"Enter the array elements \n" ;
    for(i=0 ; i<10 ; i++){
        cin>>arry[i];
    }
    cout<< "Enter the number to search : \n" ;
    cin>>x ;
    for(i=0 ;i<10 ;i++){
        if(arry[i]==x){
            index=i ;
            cout<<x <<" is present at index "<<index ;
        }
    }
    if(index==-1){
        cout<<"Not found!!" ;
    }

    return 0;
}
