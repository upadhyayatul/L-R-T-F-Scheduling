#include<stdio.h>

int main(){
	int arrival_time[20],burst_time[20],remain_time[20],complete_time,left=0;
	int n;
	// number of process.
	printf("enter the Number of Students:");
	scanf("%d",&n);
	
	int x,Student_id[20];
	printf("enter the ID of the Students \n");
	for(x=0;x<n;x++){
		printf("the Id of student[%d]: \n",x+1);
		scanf("%d",&Student_id[x]);
	}
	
	// arrival time and burst time input.
	int i;
	for(i=0;i<n;i++){
		printf("student[%d] \n",i+1);
		printf("enter arrival time: ");
		scanf("%d",&arrival_time[i]);
		printf("enter burst time: ");
		scanf("%d",&burst_time[i]);
		printf("\n");
		// burt time in another array for reamaining time calculation.
		remain_time[i]=burst_time[i];
	}
	
	//calculation of highest burst time and placing them in order or preemption and calculation of remaining time.
	int small,time;
	float total_wait = 0,total_turn_around = 0;
	remain_time[19]=0;
	for(time = 0;left != n;time++){
		small = 19;
		for(i=0;i<n;i++){
			if(arrival_time[i]<=time && burst_time[i]>remain_time[small] && remain_time[i]>0){
				small = i;     
			}
		}
		//decrementing the remaining time of the present process.
		remain_time[small]--;
		//when the remaining time of the process becomes zero then we calculate its completion time, waiting time and turn around time.
		if(remain_time[small]==0){
			left++;
			//completeion time of each process.
			complete_time = time ++;
			//calculation of turn around time.
			total_turn_around += complete_time - arrival_time[small];
			//calculation of waiting time. 
			total_wait += complete_time - arrival_time[small] - burst_time[small];
			
		}
	}
	
    //calculation of average waiting and turn around time.
	printf("the total turn around time is: %f \n",total_turn_around/n);
	printf("the total waiting time is: %f",total_wait/n);
}
