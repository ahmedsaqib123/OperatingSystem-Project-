#include<iostream> 
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX 10000
#define THREAD_MAX 8
using namespace std;
int part=0;
int a[MAX];
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

//Partitioning with divide and conquer technique on the basis of pivot element
int partition (int low, int high) 
{ 
    clock_t start,stop;
    start=clock();
    int pivot = a[low];
	int st=low;
	int end=high;
	while(st<end)
	{
		
		while(a[st]<=pivot)
		{
			
			st++;
		}
		while(a[end]>pivot)
		{
			
			end--;
		}
		if(st<end)
		{
		
		swap(a[st],a[end]);
	}
	 }
	 swap(a[low],a[end]);
	  
    stop=clock();
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
    return end;

} 

void quickSort( int low, int high) 
{ 
	clock_t start, stop;
    start=clock();
    if (low < high) 
    { 
        int pi = partition( low, high); 
        quickSort( low, pi - 1); 
        quickSort( pi + 1, high); 
    } 
	stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 

void* quickSort(void* arg) 
{ 
	clock_t start, stop;
	start=clock();
	int thread_part=part++;
	cout<<"THread Part: "<<thread_part<<endl;
	int low=(thread_part)*(MAX/4);
	cout<<"Low: "<<low<<endl;
	int high=(thread_part+1)*(MAX/4)-1;
	cout<<"High: "<<high<<endl;
	
    if (low < high) 
    { 
        int pi = partition( low, high); 
        quickSort( low, pi - 1); 
        quickSort( pi + 1, high); 
    } 
	stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 
int main() 
{ 
	srand(time(NULL));
	for(int i=0;i<MAX;i++)
	a[i]=rand()%1000;
	pthread_t t1[THREAD_MAX];
	for (int i=0;i<4;i++)
	{ 
		pthread_create(&t1[i],NULL,quickSort,(void*)NULL);
	cout<<"i: "<<i<<endl;
	}
	for (int i=0;i<4;i++)
	{
		pthread_join(t1[i],NULL);
	}
	quickSort( 0, MAX-1); 
	cout<<"SORTED ARRAY";
	for(int i=0;i<MAX;i++)
	cout<<" "<<a[i]<<" ";
	cout<<"runtime: "<<RunTime<<endl;
	return 0; 
}

