#include <iostream>
int findUnique(int *arr, int size)
{
     for(int i=0;i<size;i++){
        int j = 0;
        for(j=0;j<size;j++){
            if(i != j){
                if(arr[i] == arr[j]){
                    break;
                }
            }
        }
        
        if(j == size){
            return arr[i];
        }
    }
}


using namespace std;

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;
	}

	return 0;
}
