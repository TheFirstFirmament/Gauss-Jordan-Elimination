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
			printf("%0.2f=",arr[iloop][jloop]);
			else if(jloop=varcount)
			printf("%0.2f",arr[iloop][jloop]);
			else
			printf("%0.2f+",arr[iloop][jloop]);
		}
		printf("\n");
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
			printf("\nHey dude! This is to let you know that your system of equations doesn't have any solution!");
			exit(0);
		}
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
