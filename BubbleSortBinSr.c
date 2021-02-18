/* C PROGRAM TO SORT A LIST OF ELEMENTS USING BINARY SEARCH AND
   APPLING BINARY SEARCH TO FIND THE USER GIVEN KEY VALUE  */

/* PROGRAM SOURCES
   BUBBLE SORT -- hackr.io
   BINARY SEARCH -- binarysearch in c, video, saurabh sukhla, mysirg youtube channel
   MERGED AND DOCUMENTED BY -- Manideep Malyala */



#include <stdio.h>

   // declaring functions
void bubble_sort(int a[], int n);
void binary_search(int A[],int N, int key);

int main()
{
  int a[100], n, i;

  // fixing the number of elements from user
  printf("Enter the Number of Elements for the Array: ");
  scanf("%d", &n);
  printf("\n");
  printf("Enter %d integers: \n", n);

  // initializing the array with entered values
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("\n");

  // printing the array elements given by user
  printf("Array Elements Before Sorting:     ");
  for (i = 0; i < n; i++)
    printf("%d   ", a[i]);

  // calling the bubble sort function to sort the array
  bubble_sort(a, n);

  // printing the array elements after bubble sort
  printf("\n\nArray Elements After Bubble Sort:  ");
  for (i = 0; i < n; i++)
     printf("%d   ", a[i]);

  // taking the key value to be searched from the user
  int key;
  printf("\n\nEnter the Element to be Searched:  ");
  scanf("%d", &key);

  // calling binary search function to search the key value
  binary_search(a, n, key);

  return 0;
}


// function for bubble sort
void bubble_sort(int a[], int n)
{
    int i = 0, j = 0, tmp;
    // outer for loop for the number of passes/rounds ie [n-1]
    for (i = 0; i < n - 1; i++)
    {
      // inner for loop for the number of comparisions
        for (j = 0; j < n - i - 1; j++)
        {
          // swapping if necessory, if left value is higher than right value
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// function for finding the user entered element using binary search
void binary_search(int A[], int N, int key)
{
  // fixing the range values
  int lower = 0, upper = N - 1, mid;

  while (lower <= upper)
     { // defining the middle index
       mid = (lower + upper)/2;

       if (key == A[mid])
       {
      // printing the key value with index, if found at the middile index and exiting loop with return
        printf("\nSearch Successful, Element Found At Index %d", mid);
        return ;
       }
      // shifting the lower boundary to one place right side if the key is greater than mid, upper value is same
       else if (key > A[mid])
        lower = mid + 1;
      // shifting the upper boundary to one place leftside if the key is less than mid, lower value is same
       else
        upper = mid - 1;
     }

  printf("\nSearch Unsuccessful, Element Not Found.");
}


