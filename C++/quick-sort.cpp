#include<iostream>
using namespace std;

int partition(int input[], int size)
{
    int pivot = input[0];
    int k=1; //keeps track of pivot position
    for(int i=1; i<size; i++)
    {
        if(input[i] < pivot)
        {
            int temp = input[k];
            input[k++] = input[i];
            input[i] = temp;
        }
    }
    input[0] = input[k-1];
    input[k-1] = pivot;
    return k-1;
}

void quickSort(int input[], int size)
{
    if(size==0 || size==1) return ;
    int c = partition(input,size);
    quickSort(input,c);
    quickSort(input+c+1,size-c-1);
    return ;
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}
