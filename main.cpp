#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <ctime>

using namespace std;

void selectionSort(int anArray[], int theLength)
{
    int currentIndex,startIndex;

    for (startIndex = 0; startIndex < theLength-1; startIndex++)
    {

   /* find the min element in the unsorted a[j .. n-1] */

   //  cout<<"index="<<j<<" value ="<<anArray[j]<<endl;
   /* assume the min is the first element */
   int iMin = startIndex;

   /* test against elements after j to find the smallest */
        for ( currentIndex = startIndex+1; currentIndex < theLength; currentIndex++)
        {
       /* if this element is less, then it is the new minimum */
        if (anArray[currentIndex] < anArray[iMin])
            {
           /* found new minimum; remember its index */
           iMin = currentIndex;
            }
        }

   if(iMin != startIndex) {
       swap(anArray[startIndex], anArray[iMin]);


   }

}

 //cout<<"index= "<<j<<" value ="<<anArray[11]<<endl;
}

void bubbleSort(int anArray[], int theLength)
{
/*procedure BubbleSort( A : list of sortable items )
   n = length(A)
   repeat
      newn = 0
      for i = 1 to n-1 inclusive do
         if A[i-1] > A[i] then
            swap(A[i-1], A[i])
            newn = i
         end if
      end for
      n = newn
   until n = 0
end procedure*/

anArray[theLength];

int newLength =0;
    for(int i =1; i<theLength; i++)
    {



        for(int i =1; i<theLength; i++)
        {

                if(anArray[i-1]> anArray[i])
            {
                swap(anArray[i-1], anArray[i]);
                newLength =i;

            }


        }
    }

}






void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//l is the beginning of the array
//r is the array length

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


void gnomeSort(int anArray[], int length)
{
    int start =0;
    while(start<length)
    {
        if(start==0||anArray[start-1]<=anArray[start])
        {
            start++;
        }
        else
        {
            int temp = anArray[start];
            anArray[start]=anArray[start-1];
            anArray[--start]=temp;
        }

    }

}
void quickSort(int anArray[], int left, int right)
{
  int i = left;
  int j =right;
  int temp;
  int pivot = anArray[(left +right)/2];

  while(i<=j)
  {
      while(anArray[i]<pivot)
      {
          i++;
      }
      while(anArray[j]> pivot)
      {
          j--;
      }
      if(i<=j)
      {
//          temp=anArray[i];
//          anArray[i] = anArray[j];
//          anArray[j] =temp;
          swap(anArray[i], anArray[j]);
          i++;
          j--;
      }
  }
  if(left<j)
  {
      quickSort(anArray,left,j);
  }
  if(i<right)
  {
      quickSort(anArray, i, right);
  }


}


int main()
{

int length =10000;
int theArray[length];
int midway= length/2;
int start=0;

ifstream inputFile;
inputFile.open ("test3.txt");

for(int i=0; i<length; i++)




inputFile>>theArray[i];


clock_t begin = clock();
//selectionSort(theArray, length);
//bubbleSort(theArray, length);
//mergeSort(theArray, start,length);
quickSort(theArray, start, length);
//gnomeSort(theArray, length);
clock_t end = clock();
inputFile.close();



//output the data
for (int i=0; i<length; i++)

    cout<<theArray[i]<<endl;

 double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    printf ("Elapsed time is %.9f seconds.", elapsed_secs );




    return 0;
}
