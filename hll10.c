#include <stdio.h>
#include <stdlib.h>

int Task1(int **Matrix, int SizeX, int SizeY, int k);
void Task2(int **Matrix, int SizeX, int SizeY, int k);
void Task3(int **Matrix, int SizeX, int SizeY);
void Task4(int **Matrix, int SizeX, int SizeY);


int main()
{
    int SizeX, SizeY, X, Y, Choice, k=0;
    
    printf("Enter size X= ");
    scanf("%d", &SizeX);
    printf("\nEnter size Y= ");
    scanf("%d", &SizeY);

    int **Matrix = (int**) malloc(SizeX*sizeof(int*));
    for(X=0; X<SizeX; X++)
    {
        Matrix[X]=(int*) malloc(SizeY*sizeof(int));
    }
    for(Y=0; Y<SizeY; Y++)
    {
        for(X=0; X<SizeX; X++)
        {
            printf("Position [%d][%d] = ", Y, X);
            scanf("%d", &(*(*(Matrix+Y)+X)));
        }
    }

    printf("Matrix\n");
    for(Y=0; Y<SizeY; Y++)
    {
        for(X=0; X<SizeX; X++)
        {
            printf("%d\t", *(*(Matrix + Y) + X));
        }
        printf("\n");
    }

    printf("What i must do?\n");
    do{
        printf("Select 1 or 2 or 3 or 4. Choice= ");
        scanf("%d", &Choice);
    }while((Choice<1)||(Choice>4));

    switch(Choice)
    {
    case 1:
        Task1(Matrix, SizeX, SizeY, k);
        break;
    case 2:
        Task2(Matrix, SizeX, SizeY, k);
        printf("Biggest combo in %d string.", k+1);
        break;
    case 3:
        Task3(Matrix, SizeX, SizeY);
        break;
    case 4:
        Task4(Matrix, SizeX, SizeY);
        for (X=0; X<SizeX; X++)
    {
        for (Y=0; Y<SizeY; Y++)
        {
            printf("%d ", Matrix[X][Y]);
        }
    printf("\n");
    }
        break;
    default:
        printf("bagosiki");
    }

    for(Y=0;Y<SizeY;Y++)
    {
        free(*(Matrix+Y));
    }
    free(Matrix);

    return 0;
}

int Task1(int **Matrix, int SizeX, int SizeY, int k)
{
    int X, Y;
    k = SizeY;
  
  for (Y=0; Y<SizeY; Y++)
  {
    for (X=0; X<SizeX; X++)
    {
    if (Matrix[X][Y]==0) 
      k=k-1;  
    }
    
  }
  printf("Number of columns without zero element = %d", k); 
}

void Task2(int **Matrix, int SizeX, int SizeY, int k)
{
    int X, Y, t;
    
    int *sum = (int *)calloc(SizeX, sizeof(int));
  
  for (X=0; X<SizeX; X++)
  {
    for (Y=0; Y<SizeY; Y++)
    {
      if ( (Matrix[X][Y])%2==0)  
      {
        sum[X]+=Matrix[X][Y];
      }
    }
  }

  for (X=0; X<SizeX; X++)
  {
    printf("sum[%d]=%d\n", X, sum[X]);
  }
  for (X=0; X<SizeX-1; X++)
  { 
    if (sum[X]>sum[X+1])
    { 
      t=sum[X];
      sum[X]=sum[X+1];
      sum[X+1]=t;
        for(Y=0; Y<SizeY; Y++)
        {
         k=Matrix[X][Y];
         Matrix[X][Y]=Matrix[X+1][Y];
         Matrix[X+1][Y]=k;
        }
    }     

  }
  free(sum);
}

void Task3(int **Matrix, int SizeX, int SizeY)
{
    int X, Y;
    int sumvert1=0,sumvert2=0,sumhor1=0,sumhor2=0,mist=0;
    
    for (X=0; X<SizeX-1; X++)
    {
      for (Y=0; Y<SizeY; Y++)
      {
        sumhor1+=Matrix[X][Y];
        sumhor2+=Matrix[X+1][Y];
      }
      if (sumhor1!=sumhor2) 
        mist++; 
      sumhor1=0;
      sumhor2=0;  
    }   
        
    for (Y=0; Y<SizeY-1; Y++)
    {
      for (X=0; X<SizeX; X++)
      {
        sumvert1+=Matrix[X][Y];
        sumvert2+=Matrix[X][Y+1];
      }
      if (sumvert1!=sumvert2) 
        mist++;   
      sumvert1=0;
      sumvert2=0;
    }       
    
    
    if (mist!=0){
      printf("Not a magic square\n");
    }
    else{printf("It is a magic square\n"); 
  }  
}

void Task4(int **Matrix, int SizeX, int SizeY)
{
int X, Y, l, a, b, max;       
max=Matrix[0][0];
for (X=0; X<SizeX; X++)   
    {   
  for (Y=0; Y<SizeY; Y++)
              {
                 if (Matrix[X][Y] >max)
                    {
                             max=Matrix[X][Y];
                             a=Y;
                             b=X;
                            }
                }
    }

for (X=0; X<SizeX; X++)   
    {    l=Matrix[X][b];
        Matrix[X][b]=Matrix[X][0];
        Matrix[X][0]=l;
    }


for (Y=0; Y<SizeY; Y++)   
    {    l=Matrix[0][Y];
        Matrix[0][Y]=Matrix[a][Y];
        Matrix[a][Y]=l;
    }
}
