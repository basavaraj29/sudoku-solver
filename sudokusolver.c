#include<stdio.h>
#include<stdlib.h>
int c=0;
int flag=0;
int checksub(int b[][9],int i,int j,int t)
{
int i1,j1;

for(i1=0;i1<9;i1++) if(t==b[i1][j]) return 0;
for(i1=0;i1<9;i1++) if(t==b[i][i1]) return 0;
if(i%3==0)
{
if(j%3==0) {for(i1=0;i1<3;i1++) {for(j1=0;j1<3;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==1) {for(i1=0;i1<3;i1++) {for(j1=-1;j1<2;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==2) {for(i1=0;i1<3;i1++) {for(j1=-2;j1<1;j1++) if(t==b[i+i1][j+j1]) return 0;}}
}
else if(i%3==1)
{
if(j%3==0) {for(i1=-1;i1<2;i1++) {for(j1=0;j1<3;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==1) {for(i1=-1;i1<2;i1++) {for(j1=-1;j1<2;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==2) {for(i1=-1;i1<2;i1++) {for(j1=-2;j1<1;j1++) if(t==b[i+i1][j+j1]) return 0;}}
}
else
{
if(j%3==0) {for(i1=-2;i1<1;i1++) {for(j1=0;j1<3;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==1) {for(i1=-2;i1<1;i1++) {for(j1=-1;j1<2;j1++) if(t==b[i+i1][j+j1]) return 0;}}
else if(j%3==2) {for(i1=-2;i1<1;i1++) {for(j1=-2;j1<1;j1++) if(t==b[i+i1][j+j1]) return 0;}}
}
return 1;
}
int check(int b[][9])
{
int i,j,t,i1,j1;
for(i=0;i<9;i++) for(j=0;j<9;j++)
{
for(t=0;t<9;t++) if(b[i][j]==b[t][j]&&i!=t) return 0;
for(t=0;t<9;t++) if(b[i][j]==b[i][t]&&j!=t) return 0;
if(i%3==0)
{
if(j%3==0) {for(i1=0;i1<3;i1++) {for(j1=0;j1<3;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==1) {for(i1=0;i1<3;i1++) {for(j1=-1;j1<2;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==2) {for(i1=0;i1<3;i1++) {for(j1=-2;j1<1;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
}
else if(i%3==1)
{
if(j%3==0) {for(i1=-1;i1<2;i1++) {for(j1=0;j1<3;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==1) {for(i1=-1;i1<2;i1++) {for(j1=-1;j1<2;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==2) {for(i1=-1;i1<2;i1++) {for(j1=-2;j1<1;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
}
else if(i%3==2)
{
if(j%3==0) {for(i1=-2;i1<1;i1++) {for(j1=0;j1<3;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==1) {for(i1=-2;i1<1;i1++) {for(j1=-1;j1<2;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
else if(j%3==2) {for(i1=-2;i1<1;i1++) {for(j1=-2;j1<1;j1++) if(b[i][j]==b[i+i1][j+j1]&&i!=i+i1) return 0;}}
}
}
return 1;
}
void guess(int a[][9],int b[][9],int i,int j)
{
int t,i1,j1,t1;
for(t=1;t<10&&!(flag==-1&&a[i][j]!=0);t++)
{if(flag==1) return;
    if(a[i][j]==0) {if(checksub(b,i,j,t)==1) b[i][j]=t;else continue;}
    if(flag==-1&&t<=9) flag=0;
        if(i<=8&&j<8) guess(a,b,i,j+1);
    else if(i<8&&j==8) guess(a,b,i+1,0);
    else {if(check(b)==1) {flag=1;c=0;for(i1=0;i1<9;i1++) for(j1=0;j1<9;j1++) {t1=a[i1][j1];a[i1][j1]=b[i1][j1];b[i1][j1]=t;}return;} else{flag=-1;if(a[i][j]==0) b[i][j]=0;return;}  }
}
if(t==10&&a[i][j]==0) {b[i][j]=0;flag=-1;return;}
if(t==10&&flag==-1&&a[i][j]==0) {b[i][j]=0;return;}

}

void put(int p[][9])
{
int k,t,x,l,i1,j1,i2,j2,t1,count,i,j,a[9],b,q[9][9];
for(i1=0;i1<9;i1++) for(j1=0;j1<9;j1++) q[i1][j1]=p[i1][j1];
for(;c>0;)
{
    for(i=0;i<9;i++) for(j=0;j<9;j++)
{
    if(p[i][j]==0)
    {
        for(t=1,count=0;t<10;t++) {if(checksub(p,i,j,t)==1) {count++;i1=i;j1=j;t1=t;}}
        if(count==1) {p[i1][j1]=t1;c--;}
    }
}
for(i1=0;i1<9;i1++)
    {
        for(t=1;t<10;t++)

     {
        for(j1=0,count=0;j1<9;j1++)
{
if(p[i1][j1]==0)
{
    if(checksub(p,i1,j1,t)==1) {count++;i2=i1;j2=j1;t1=t;}
}
}
   if(count==1) {p[i2][j2]=t1;c--;}
   }
}
for(j1=0;j1<9;j1++)
    {
        for(t=1;t<10;t++)

     {
        for(i1=0,count=0;i1<9;i1++)
{
if(p[i1][j1]==0)
{
    if(checksub(p,i1,j1,t)==1) {count++;i2=i1;j2=j1;t1=t;}
}
}
   if(count==1) {p[i2][j2]=t1;c--;}
   }
}
for(t=1,count=0;t<10;t++)
    {
    for(j=0;j<9;j=j+3)
        {
            for(i=0;i<9;i=i+3)
         {
            for(i1=0,count=0;i1<3;i1++)
            {
                for(j1=0;j1<3;j1++)
                if(p[i+i1][j+j1]==0)
                {
                    if(checksub(p,i+i1,j+j1,t)==1) {count++;i2=i+i1;j2=j+j1;t1=t;}
                }
            }
    if(count==1) {p[i2][j2]=t1;c--;}
        }
       }
    }
    {for(i1=0,count=0;i1<9;i1++) {for(j1=0;j1<9;j1++) {if(q[i1][j1]!=p[i1][j1]) count++;}} if(count==0&&c!=0) {guess(p,q,0,0);}}
for(i1=0;i1<9;i1++) {for(j1=0;j1<9;j1++) {q[i1][j1]=p[i1][j1];}}
}
}
int main()
{
int a[9][9],i,j,k,n;
for(i=0;i<9;i++) for(j=0;j<9;j++) a[i][j]=0;
printf("Enter how many numbers you want to give as your input\t");
scanf("%d",&n);
printf("Enter the data along with its position coordinates in the format-> ith X jth\n");
for(k=0;k<n;k++) {scanf("%d %d",&i,&j);scanf("%d",&a[i-1][j-1]);}
printf("The given sudoku is\n");
for(i=0;i<9;i++) {for(j=0;j<9;j++) {printf("%d\t",a[i][j]);} printf("\n");};
for(i=0;i<9;i++) for(j=0;j<9;j++) if(a[i][j]==0) c++;
put(a);
printf("The answer is\n");
for(i=0;i<9;i++) {for(j=0;j<9;j++) {printf("%d\t",a[i][j]);} printf("\n");};
return 0;
}
