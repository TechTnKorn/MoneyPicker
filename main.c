#include <stdio.h>
#include <stdlib.h>
int bank_type[9]={1000,500,100,50,20,10,5,2,1},bank_data[9][2];
int type_idx,have,stage,data,total,need,de,check,sol;
char YorN;
void error()
    {
        system("cls");
        printf("\a\t\t >>>ERROR!!<<<\n\n");
        printf("\t\tPLEASE TRY AGAIN\n");
        printf ("_____________________________________________________________________________\n\n");
    }
void retype(int k)
    {
        printf("%20d Baht = %d\n",bank_type[k],bank_data[k][0]);
    }
void announce(int k)
    {
        printf("%20d Baht = %d ea\n",bank_type[k],bank_data[k][0]);
        if(k==8)
            {
                printf("\t\t Total cash is %d\n",total);
            }
    }
void no_more()
    {
        printf("\a\t       DON'T HAVE ANY CASH IN SYSTEM!\n");
        printf("\n\t\tTHE SYSTEM IS RESTARTING...\n");
    }

int main()
{
    do//all system
        {
            do//input non zero check
                {
                    printf ("_____________________________________________________________________________\n");
                    printf("\n========== How much cash do you have? ==========\n");
                    //get
                    have=0;
                    for(type_idx=0;type_idx<9;)
                        {
                            printf("%20d Baht = ",bank_type[type_idx]);
                            scanf("%d",&bank_data[type_idx][0]);
                            data=bank_data[type_idx][0];
                            if(data<0)
                                {
                                    error();
                                    printf("========== How much cash do you have? ==========\n");
                                    for(type_idx=0;type_idx<have;++type_idx)
                                        {
                                            retype(type_idx);
                                        }
                                }
                            else
                                {
                                    have++;
                                    type_idx++;
                                    system("cls");
                                    printf ("_____________________________________________________________________________\n");
                                    printf("\n========== How much cash do you have? ==========\n");
                                    for(type_idx=0;type_idx<have;++type_idx)
                                        {
                                            retype(type_idx);
                                        }
                                }
                        }
                    //total
                    total=0;
                    for(type_idx=0;type_idx<9;++type_idx)
                        {
                            total=total+bank_type[type_idx]*bank_data[type_idx][0];
                        }
                    if(total==0)
                        {
                            system("cls");
                            no_more();
                            stage=0;
                        }
                    else
                        {
                            stage=1;
                        }
                }while(stage==0);
            do//con
                {
                        system("cls");
                        do//re get
                            {
                                do//re need
                                    {
                                        //how many use
                                        printf("========== The number of cash that you have ==========\n");
                                        for(type_idx=0;type_idx<9;++type_idx)
                                            {
                                                announce(type_idx);
                                            }
                                        printf ("_____________________________________________________________________________\n");
                                        printf ("\nEnter your money that you want =====> ");
                                        scanf ("%d",&need);
                                        if(need<=0||need>total)
                                            {
                                                error();
                                            }
                                    }while(need<=0||need>total);
                                //cal
                                de=need;
                                for(type_idx=0;type_idx<9;++type_idx)
                                    {
                                        bank_data[type_idx][1]=de/bank_type[type_idx];
                                        de=de%bank_type[type_idx];
                                        while(bank_data[type_idx][1]>bank_data[type_idx][0])
                                            {
                                                bank_data[type_idx][1]--;
                                                de+=bank_type[type_idx];
                                            }
                                    }
                                if(de!=0)
                                    {
                                        error();
                                        printf("========== The number of cash that you have ==========\n");
                                        for(type_idx=0;type_idx<9;++type_idx)
                                            {
                                                announce(type_idx);
                                            }
                                        do
                                            {
                                                printf ("_____________________________________________________________________________\n");
                                                printf("================== You need %d Baht ==================",need);
                                                printf("\nDO YOU STILL WANT TO GET IT?\n");
                                                printf("Select!!\n");
                                                printf("1)Continue.\n");
                                                printf("2)Cancel.\n");
                                                printf(">> ");
                                                scanf("%d",&check);
                                                if(check<1||check>2)
                                                    {
                                                        error();
                                                        printf("========== The number of cash that you have ==========\n");
                                                        for(type_idx=0;type_idx<9;++type_idx)
                                                                {
                                                                    announce(type_idx);
                                                                }
                                                    }
                                            }while(check<1||check>2);
                                        if(check==1)
                                            {
                                                //calculator_continue#2
                                                do
                                                    {
                                                        sol=++need;
                                                        if(sol<=total)
                                                            {
                                                                for(type_idx=0;type_idx<9;++type_idx)
                                                                    {
                                                                        bank_data[type_idx][1]=sol/bank_type[type_idx];
                                                                        sol=sol%bank_type[type_idx];
                                                                        while(bank_data[type_idx][1]>bank_data[type_idx][0])
                                                                            {
                                                                                bank_data[type_idx][1]--;
                                                                                sol+=bank_type[type_idx];
                                                                            }
                                                                    }
                                                            }
                                                    }while(sol>0&&sol<=total);
                                            }
                                        else
                                            {
                                                system("cls");
                                                printf("========== The number of cash that you have ==========\n");
                                                for(type_idx=0;type_idx<9;++type_idx)
                                                    {
                                                        announce(type_idx);
                                                    }
                                            }
                                    }
                            }while(check==2);

                printf ("_____________________________________________________________________________\n");
                for(type_idx=0;type_idx<9;++type_idx)
                    {
                        bank_data[type_idx][0]-=bank_data[type_idx][1];
                    }
                total=0;
                for(type_idx=0;type_idx<9;++type_idx)
                    {
                        total=total+bank_type[type_idx]*bank_data[type_idx][0];
                    }
                system("cls");
                printf("================ You need %d Baht ================\n",need);
                printf ("_____________________________________________________________________________\n");
                printf("\n============ The number of cash you need ============\n");
                for(type_idx=0;type_idx<9;++type_idx)
                    {
                        if (bank_data[type_idx][1]!=0)
                            {
                                printf("%20d Baht =  %d ea\n",bank_type[type_idx],bank_data[type_idx][1]);
                            }
                    }
                printf ("_____________________________________________________________________________\n");
                printf("\n========== The number of cash you remaining ==========\n");
                for(type_idx=0;type_idx<9;++type_idx)
                    {
                        announce(type_idx);
                    }
                if(total==0)
                {
                    do
                        {
                            printf ("_____________________________________________________________________________\n\n");
                            no_more();
                            printf ("\n_____________________________________________________________________________\n\n");
                            printf("Do you want to restart the syetem?\n");
                            printf("Y)= Yes!\n");
                            printf("N)= No!\n");
                            printf(">>");
                            fflush(stdin);
                            scanf("%c",&YorN);
                            if(YorN!='y'||YorN!='Y'||YorN!='n'||YorN!='N')
                                {
                                    error();
                                    printf("\n========== The number of cash you remaining ==========\n");
                                    for(type_idx=0;type_idx<9;++type_idx)
                                        {
                                            announce(type_idx);
                                        }
                                }
                        }while(YorN!='y'&&YorN!='Y'&&YorN!='n'&&YorN!='N');
                            if(YorN=='y'||YorN=='Y')
                                {
                                    system("cls");
                                    stage=0;
                                }
                            else if(YorN=='n'||YorN=='N')
                                {
                                    system("cls");
                                    stage=2;
                                }
                }
                else if (total>0)
                    {
                        stage=3;
                        //for into loop
                        do
                            {
                                //RE
                                printf ("\n_____________________________________________________________________________\n\n");
                                printf("Select!!\n");
                                printf("0)Reset.\n");
                                printf("1)Continue.\n");
                                printf("2)End.\n");
                                printf(">> ");
                                scanf("%d",&stage);
                                if(stage<0||stage>2)
                                    {
                                        error();
                                        printf("\n========== The number of cash you remaining ==========\n");
                                    for(type_idx=0;type_idx<9;++type_idx)
                                        {
                                            announce(type_idx);
                                        }
                                    }
                            }while(stage<0||stage>2);
                    }
                }while(stage==1);
        }while(stage==0);
    printf("The system was ended!\n");
    printf("THANK YOU!\n\n");

//copy from internet :>
int i,j;
    /* printing top semi circular shapes of heart */
    for(i = 10/2; i <= 10; i+=2){
     /* Printing Spaces */
        for(j = 1; j < 10-i; j+=2) {
            printf(" ");
        }
        /* printing stars for left semi circle */
        for(j = 1; j <= i; j++){
            printf("*");
        }
        /* Printing Spaces */
        for(j = 1; j <=10-i; j++){
            printf(" ");
        }
        /* printing stars for right semi circle */
        for(j = 1; j <= i; j++){
            printf("*");
        }
        /* move to next row */
        printf("\n");
    }

    /* printing inverted start pyramid */
    for(i = 10; i >= 1; i--){
        for(j = i; j < 10; j++){
            printf(" ");
        }
        for(j = 1; j <= (i*2)-1; j++){
            printf("*");
        }
        /* move to next row */
        printf("\n");
    }
    return 0;
}
