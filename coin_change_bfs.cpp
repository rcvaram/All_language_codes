#include <bits/stdc++.h> 
using namespace std; 
 
int minNumbers(int x, int* arr, int n) 
{ 
    queue<int> q; 
  
    q.push(x); 
  
    unordered_set<int> v; 
  
    int d = 0; 
  
    while (q.size()) { 
  
        int s = q.size(); 
        while (s--) { 
  
            int c = q.front(); 
  
            if (!c) 
                return d; 
            q.pop(); 
            if (v.find(c) != v.end() or c < 0) 
                continue; 
  
            v.insert(c); 
  
            for (int i = 0; i < n; i++) 
                q.push(c - arr[i]); 
        } 
  
        d++; 
    } 
   
    return -1; 
} 
  
// main function
int main() 
{ 
    int arr[] = { 3, 3, 4 }; 
    int n = sizeof(arr) / sizeof(int); 
    int x = 7; 
  
    cout << minNumbers(x, arr, n); 
  
    return 0; 
} 