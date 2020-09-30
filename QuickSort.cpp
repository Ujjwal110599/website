#include<bits/stdc++.h>
using namespace std ;
void swap(int *a, int *b){
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}
void display(int n, int list[] ){
cout<<"The elements after passing through QuickSort are:"<<endl;
for (int i = 0; i < n; i++)
{
	cout<<list[i]<<" ";
}
}
int PivotPartition(int low, int high, int list[]){
	int pivot = list[high];
	int i = low - 1 ;
	for (int j = low; j <= high-1; j++)
	{
		if(list[j] < pivot){
			i++;
			swap(&list[i], &list[j]);
		}
	}
	swap(&list[i+1], &list[high]);
	return (i+1);
}
void QuickSort(int low, int high, int list[]){
	int pindex ;
	if(low < high){
		pindex = PivotPartition(low, high, list);
		QuickSort(low, pindex-1, list);
		QuickSort(pindex+1, high, list);
	}
}
int main(){
	int n ;
	cout<<"Enter the size of the list:"<<endl;
	cin>>n ;
	int list[n];
	cout<<"Enter the elements of the list:"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>list[i];
	}
	cout<<"The elements you entered are:"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout<<list[i]<<" ";
	}
	QuickSort(0,n-1,list);
	cout<<"\n";
	display(n,list);

	return 0 ;
}