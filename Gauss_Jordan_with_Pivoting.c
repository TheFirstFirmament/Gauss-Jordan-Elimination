#include<stdio.h>
#include<stdlib.h>
#define VARNUM 26
float arr[50][51];
int varcount,iloop,jloop;
char varname[VARNUM];
void this_methods_not_for_user()
{
	for(iloop=0;iloop<VARNUM;iloop++)
	varname[iloop]=(char)(97+iloop);
}
void yo_my_man_give_the_values()
{
	printf("Enter number of variables: ");
	scanf("%d",&varcount);
	for(iloop=0;iloop<varcount;iloop++)
	{
		printf("\nEnter variable coefficients for equation %d\n",(iloop+1));
		for(jloop=0;jloop<=varcount;jloop++)
		{
			if(jloop==varcount)
			printf("\nEnter result value of equation %d: ",(iloop+1));
			scanf("%f",&arr[iloop][jloop]);
		}
	}
}
void heres_a_preview_of_the_equations()
{
	printf("\nHere's the equations you entered:\n");
	for(iloop=0;iloop<varcount;iloop++)
	{
		for(jloop=0;jloop<=varcount;jloop++)
		{
			if(jloop==varcount-1)
			printf("%0.2f%c=",arr[iloop][jloop],varname[jloop]);
			else if(jloop==varcount)
			printf("%0.2f",arr[iloop][jloop]);
			else
			printf("%0.2f%c+",arr[iloop][jloop],varname[jloop]);
		}
		printf("\n");
	}
}
void damn(int r)
{
	int flag=0;
	float temp;
	char chtemp;
	for(iloop=r;iloop<varcount;iloop++)
	{
		if(arr[iloop][r]!=0)
		{
			for(jloop=0;jloop<=varcount;jloop++)
			{
				temp=arr[iloop][jloop];
				arr[iloop][jloop]=arr[r][jloop];
				arr[r][jloop]=temp;
				chtemp=varname[iloop];
				varname[iloop]=varname[r];
				varname[r]=chtemp;
			}
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\nI am really sorry man. I tried you know, but it seems your system of equations just won't get solved!");
		exit(0);
	}
}
void do_the_pivot_dude(int r)
{
	float max=arr[0][r],temp;
	char chtemp;
	int pos=0;
	for(iloop=0;iloop<varcount;iloop++)
	{
		if(max>arr[iloop][r])
		{
			max=arr[iloop][r];
			pos=iloop;
		}
	}
	if(pos!=r)
	{
		temp=arr[pos][r];
		arr[pos][r]=arr[r][r];
		arr[r][r]=temp;
		chtemp=varname[pos];
		varname[pos]=varname[r];
		varname[r]=chtemp;
	}
}
void and_this_is_where_everything_happens()
{
	int r,row,col;
	float k,m;
	for(r=0;r<varcount;r++)
	{
		k=arr[r][r];
		if(k==0.0)
		{
			damn(r);
		}
		do_the_pivot_dude(r);
		for(col=0;col<=varcount;col++)
		arr[r][col]=arr[r][col]/k;
		for(row=0;row<varcount;row++)
		{
			if(row!=r)
			{
				m=arr[row][r];
				for(col=1;col<=varcount;col++)
				arr[row][col]=arr[row][col]-m*arr[r][col];
			}
		}
	}
}
void you_still_need_the_answer_right()
{
	printf("\nAnd the answer to your system of equations are... *drum rolls*");
	for(iloop=0;iloop<varcount;iloop++)
	printf("\n%c = %0.2f\n",varname[iloop],arr[iloop][varcount]);
}
int main()
{
	this_methods_not_for_user();
	yo_my_man_give_the_values();
	heres_a_preview_of_the_equations();
	and_this_is_where_everything_happens();
	you_still_need_the_answer_right();
}
