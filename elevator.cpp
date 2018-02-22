#include<stdio.h>
#include <string.h>
#include <conio.h>

int max(int a[],int n,int l)//取最大值函数 
{
	int t,i;
	t=l;
	for(i=0;i<n;i++)
	{
		if(a[i]>t)
		t=a[i];
	}
	return t;
}
int min(int a[],int n,int l)//取最小值函数 
{
	int t,i;
	t=l;
	for(i=0;i<n;i++)
	{
		if(a[i]<t && a[i]!=0)
		t=a[i];
	}
	return t;
}
int main()
{
	int time[5],begin[5],end[5],a[5],i,j,k=0,t=0,ok=1,ok1=0,sumtime=0;
	FILE *in;
	in=fopen("e:\\第三次作业\\BIN\\input.txt","rt");
	for(i=0;i<5;i++)//输入数据，判断方向。 
	{
		fscanf(in,"%d%d%d",&time[i],&begin[i],&end[i]);
		if(begin[i]<end[i])
		a[i]=1;
		else
		a[i]=0;
	}
	fclose(in);
    FILE *out; 
    extern clrscr();
    out=fopen("e:\\第三次作业\\BIN\\output.txt","wt");
	while(ok)
	{
		for(j=k+1;j<=10;j++)//电梯上时的情况 
		{
			if((j-1)>max(end,5,max(begin,5,j-1)))
			break;
			for(i=0;i<5;i++)
			{
				if(begin[i]==j && time[i]<=t && a[i]==1)
				{
					ok1=1;
					begin[i]=0;a[i]=2;
				}
			}
				if(ok1)
				{
					fprintf(out,"%d时，停靠在%d楼\n",t,j);
					t++;
				}
				ok1=0;
			for(i=0;i<5;i++)
			{
				if(end[i]==j && a[i]==2)
				{
					end[i]=0;
					sumtime=sumtime+t-time[i];
					ok1=1;
				}
			}
			if(ok1)
			{
					fprintf(out,"%d时，停靠在%d楼\n",t,j);
					t++;
			}
			ok1=0;
			t++;
		}
		for(k=j-1;k>=1;k--)//电梯向下时的情况 
		{
			if(k+1<min(end,5,min(begin,5,k+1)))
			break;
			for(i=0;i<5;i++)
			{
				if(begin[i]==k && time[i]<=t && a[i]==0)//进入楼梯 
				{
					ok1=1;
					begin[i]=0;a[i]=3;
				}
			}
			if(ok1)
			{
					fprintf(out,"%d时，停靠在%d楼\n",t,k);
					t++;
			}
			ok1=0;
			for(i=0;i<5;i++)
			{
				if(end[i]==k && a[i]==3)//出楼梯 
				{
					ok1=1;
					end[i]=0;
					sumtime=sumtime+t-time[i];
				}
			}
			if(ok1)
			{
				fprintf(out,"%d时，停靠在%d楼\n",t,k);
				t++;
			}
			ok1=0;
			t++;
		}
		ok=0;
		for(i=0;i<5;i++)//控制是否循环 
		{
			ok=ok+begin[i]+end[i];
		}
		
	}
	fprintf(out,"%d",sumtime);
	fclose(out);
	return 0;
}
