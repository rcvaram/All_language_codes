#include<bits/stdc++.h>
using namespace std;

struct process{
	int arr_t, bur_t, burst, comp_t, tat, wait_t;
	string pro_id;
};

bool compare_arr_t(process a,process b)
{
	return a.arr_t<b.arr_t;
}

bool compare_bur_t(process a,process b)
{
	return a.bur_t<b.bur_t;
}

int main(){
	int n, i, t;
	cout<<"Enter the number of process:\t";
	cin>>n;
	process p[10];
	cout<<"\nEnter the arrival time and burst time respectively of each process::\n";
	for(i=0;i<n;i++){
		char c = static_cast<char>(i);
		p[i].pro_id = 'A' + c;
		cout<<"P"<<i+1<<"\tArrival Time: ";
		cin>>p[i].arr_t;
		cout<<"\tBurst Time: ";
		cin>>p[i].bur_t;
		p[i].burst = p[i].bur_t;
	}
	for(i=0;i<n;i++){
		cout<<p[i].pro_id<<" "<<p[i].arr_t<<" "<<p[i].bur_t<<"\n";
	}
	cout<<"\n";
	sort(p,p+n,compare_arr_t);
	for(i=0;i<n;i++){
		cout<<p[i].pro_id<<" "<<p[i].arr_t<<" "<<p[i].bur_t<<"\n";
	}
	int completed=0;
	while(completed!=n){
		for(i=0;i<n;i++){
			if(p[i].arr_t > t)
				break;
		}
		sort(p, p+i, compare_bur_t);
		if(i>0){
			for(int j=0;j<n;j++){
				if(p[j].bur_t != 0)
					break;
			}
			if(p[j].arr_t > t){
				t = p[j].arr_t;
			}
			p[j].comp_t = t+1;
			p[j].bur_t--;
		}
		t++;
		completed = 0;
		for(i=0;i<n;i++){
			if(p[i].bur_t == 0){
				completed++;
			}
		}
	}
	float av_tat=0, av_wait=0;
	cout<<"ProcessID\tArrivalTime\tBurstTime\tCompTime\tTurnAroundTime\tWaitingtime\n";
	for(i=0;i<n;i++)
	{
		p[i].tat = p[i].comp_t - p[i].arr_t;
		p[i].wait_t = p[i].tat - p[i].burst;
		av_tat += p[i].tat;
		av_wait += p[i].wait_t;
		cout<<p[i].pro_id<<"\t\t"<<p[i].arr_t<<"\t\t"<<p[i].burst<<"\t\t"<<p[i].comp_t<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wait_t;
		cout<<endl;
	}
	av_tat /= n;
	av_wait /= n;
	cout<<"\nAverage Waiting Time = "<<av_wait<<" , Average Turn Around Time = "<<av_tat;
	cout<<"\n";
	return 0;
}