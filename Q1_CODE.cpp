#include <iostream>

using namespace std;

void sort(int arr[], int size) {

    int temp = 0;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


bool check(int arr[],int size,int num){ // checks if given number is in array
	bool flag = false;

	for(int i = 0;i < size;i++){
		if(arr[i] == num)
			flag = true;
	}
	return flag;
}

void solve(int arr[],int size){
	if(size == 0)
		cout << "Empty array" << endl;
	else{
		sort(arr,size);

		int min = arr[0];
		int tmp = min;

		if(min > 0){
			for(int i = 0;i < size;i++){
			if(check(arr,size,tmp))
				tmp++;
			}
		}
		else{
			while(tmp <= 0){
				tmp++;
				if(check(arr,size,tmp))
					tmp++;
			}	

		}

		cout << "Sorted Array: " << endl;
		for(int i = 0;i < size;i++)
			cout << arr[i] << " ";
		cout << endl;

		cout << "Answer is " << tmp << endl;
	}
}


int main(){
	int N;
	cout << "Enter a number for array size: " << endl;
	cin >> N;

	int arr[N];

	for(int i = 0;i < N;i++){
		int num;
		cin >> num;
		arr[i] = num;
	}

	int size = sizeof(arr)/sizeof(arr[0]);

	solve(arr,size);

	return 0;
}
