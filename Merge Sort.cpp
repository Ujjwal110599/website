#include <iostream>
using namespace std;
// O(nlogn) Out-placed.
void Merge(int arr[],int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k=0;
    int b[ub-lb+1];
    while(i<=mid && j<=ub){
        if(arr[i]>arr[j]){
            b[k] = arr[j];
            j++;
        }
        else{
            b[k] = arr[i];
            i++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k++] = arr[j++];
        }
    }
    else{
        while(i<=mid){
            b[k++] = arr[i++];
        }
    }
    for(int i=lb,k=0;i<=ub;i++,k++){
        arr[i] = b[k];
    }
}
void MergeSort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = lb+ (ub-lb)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    }
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin >> arr[i];
	}
	MergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
	    cout << arr[i] << ' ';
	}
	return 0;
}

TIME COMPLEXITY: O(nlogn)
SPACE COMPLEXITY: O(n)


