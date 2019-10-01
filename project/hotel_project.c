#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    FILE *fp;
    fp=fopen("BILL.TXT","w");
    if(fp == NULL)
    {
        printf("\nwrong");
        exit(0);
    }
    int ch,pr;
    float tot=0,gst,price;
    time_t t;
    char b[100],s;
    fputs("\n\t\t\tWelcome to XXX Hotel!!!!!!\n",fp);
    while(1)
    {
    printf("\n\t\t\tWelcome to XXX Hotel!!!!!!");
    printf("\nwe serve the following delicacies.......");
    printf("\n\t***Breakfast***");
    printf("\n\t1.Poha -- Rs.30");
    printf("\n\t2.Upma -- Rs.45");
    printf("\n\t3.Idli -- Rs.50");
    printf("\n\t4.Dosa -- Rs.70");
        printf("\n\t***Lunch***");
    printf("\n\t5.Rice Plate -- Rs.90");
    printf("\n\t6.Noodles -- Rs.120");
    printf("\n\t7.Paneer tikka -- Rs.150");
    printf("\n\t8.Chicken Tandoori -- Rs.220");
    printf("\nEnter choice:--");
    scanf("%d",&ch);
    if(ch == 0)
        break;
    switch(ch)
    {
        case 1:fputs("Poha..--Rs.30\n",fp);
                   tot=tot+30;
                   break;
        case 2:fputs("Upma..--Rs.45\n",fp);
                    tot= tot + 45;
                    break;
        case 3:fputs("Idli..--Rs.50\n",fp);
                    tot = tot + 50;
                    break;
        case 4:fputs("Dosa..--Rs.70\n",fp);
                   tot = tot + 70;
                   break;
        case 5:fputs("Rice Plate..--Rs.90\n",fp);
                    tot = tot + 90;
                    break;
        case 6:fputs("Noodles..--Rs.120\n",fp);
                    tot = tot + 120;
                    break;
        case 7:fputs("Paneer Tikka..--Rs.150\n",fp);
                    tot = tot + 150;
                    break;
        case 8:fputs("Chicken Tandoori ..--Rs.220\n",fp);
                    tot = tot + 220;
                    break;
    }
    }
    gst=9*tot/100;
    price=tot+gst;
    fprintf(fp,"Total = %f\nGST(9per.) = %f\nGrand Total=%f\n",tot,gst,price);
    fputs(__TIME__,fp);
    fputs(" ",fp);
    fputs(__DATE__,fp);
    fclose(fp);
    fp=fopen("BILL.TXT","r");
    do
    {
		s=getc(fp);
		printf("%c",s);
	}
	while(s!=EOF);
	fclose(fp);
    return 0;
}
