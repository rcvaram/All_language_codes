#include <iostream>

using namespace std;

/***


function recieves array of integers its length and the integer whose index is to be found
-1 is returned if no element matching to requiered is found



***/
int linear_search(int *arr,int length,int key){

if (length==0)
return -1;  //not found

else if (arr[length-1]==key){

return length-1;   // returning index
}
else{
return linear_search(arr,length-1,key);

}


}
