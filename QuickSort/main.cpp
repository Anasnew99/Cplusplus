#include <iostream>
#include <vector>

using namespace std;
void swapElements(vector<int> &arr,int index1,int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
int PARTITION(vector<int> &arr,int lb,int ub){
	int pivot_element = arr[lb];
	int start = lb+1;
	int end = ub;
	while(start < end){
		while(arr[start] < pivot_element){
			start++;
			if(start == ub){
				break;
			}
		}
		while(arr[end]>pivot_element){
			end--;
		}
		if(end>=start){
			swapElements(arr,start,end);
		}
	}
	swapElements(arr,lb,end);
	return end;
}

void QUICK_SORT(vector<int> &arr,int lb,int ub){
	if(lb < ub){
		int position = PARTITION(arr, lb, ub);
		QUICK_SORT(arr,lb,position - 1);
		QUICK_SORT(arr,position+1,ub);
	}
}
int main(int argc, char **argv)
{
	int i{0},temp{0},n;
	vector<int> arr;
	cout<<"Enter NO oF ELEMENTS U WANT TO ENTER :=>";
	cin>>n;
	cout<<"Enter elements: => \n";
	while(i<n){
		cin>>temp;
		arr.push_back(temp);
		i++;
	}
	QUICK_SORT(arr,0,arr.size()-1);
	cout<<"\n After Sorting Using Heap Sort: ";
	for(int i:arr){
		cout<<i<<" ";
	}
	return 0;
}
