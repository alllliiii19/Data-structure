#include<iostream>

using namespace std;

int main()
{
	int a[5]={10,15,20,25,30};
	int sum;
	float mean;
	
	for(int i=0;i<5;i++)
	{
		sum=sum+a[i];
	}
	mean=sum/5.0;
	int sum2;
for(int i=0;i<5;i++)
{
	int term1=a[i]-mean;
	int term2=term1*term1;
	sum2=sum2+term2;
}
float variance= sum2/5.0;
cout<<"variance = "<<variance;

}
