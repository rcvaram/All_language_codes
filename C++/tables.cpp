#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number you want the table of: ";
    cin>>n;
    for(int i=1;i<=10;i++)
    {
        cout<<n<<" x "<<i<<" = "<<n*i<<endl;
    }
}
