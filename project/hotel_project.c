#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 50
#define SIZE 30
typedef struct
{
    char s[MAX][SIZE];
    int f,r;
}queue;
void insert(queue *t ,char ele[])
{
    if(t->r == MAX -1)
    {
        printf("\nQueue full");
        return;
    }
    t->r++;
    strcpy(t->s[t->r],ele);
}
void xdelete(queue *t)
{
    char z[30];
    strcpy(z,t->s[t->f]);
    t->f++;
}
void display(queue *t)
{
    int i;
    for(i=t->f;i<=t->r;i++)
        printf("%s   ",t->s[i]);
    printf("\n");
}
int main()
{
    FILE *fp;
    fp=fopen("BILL.TXT","w");
    if(fp == NULL)
    {
        printf("\nwrong");
        exit(0);
    }
    queue x;
    x.f=0;
    x.r = -1;
    int ch,pr;
    float tot=0,gst,price;
    time_t t;
    char b[100],s;
    fputs("\n\t\t\tWelcome to PethPooja Hotel!!!!!!\n",fp);
    while(1)
    {
    printf("\n\t\t\tWelcome to PethPooja Hotel!!!!!!");
    printf("\nwe serve the following delicacies.......");
    printf("\n\t***Breakfast***");
    printf("\n\t1.Poha -- Rs.30");
    printf("\n\t2.Upma -- Rs.45");
    printf("\n\t3.Idli -- Rs.50");
    printf("\n\t4.Dosa -- Rs.70");
        printf("\n\t***Lunch***");
    printf("\n\t5.Rice Plate -- Rs.90");
    printf("\n\t6.Noodles -- Rs.120");
    printf("\n\t***Dinner***");
    printf("\n\t7.Paneer tikka -- Rs.150");
    printf("\n\t8.Chicken Tandoori -- Rs.220");
    printf("\n\t9.Rogan Josh -- Rs.390");
    printf("\n 0. to exit\nEnter choice:--");
    scanf("%d",&ch);
    if(ch == 0)
        break;
    switch(ch)
    {
        case 1:fputs("Poha..--Rs.30\n",fp);
                   tot=tot+30;
                   insert(&x,"Poha");
                   break;
        case 2:fputs("Upma..--Rs.45\n",fp);
                    tot= tot + 45;
                    insert(&x,"Upma");
                    break;
        case 3:fputs("Idli..--Rs.50\n",fp);
                    tot = tot + 50;
                    insert(&x,"Idli");
                    break;
        case 4:fputs("Dosa..--Rs.70\n",fp);
                   tot = tot + 70;
                   insert(&x,"Dosa");
                   break;
        case 5:fputs("Rice Plate..--Rs.90\n",fp);
                    tot = tot + 90;
                    insert(&x,"Rice Plate");
                    break;
        case 6:fputs("Noodles..--Rs.120\n",fp);
                    tot = tot + 120;
                    insert(&x,"Noodles");
                    break;
        case 7:fputs("Paneer Tikka..--Rs.150\n",fp);
                    tot = tot + 150;
                    insert(&x,"Paneer Tikka");
                    break;
        case 8:fputs("Chicken Tandoori ..--Rs.220\n",fp);
                    tot = tot + 220;
                    insert(&x,"Chicken Tandoori");
                    break;
        case 9:fputs("Rogan Josh...--Rs.390\n",fp);
                    tot = tot +390;
                    insert(&x,"Rogan Josh");
                    break;
    }
    }
    display(&x);
    gst=9*tot/100;
    price=tot+gst;
    fprintf(fp,"Total = %f\nGST(9per.) = %f\nGrand Total=%f\n",tot,gst,price);
    fputs(__TIME__,fp);
    fputs(" ",fp);
    fputs(__DATE__,fp);
    fclose(fp);
    fp=fopen("BILL.TXT","r");
    if(fp==NULL)
	{
		printf("\nCAN NOT OPEN FILE");
		exit(0);
	}
    do
    {
		s=getc(fp);
		printf("%c",s);
	}
	while(s!=EOF);
	fclose(fp);
    return 0;
}
