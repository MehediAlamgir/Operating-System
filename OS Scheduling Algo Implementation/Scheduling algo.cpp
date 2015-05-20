
#include<iostream>
#include<cstdio>
#include<cmath>
#define size 50
using namespace std;

class Algo
{
	int n,Bu[size],c;
	float twt,awt,A[size],wt[size],w;
public:

	void get_Burst_Time();

	void fcfs();

	void sjfnp();

	void sjfp();

	void Priority();

	void RoundRobin();


};


void Algo::get_Burst_Time()
{
	int i;
	cout<<"Enter the num of processes: ";
	cin>>n;
    cout<<"\n";
	cout<<"Enter The Burst Time: "<< endl;
	for(i=1;i<=n;i++)
	{
       cout << " p"<<i<<" =	";
		cin>>Bu[i];
	}
    cout<<"\n\n";
	cout<<"Burst Time has been taken.Now Select Algorithm Which You Want To Execute......" <<"\n";
}

// FIRST COME FIRST SERVED SCHEDULING ALGORITHM

void Algo::fcfs()
{
	int i,B[size];
	twt=0.0;
	 cout<<"\n\n";
    cout<<"Process"<<" "<<" Burst Time"<<endl;

	for(i=1;i<=n;i++)
	{
	    B[i]=Bu[i];
		cout<<"  p"<<i<<"      "<<B[i]<<endl;
	}

	wt[1]=0;
	for(i=2;i<=n;i++)
	{
		wt[i]=B[i-1]+wt[i-1];
	}

	//Calculating Average waiting Time
	for(i=1;i<=n;i++)
    {
		twt=twt+wt[i];
	}
    awt=twt/n;
    cout<<"\n";
	cout<<"Total   waiting Time = "<<twt<<endl;

	 cout<<"Average waiting Time : (";

    for(i=1;i<=n;i++)
    {
        cout<<wt[i];
        c=1;

        if(i==n)
        {
            c=0;
            cout<<")";
        }

        if(c==1)
            cout<<"+";
    }

   cout<<"/"<<n<<" = "<<awt<<"\n\n";
}

// SHORTEST JOB FIRST (NON PREEMPTIVE) SCHEDULING ALGORITHM

void Algo::sjfnp()
{
	int i,B[size],tt=0,temp,j;
	char S[size];
	float A[size],temp1,t;
	twt=0.0;
	w=0.0;
	cout<<"Enter Arrival Time: "<<"\n";
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
        S[i]='T';
		tt=tt+B[i];
		cout<<" p"<<i<<"=	";
		cin>>A[i];
	}

    cout<<"\n\n";
    cout<<"Process"<<" "<<" Burst Time"<<" "<<" Arrival Time"<<endl;

	for(i=1;i<=n;i++)
	{
		cout<<"  p"<<i<<"      "<<B[i]<<"	      "<<A[i]<<endl;
	}

	cout<<"\n\n";


		wt[1]=0;
		w=w+B[1];
		t=w;
		S[1]='F';

		while(w<tt)
		{
			i=2;
			while(i<=n)
			{
				if(S[i]=='T'&& A[i]<=t)
				{
					wt[i]=w;

					S[i]='F';
					w=w+B[i];
					t=w;
					i=2;
				}
				else
					i++;
			}
		}




		//calculating average weighting Time

		for(i=1;i<=n;i++)
        {
            twt=twt+(wt[i]-A[i]);
        }

		awt=twt/n;

	 cout<<"\n";
	 cout<<"Total   waiting Time = "<<twt<<endl;

	 cout<<"Average waiting Time : (";

    for(i=1;i<=n;i++)
    {
        cout<<abs((wt[i])-(A[i]));
        c=1;

        if(i==n)
        {
            c=0;
            cout<<")";
        }

        if(c==1)
            cout<<"+";
    }

   cout<<"/"<<n<<" = "<<awt<<"\n\n";

}



//SHORTEST JOB FIRST (PREEMPTIVE) SCHEDULING ALGORITHM

