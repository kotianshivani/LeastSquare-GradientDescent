#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void main()
{
 float n=40,I;
 float sumx, sumsq, sumy, sumxy, l[50], m[50],slope=0,meanx=0,meany=0,intercept=0,value=0,slopemal=0,interceptmal=0,error=0,sqerror=0;
 FILE *fp=fopen("datay.txt","r");
char line[100];
if(fp==NULL)
{	printf("hhh");
}
 sumx = 0;
 sumsq = 0;
 sumy = 0;
 sumxy = 0;
int i=0;
int h=n;
    while(fscanf(fp,"%f",&m[i])==1) {       
          
        
        i++;
    }
for(i=0;i<n;i++)
{
	l[i]=i;
}


//least square  method
for(i=0;i<n;i++)
{
	sumx +=l[i];
	sumy +=m[i];
}
	meanx=sumx/n;
	meany=sumy/n;
for(i=0;i<n;i++)
{
 	sumxy=sumxy+((l[i]-meanx)*(m[i]-meany));
 	sumsq=sumsq+pow((l[i]-meanx),2);
}
	slope=sumxy/sumsq;
/*for(i=0;i<n;i++){
	
	//intercept= intercept+ m[i]-slope*l[i];

}
	intercept=intercept/n;*/
	intercept=meany-slope*meanx;
	printf("y=%f*x+%f\n",slope,intercept);
for(i=0;i<n;i++){
	value=slope*i+intercept;
	
	error=m[i]-value;
	sqerror += pow(error,2);
}
sqerror=sqerror/n;
sqerror=sqrt(sqerror);
printf(" error %f",sqerror);

printf(" least sq value for next day %f\n",(slope*41+intercept));

//gradient descent
float learning_rate=0.01;
int j=0;
//slope=3,intercept=0;
for(j=0;j<10;j++)
{
	for(i=1;i<=n;i++)
	{
		slopemal+=l[i-1]*(m[i-1]-(slope*l[i-1]+intercept));
		interceptmal+=(m[i-1]-(slope*l[i-1]+intercept));
		//printf("%f\n",m[i]-(slope*l[i]+intercept));

	
	//printf("%f",slope);
	
	slopemal=(-2/n)*(slopemal);
	interceptmal=(-2/n)*(interceptmal);
	slope -= slopemal*learning_rate;
	intercept -= interceptmal*learning_rate;
}
	//learning_rate=learning_rate*10;
}

 
printf("after descent\ny=%f*x+%f\n",slope,intercept);
printf(" gradient value for next day %f\n",(slope*41+intercept));
sqerror=0;
for(i=0;i<n;i++)
{
	value=slope*i+intercept;
	//printf("%d\t%f\n",i,value);
	error=m[i]-value;
	sqerror += pow(error,2);
}
sqerror=sqerror/n;
sqerror=sqrt(sqerror);
printf("gd %f\n",sqerror);
fclose(fp);
}



