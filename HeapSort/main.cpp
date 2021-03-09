#include <iostream>
#include <vector>
using namespace std;
void swapElements(vector<int> &arr,int index1,int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
void MAX_HEAPIFY(vector<int> &arr,int curIndex, int size){
	int left_child = 2*curIndex;
	int right_child = 2*curIndex + 1;
	while(left_child <= size-1){
		if(right_child > size - 1){
			if(arr.at(left_child) > arr.at(curIndex)){
				swapElements(arr,left_child,curIndex);
				curIndex = left_child;				
			}else{
				break;
			}
		}else{
			if(arr[left_child]>arr[right_child]){
				if(arr.at(left_child) > arr.at(curIndex)){
					swapElements(arr,left_child,curIndex);
					curIndex = left_child;				
				}else{
					break;
				}
			}else{
				if(arr.at(right_child) > arr.at(curIndex)){
					swapElements(arr,right_child,curIndex);
					curIndex = right_child;				
				}else{
					break;
				}
			}
		}
		left_child = 2*curIndex;
		right_child = 2*curIndex + 1;
	}
}
void BUILD_MAX_HEAPIFY(vector<int> &arr,int size){
	int curIndex = size - 1;
	while(curIndex >=0){
		MAX_HEAPIFY(arr,curIndex,size);
		curIndex--;
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
	BUILD_MAX_HEAPIFY(arr,n);
	cout<<"\n Max Heap For The Given Array is: ";
	for(int i:arr){
		cout<<i<<" ";
	}
	cout<<"\n";
	i = n;
	while(i>0){
		swapElements(arr,0,i-1);
		MAX_HEAPIFY(arr,0,i-1);
		i--;
	}
	cout<<"\n After Sorting Using Heap Sort: ";
	for(int i:arr){
		cout<<i<<" ";
	}
	return 0;
}