void Algo::sjfp()
{
	int i,j,m,wt[size],k,B[size],A[size],tt=0,wtm[size],temp;
	char S[size],start[size];
	int max=0,Time=0,min;
	float twt=0.0,awt;
	cout<<"Enter Arrival Time "<<endl;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];

		if(B[i]>max)
        {
			max=B[i];
		}
		wt[i]=0;
		S[i]='T';
		start[i]='F';
		tt=tt+B[i];
		cout<<"p"<<i<<"=	";
		cin>>A[i];
		if(A[i]>Time)
			Time=A[i];
	}

	 cout<<"\n\n";
    cout<<"Process"<<" "<<" Burst Time"<<" "<<" Arrival Time"<<endl;

	for(i=1;i<=n;i++)
	{
		cout<<"  p"<<i<<"      "<<B[i]<<"	      "<<A[i]<<endl;
	}

	cout<<"\n\n";

	int w=0,flag=0,t=0;
	i=1;
	while(t<Time)
	{
		if(A[i]<=t && B[i]!=0)
		{
			if(flag==0)
			{
				wt[i]=wt[i]+w;

			}
			B[i]=B[i]-1;
			if(B[i]==0)
            {
				S[i]='F';
			}
			start[i]='T';
			t++;
			w=w+1;
			if(S[i]!='F')
			{
				j=1;flag=1;
				while(j<=n && flag!=0)
				{
					if(S[j]!='F' && B[i]>B[j] && A[j]<=t && i!=j )
					{
						flag=0;
						wt[i]=wt[i]-w;
						i=j;
					}
					else
					{
						flag=1;
					}
					j++;
				}
			}
			else
			{
				i++;
				j=1;
				while(A[j]<=t &&j<=n)
				{
					if(B[i]>B[j] && S[j]!='F')
					{
						flag=0;
						i=j;
					}
					j++;
				}
			}
		}
		else
			if(flag==0)
			i++;
	}


	while(w<tt)
	{
		min=max+1;
		i=1;
		while(i<=n)
		{
			if(min>B[i] && S[i]=='T')
			{
				min=B[i];
				j=i;
			}
			i++;
		}
		i=j;
		if(w==Time && start[i]=='T')
		{
			w=w+B[i];
			S[i]='F';
		}
		else
		{
			wt[i]=wt[i]+w;
			w=w+B[i];
			S[i]='F';
		}
	}


	for(i=1;i<=n;i++)
	{
		wt[i]=wt[i]-A[i];

	}

	for(i=1;i<=n;i++)
    {
        twt=twt+wt[i];
    }

	awt=twt/n;
	cout<<"Total Waiting Time: "<<twt<<endl;

	 cout<<"Average waiting Time : (";

    for(i=1;i<=n;i++)
    {
        cout<<abs((wt[i])-(A[i]));
        c=1;

        if(i==n)
        {
            c=0;
            cout<<")";
        }

        if(c==1)
            cout<<"+";
    }

   cout<<"/"<<n<<" = "<<awt<<"\n\n";

}


// PRIORITY SCHEDULING ALGORITHM

void Algo::Priority()
{
	int i,B[size],P[size],j;
	w=0.0;
	int max;
	twt=0.0;
	max=1;
	cout<<"Enter the priority "<<endl;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];

		cout<<"P"<<i<<"=	";
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}

    cout<<"\n\n";
    cout<<"Process"<<" "<<" Burst Time"<<" "<<" Priority"<<endl;

	for(i=1;i<=n;i++)
	{
		cout<<"  p"<<i<<"      "<<B[i]<<"	      "<<P[i]<<endl;
	}

	cout<<"\n\n";

	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}

	//calculating average weighting Time
	for(i=1;i<=n;i++)
		twt=twt+wt[i];
	awt=twt/n;
	cout<<"Total   waiting Time :"<<twt<<""<<endl;
	cout<<"Average waiting Time : (";

    for(i=1;i<=n;i++)
    {
        cout<<wt[i];
        c=1;

        if(i==n)
        {
            c=0;
            cout<<")";
        }

        if(c==1)
            cout<<"+";
    }

   cout<<"/"<<n<<" = "<<awt<<"\n\n";
}


// ROUND ROBIN SCHEDULING ALGORITHM

