#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int NOP,NOB,i,j,ch;
    cout<<"Enter The number of processes: ";
    cin>>NOP;
    cout<<"Enter the number of blocks: ";
    cin>>NOB;
    int processes[NOP];//={212,417,112,426};
    int blocks[NOB];//={100,500,200,300,600};
    int c[NOB],d[NOB],flag[NOB],alloc[NOB];
    // NOP = NOB
    cout<<"Enter Processes size: \n";
    for(i=0; i<NOP; i++)
    {
        cout<<"P["<<i<<"]: ";
        cin>>processes[i];
    }
    cout<<"\nEnter Blocks size: \n";
    for(i=0; i<NOB; i++)
    {
        cout<<"B["<<i<<"]: ";
        cin>>blocks[i];
        c[i]=blocks[i];d[i]=blocks[i];
    }

    if(NOP<=NOB)
    {
        do
        {
        cout<<"\n\n1.First fit\t2.Best fit \t3.Worst fit\t4.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nFirst Fit\n";
            for(i=0;i<NOP;i++)
            {
                for(j=0;j<NOB;j++)
                {
                    if(processes[i]<=blocks[j])
                    {
                    alloc[j]=processes[i];cout<<"\nAlloc["<<alloc[j]<<"]";
                    cout<<"\nProcess "<<i<<":"<<processes[i]<<" Block: "<<j<<": "<<blocks[j];
                    flag[i]=0,blocks[j]=0;break;
                    }
                    else flag[i]=1;
                }
            }
            for(i=0;i<NOP;i++)
            {
                if(flag[i]!=0)
                cout<<"\nProcess "<<i<<" of size "<<processes[i]<<" is not allocated\n";
            }break;

            case 2: cout<<"\nBest Fit\n";
                for(i=0;i<NOB;i++)
                {
                    for(j=i+1;j<NOB;j++)
                    {
                        if(c[i]>c[j])
                        {
                        int temp=c[i];c[i]=c[j];c[j]=temp;
                        }
                    }
                }

                for(i=0;i<NOP;i++)
                {
                    for(j=0;j<NOB;j++)
                    {
                        if(processes[i]<=c[j])
                        {
                            alloc[j]=processes[i];cout<<"\nAlloc["<<alloc[j]<<"]";
                            cout<<"\nProcess "<<i<<":"<<processes[i]<<" Block: "<<j<<": "<<c[j];
                            flag[i]=0,c[j]=0;break;
                        }else flag[i]=1;
                    }
                }
                for(i=0;i<NOP;i++)
                {
                    if(flag[i]!=0)
                   cout<<"\nProcess "<<i<<" of size "<<processes[i]<<" is not allocated\n";
                }
            break;
            case 3: cout<<"\nWorst Fit\n";
            for(i=0;i<NOB;i++)
            {
                for(j=i+1;j<NOB;j++)
                {
                    if(d[i]<d[j])
                    {
                        int temp=d[i];d[i]=d[j];d[j]=temp;
                    }
                }
            }
            for(i=0;i<NOP;i++)
            {
                for(j=0;j<NOB;j++)
                {
                    if(processes[i]<=d[j])
                    {
                    alloc[j]=processes[i];cout<<"\nAlloc["<<alloc[j]<<"]";
                    cout<<"\nProcess "<<i<<":"<<processes[i]<<" Block: "<<j<<": "<<d[j];
                    flag[i]=0,d[j]=0;break;
                    }else flag[i]=1;
                }
            }
            for(i=0;i<NOP;i++)
            {
                if(flag[i]!=0)
                cout<<"\nProcess "<<i<<" of size "<<processes[i]<<" is not allocated\n";
            }
            break;
            case 4: exit(0);
            default: cout<<"Invalid Choice…!";break;
        }
        }while(ch<=3);
    }else cout<<"\nNumber of Process must be less then or equal to number of blocks....";

    return 0;
}
