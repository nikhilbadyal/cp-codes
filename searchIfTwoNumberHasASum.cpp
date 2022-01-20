#include<stdio.h>
#include<iostream>
using namespace std;
int _found(int *arr,int , int size , int);
int checkSum(int *  , int , int );

int _found(int *arr,int l, int r , const int value)
{
    if(l>r) return -1;
    int mid = (l+r)/2;
    if(arr[mid]== value)
    {
        return (mid+1);
    }
    else if (arr[mid]>value)
    {
        r = mid-1;
        _found(arr,l,r,value);
    }
    else{
        l  = mid+1;
        _found(arr,l,r,value);
    }
    //return -1;
}
int checkSum(int * arr , int size , int sum)
{
    for(int i = 0 ; i< size ;++i)
    {
        int temp = sum - arr[i];
        int check = _found(arr,(i+1),size-1,temp);
        if(check != -1)
        {
                cout<<i<<"  "<<check<<"  ";
           return check;
        }
    }
    return -1;
}
int main()
{
	int arr[10];
	int i = 0;
	while(i!= 10)
	{
		arr[i] = i;
		++i;
	}
	for(i = 0;i<10;++i)
    {
        printf("%d  ",arr[i]);
    }
//	size = sizeof(arr)/sizeof(arr[0]);
	cout<<endl;
	int sum = 13;
	checkSum(arr,10,sum);
    //printf("%d\n",_found(arr,0,size-1,value) );
	return 0;
}