void Algo::RoundRobin()
{

	int i,j,qt,k,B[size],r[size][size],count[size];
	int max=0;
	int m;
	twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];

		if(max<B[i])
			max=B[i];
		wt[i]=0;
	}
	cout<<"Enter Quantum Time = ";
	cin>>qt;

	m=max/qt+1;

    cout<<"\n\n";
    cout<<"Process"<<" "<<" Burst Time"<<" "<<" Quantum Time"<<endl;

	for(i=1;i<=n;i++)
	{
		cout<<"  p"<<i<<"      "<<B[i]<<"	      "<<qt<<endl;
	}

	cout<<"\n";


	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			r[i][j]=0;
		}
	}

	i=1;
	while(i<=n)
	{
		j=1;
		while(B[i]>0)
		{
			if(B[i]>=qt)
			{
				B[i]=B[i]-qt;
				r[i][j]=qt;
				j++;
			}
			else
			{
				r[i][j]=B[i];
				B[i]=0;
				j++;
			}
		}
		count[i]=j-1;
		i++;
	}


	//calculating weighting time
	int x=1;
	i=1;
	while(x<=n)
	{
		for(int a=1;a<x;a++)
		{
			wt[x]=wt[x]+r[a][i];
		}
		i=1;
		int z=x;
		j=count[z];
		k=1;
		while(k<=j-1)
		{
			if(i==n+1)
			{
				i=1;
				k++;
			}
			else
			{
				if(i!=z)
				{
					wt[z]=wt[z]+r[i][k];
				}
				i++;
			}
		}
		x++;
	}
	cout<<"waiting Time for "<<"\n";
	for(i=1;i<=n;i++)
    {
		cout<<"P"<<i<<"="<<wt[i]<<endl;
	}
    cout<<"\n\n";
	//calculating Average waiting Time
	for(i=1;i<=n;i++)
    {
		twt=twt+wt[i];
	}
	awt=twt/n;
	cout<<"Total   waiting Time="<<twt<<endl;


    cout<<"Average waiting Time : (";

    for(i=1;i<=n;i++)
    {
        cout<<abs((wt[i])-(A[i]));
        c=1;

        if(i==n)
        {
            c=0;
            cout<<")";
        }

        if(c==1)
            cout<<"+";
    }

   cout<<"/"<<n<<" = "<<awt<<"\n\n";

}



int main()
{
	int ch,cho;
	Algo c;
	do
	{
	    cout<<"\n\n\n";
        cout<<"========================================================================="<<"\n\n";

		cout<<"                                      OPTION                              "<<"\n\n";
        cout<<"========================================================================="<<"\n\n";

		cout<<"\n";

        cout<<" Select One: " <<"\n";
		cout<<"___________________________________________________________________"<<"\n\n";
		cout<<"1.Enter Burst Time"<<endl;
		cout<<"\n";

		cout<<"2.First Come First Served (FCFS) Algorithm"<<endl;
		cout<<"\n";
		cout<<"3.Shortest Job First (SJF) Algorithm"<<endl;
		cout<<"\n";
		cout<<"4.Priority Algorithm"<<endl;
		cout<<"\n";
		cout<<"5.Round Robin Algorithm"<<endl;
		cout<<"\n";
		cout<<"6.EXIT"<<endl;
        cout<<"___________________________________________________________________"<<"\n\n";

		cout<<"\n\n\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n\n";
		switch(ch)
		{
		case 1:
			c.get_Burst_Time();
			break;
		case 2:

		    cout<<"=========================================================================="<<"\n\n";

			cout<<"FIRST COME FIRST SERVED"<<"\n\n";

			cout<<"=========================================================================="<<"\n\n";

			c.fcfs();
			break;
		case 3:
            cout<<"=========================================================================="<<"\n\n";

			cout<<"SHORTEST JOB FIRST SCHEDULING"<<"\n\n";

            cout<<"=========================================================================="<<"\n\n";
            cout<<"\n";


			do
			{
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

			    cout<<" Select Your Option "<<"\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n\n";
                cout<<"_______________________________"<<"\n\n";

				cout<<"1.SJF-Preemptive"<<endl;
				cout<<"\n";
				cout<<"2.SJF-NonPreemptive"<<endl;
				cout<<"\n";
				cout<<"3.Terminate"<<endl;
                cout<<"_______________________________"<<"\n\n";

				cout<<"\n\n";
				cout<<"Enter your choice: ";

				cin>>cho;
				cout<<"\n\n";
				switch(cho)
				{

				case 1:
					c.sjfp();
					break;
				case 2:
					c.sjfnp();
					break;
                case 3:
                    break;
				}
			}while(cho<=2);
			break;

		case 4:
            cout<<"=========================================================================="<<"\n\n";

			cout<<"PRIORITY SCHEDULING"<<"\n\n";

            cout<<"=========================================================================="<<"\n\n";
            cout<<"\n";
			c.Priority();
			break;

        case 5:
            cout<<"=========================================================================="<<"\n\n";

			cout<<"ROUND ROBIN SCHEDULING"<<"\n\n";
            cout<<"=========================================================================="<<"\n\n";
            cout<<"\n";

			c.RoundRobin();
			break;

		case 6:
		    cout<<"Thanks .  Leaving System.....!!"<<"\n\n";
			break;
		}
	}while(ch<=5);
}


