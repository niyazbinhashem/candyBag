#include<stdio.h>
void buildHeap(int*);
void Heapify(int*,int);
void heapSort(int*);

int heapSize;
int length;

void main()                 //
{

    int bag[length];
    scanf("%d",&length);

    int minute;
    scanf("%d",&minute);

    int candy;
    for(candy = 0; candy < length; candy++)
    {
        scanf("%d",&bag[candy]);
    }


    int j,sum = 0;
    for(j = 0;j < minute; j++)
    {
        heapSort(bag);
        sum = sum + bag[length-1];
        bag[length-1] = bag[length-1]/2;
    }
    printf("%d",sum);

}


void buildHeap(int* bag)        //
{
    heapSize = length - 1;
    int i;
    for(i = (length - 1) / 2; i >= 0; i--)
    {
        Heapify(bag, i);
    }

}

void Heapify(int* bag,int i)    //
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if(l <= heapSize && bag[l] > bag[i])
        largest = l;

    else
        largest = i;

    if(r <= heapSize && bag[r] > bag[largest])
        largest = r;

    if(largest != i)
    {
      int temp = bag[i];
      bag[i] = bag[largest];
      bag[largest] = temp;
      Heapify(bag, largest);
    }
}

void heapSort(int* bag)         //
{
  buildHeap(bag);
  int i;
  for(i = length - 1; i > 0; i--)
    {
      int temp = bag[heapSize];
      bag[heapSize] = bag[0];
      bag[0] = temp;
      heapSize--;
      Heapify(bag, 0);
    }
}

