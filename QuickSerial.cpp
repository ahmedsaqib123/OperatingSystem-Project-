#include<iostream> 
#include<time.h>
#include<stdlib.h>
#define n 10000
using namespace std;

double RunTime=0;
void swap(int* a, int* b) 
{ 
    clock_t start,stop;
    start=clock();
    int t = *a; 
    *a = *b; 
    *b = t; 
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
	//cout<<RunTime<<"swap"<<endl;
} 
int partition (int arr[], int low, int high) 
{ 
    clock_t start,stop;
    start=clock();
    int pivot = arr[low];
	int st=low;
	int end=high;
	while(st<end)
	{
		
		while(arr[st]<=pivot)
		{
			
			st++;
		}
		while(arr[end]>pivot)
		{
			
			end--;
		}
		if(st<end)
		{
			swap(arr[st],arr[end]);
		}
	
	}
	
	swap(arr[low],arr[end]);
	
    stop=clock();
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
    return end;

} 


void quickSort(int arr[], int low, int high) 
{ 
 clock_t start, stop;
    start=clock();
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
	stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 

int main() 
{ 
	srand(time(NULL));
	int arr[n]; 
	
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
	}
	
	quickSort(arr, 0, n-1); 
	cout<<"Sorted Array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" ";
	}
	
	cout<<"Runtime: "<<RunTime<<endl;
    return 0; 
}

