#include <iostream>

using namespace std;

/*int calculateSS()
{

    return 0;
}*/

int main()
{
    int NOP,NOI,i,s=0,ss=0,finish=0,k;
    cout<<"Enter The number of processes: ";
    cin>>NOP;
    cout<<"\nEnter the number of instances: ";
    cin>>NOI;
    int allocation[NOP][NOI]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}},w=NOP;
    /*int waitingQueue[NOP]; // 0 = finish & 1 = waiting*/
    int finishQueue[NOP];// 0 = not finish & 1=finish
    int maximum[NOP][NOI]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int available[NOP][NOI],tempAvail[NOI];
    int need[NOP][NOI];
    int safeSequence[NOP];
    cout<<"\nEnter allocation matrix values: ";
    for(i=0; i<NOP; i++)
    {   finishQueue[i]=0;
        cout<<"\nEnter P["<<i<<"] allocation values: ";
        for(k=0; k<NOI; k++)
        {
           // cin>>allocation[i][k];
        	//cout<<allocation[i][k]; if(k==NOI-1) cout<<endl;
            /*waitingQueue[i]=1;*/
/*            allocation[][]={
            	0,1,0,2,0,0,3,0,2,2,1,1,0,0,2
            };*/
        }
    }
    cout<<"\nEnter Max matrix values: ";
    for(i=0; i<NOP; i++)
    {
        cout<<"\nEnter P["<<i<<"] maximum values: ";
        for(k=0; k<NOI; k++)
        {
           // cin>>maximum[i][k];
        		//cout<<maximum[i][k]; if(k==NOI-1) cout<<endl;
        }
    }
    cout<<"\nEnter the value of Available resources for "<<NOI<<" Instances: ";
    for(k=0; k<NOI; k++)
    {
       cin>>available[0][k];tempAvail[k]=available[0][k];
    }
    cout<<"\nNeed Matrix : \n";
    for(i=0; i<NOP; i++)
    {
        for(k=0; k<NOI; k++)
        {
            need[i][k]=maximum[i][k]-allocation[i][k];
            cout<<need[i][k]<<"\t   ";if(k==NOI-1) cout<<endl;
        }
    }
    cout<<endl<<endl;
/*    cout<<"\nAvailable Matrix : \n";
    for(i=0; i<NOP; i++)
    {
        for(k=0; k<NOI; k++)
        {
        	cout<<available[i][k]<<" ";if(k==NOI-1) cout<<endl;
        }
    }*/
    do//P=n and I=m
    {  	
   	/*cout<<"\nfinishQueue:";
   	for(i=0;i<NOP;i++)
    {
    	cout<<finishQueue[i]<<" ";
	}*/
    for(i=0;i<NOP;i++)
    {
    	/*cout<<"\nFinish:"<<finishQueue[i]<<" \n";*/
    	if(finishQueue[i]==0) //not finished
    	{
    		for(k=0;k<NOI;k++) available[i][k]=tempAvail[k];
	    	/*for( k=0;k<NOI;k++)
	    	{
	    		cout<<need[i][k]<<":"<<available[i][k]<<" ";	
	    	}*/cout<<endl;
	    	for( k=0;k<NOI;k++)
	    	{
	    		//cout<<"\n\nI:"<<i<<" K:"<<k<<"\n\n";
	    		if(need[i][k]<=available[i][k])	s++; else break;
	    	}	
	    	//cout<<"\nS:"<<s<<"\n";
	    	if(s==NOI)
	    	{
	    		finishQueue[i]=1;
	    		safeSequence[ss]=i;ss++;w--;/*cout<<"\n\nSAFESEQUENCE["<<ss-1<<"] "<<safeSequence[ss-1]<<"\n\n";*/
	    		for(k=0;k<NOI;k++)
                {
                    tempAvail[k] = available[i][k]+allocation[i][k];
                }/*cout<<"\n\nCHANGE:W: "<<w<<" \n\n";*/
	    	}
	    	else 
	    	{/* cout<<"\n\nSAME\n\n";*/
	    		for(k=0;k<NOI;k++)
            	{
                	tempAvail[k] = available[i][k];
            	}
            }s=0;

    	}
    	else
    	{ // finished then copy the available matrix values as it is
    		finish++;
    		for( k=0;k<NOI;k++)
            {
                available[i+1][k] = available[i][k];
            }
    	}
    }
    }while(w>0);cout<<endl<<endl;
    cout<<"\nSAFE SEQUENCE\n";
    for(i=0;i<NOP;i++)
    	cout<<safeSequence[i]<<" ";
    if(finish==NOP) cout<<"\nThe system is in safe mode\n";
    else cout<<"\nThe system is not in safe mode\n"; 
    return 0;
}