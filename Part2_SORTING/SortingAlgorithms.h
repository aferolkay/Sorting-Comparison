#ifndef SORTINGALGORITHMS_H_INCLUDED
#define SORTINGALGORITHMS_H_INCLUDED
using namespace std;

template <class T>
void Swap (T &x, T &y){// by reference!
    T temp; // temp variable for swap
    temp = x; //EACH TIME SWAP FUNCTION TAKES PLACE, 3 DATA MOVES HAPPEN.
    x = y;
    y = temp;
}

//BUBBLE SORT****************************************************************************************
//BUBBLE SORT****************************************************************************************
//BUBBLE SORT****************************************************************************************
//BUBBLE SORT****************************************************************************************
// BubbleSort is passed an array A and list count n. It sorts the data by
// making a series of passes as long as lastExchangeIndex > 0.
template <class T>
void BubbleSort(T A[], int n){ // pass array variable
    int i, j;
    int lastExchangeIndex; // Index of last exchange
    i = n-1; // i is the index of last element in the sublist
    while (i > 0){ // continue the process until no exchanges are made
    lastExchangeIndex = 0; // start lastExchangeIndex at 0
    for (j = 0; j < i; j++){ // scan the sublist A[0] to A[i]
        if (A[j+1] < A[j]){ // exchange a pair and update lastExchangeIndex
            Swap(A[j],A[j+1]);
            lastExchangeIndex = j;
        }
    }
    i = lastExchangeIndex; // set i to index of the last exchange
    // continue sorting the sublist A[0] to A[i]
    }
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
//SAME AS ABOVE BUT MODIFIED WITH COUNT VARIABLES
template <class T>
int* BubbleSortStat(T A[], int n){ // pass array variable
    int comparison=0,move=0;
    int *output=new int[2];

    int i, j;
    int lastExchangeIndex; // Index of last exchange
    i = n-1; // i is the index of last element in the sublist
    while (i > 0){ // continue the process until no exchanges are made
    lastExchangeIndex = 0; // start lastExchangeIndex at 0
    for (j = 0; j < i; j++){ // scan the sublist A[0] to A[i]
        comparison++;//IN IF CONDITION COMPARISON OCCURS
        if (A[j+1] < A[j]){ // exchange a pair and update lastExchangeIndex
            Swap(A[j],A[j+1]);

            move=move+3; //SWAP OCCURS
            lastExchangeIndex = j;
        }
    }
    i = lastExchangeIndex; // set i to index of the last exchange
    // continue sorting the sublist A[0] to A[i]
    }
    output[0]=comparison; //STORE DATA FOR LATER
    output[1]=move;

    return output;

}










//SELECTION SORT ****************************************************************************************
//SELECTION SORT ****************************************************************************************
//SELECTION SORT ****************************************************************************************
//SELECTION SORT ****************************************************************************************
// sort an array of n elements of
//type T using selection sort
template <class T>
void SelectionSort(T A[], int n){ //    pass array variable!

    // index of smallest item in each pass
    int smallIndex;
    int i, j;
    // compare A[0]...A[n-2] with partof the list after
    for (i = 0; i < n-1; i++){
        // start the scan at index i; set smallIndex to i
        smallIndex = i;
        // j scans the sublist A[i+1]...A[n-1]
        for (j = i+1; j < n; j++)
        // update smallIndex if smaller element is found
            if (A[j] < A[smallIndex])
                smallIndex = j;
        // when finished, swap smallest item with A[i]
       Swap(A[i], A[smallIndex]);
    }
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
//SAME AS ABOVE BUT MODIFIED WITH COUNT VARIABLES
template <class T>
int* SelectionSortStat(T A[], int n){ //    pass array variable!

    int comparison=0,move=0;
    int *output= new int[2];
    // index of smallest item in each pass
    int smallIndex;
    int i, j;
    // compare A[0]...A[n-2] with partof the list after
    for (i = 0; i < n-1; i++){
        // start the scan at index i; set smallIndex to i
        smallIndex = i;
        // j scans the sublist A[i+1]...A[n-1]
        for (j = i+1; j < n; j++){
        // update smallIndex if smaller element is found
            comparison++;//IN IF CONDITION, COMPARASION OCCURS
            if (A[j] < A[smallIndex]){
                smallIndex = j;
            }
        }
        // when finished, swap smallest item with A[i]
        Swap(A[i], A[smallIndex]);
        move=move+3; //SWAP FUNCTION OCCURS
    }
    output[0]=comparison;//STORE DATA
    output[1]=move;

    return output;
}


// QUICK SORT 1-FIRST ELEMENT IS PIVOT********************************************************************
// QUICK SORT 1-FIRST ELEMENT IS PIVOT********************************************************************
// QUICK SORT 1-FIRST ELEMENT IS PIVOT********************************************************************
// QUICK SORT 1-FIRST ELEMENT IS PIVOT********************************************************************
template <class T>
void QuickSort1(T *A, int low, int high){
    T pivot;
    if (low < high) {
        int ScanUp = low + 1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        pivot = A[low]; // Set pivot AS FIRST ELEMENT
        while (true){
            while (ScanUp < high && A[ScanUp] <=pivot)
                ScanUp++; // Increment ScanUp until pivot
            while (ScanDown > low && A[ScanDown] >pivot)
                ScanDown--; // Decrement ScanDown until pivot
            if(ScanUp < ScanDown)// swap A[ScanDown] and A[ScanUp]
                Swap(A[ScanDown],A[ScanUp]);
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(A[ScanDown],A[low]);
        //Recursive calls
        QuickSort1(A,low,ScanDown-1);
        QuickSort1(A, ScanDown+1,high);
    }//end of if low < high
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
template <class T>
void QuickSort1Stat(T *A, int low, int high, int& move, int& comparison){
    T pivot;
    if (low < high) {
        int ScanUp = low + 1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        pivot = A[low]; // Set pivot
        while (true){
            while (ScanUp < high && A[ScanUp] <=pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison++;//WHILE CONDITION CONTAINS COMPARISON
                }
            comparison++; //FOR LAST COMPARISON
            while (ScanDown > low && A[ScanDown] >pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison++; //WHILE CONDITION CONTAINS COMPARISON
            }
            comparison++;//FOR LAST COMPARISON
            if(ScanUp < ScanDown){// swap A[ScanDown] and A[ScanUp]
                Swap(A[ScanDown],A[ScanUp]);
                move=move+3;//SWAP FUNCTION OCCURS
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(A[ScanDown],A[low]);
        move=move+3; //SWAP FUNCTION OCCURS
        //Recursive calls
        QuickSort1Stat(A,low,ScanDown-1,move,comparison);
        QuickSort1Stat(A, ScanDown+1,high,move,comparison);
    }//end of if low < high
}



//// QUICK SORT 2- MIDDLE ELEMENT IS PIVOT************************************************************************
//// QUICK SORT 2- MIDDLE ELEMENT IS PIVOT************************************************************************
//// QUICK SORT 2- MIDDLE ELEMENT IS PIVOT************************************************************************
//// QUICK SORT 2- MIDDLE ELEMENT IS PIVOT************************************************************************
void QuickSort2(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[(left_index + right_index) /2]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) left++;//find low on the right
		while(a[right] > pivot) right--;     //find high on the left
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			left++; right--;
		}
	}

        // recursion
	QuickSort2(a,left_index,right);
	QuickSort2(a,left,right_index);
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
//SAME AS ABOVE BUT MODIFIED WITH COUNTERS
void QuickSort2Stat(int a[], int left_index, int right_index,int& move,int& comparison)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[(left_index + right_index) /2]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot){ left++;comparison++  ;    }//find low on the right
		comparison++  ;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		while(a[right] > pivot) {right--;comparison++;    }     //find high on the left
		comparison++  ;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			move=move+3; //SWAP FUNCTION!
			left++; right--;
		}
	}

        // recursion
	QuickSort2Stat(a,left_index,right, move, comparison);
	QuickSort2Stat(a,left,right_index, move, comparison);
}









//// QUICK SORT 3- RANDOM PIVOT************************************************************************
//// QUICK SORT 3- RANDOM PIVOT************************************************************************
//// QUICK SORT 3- RANDOM PIVOT************************************************************************
//// QUICK SORT 3- RANDOM PIVOT************************************************************************
void QuickSort3(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[ rand()%(right_index-left_index) + left_index ]; //a random element is selected AS PIVOT

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) left++; //find low on the right
		while(a[right] > pivot) right--;//find high on the left
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			left++; right--;
		}
	}

        // recursion
	QuickSort3(a,left_index,right);
	QuickSort3(a,left,right_index);
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
//SAME AS ABOVE BUT MODIFIED TO COLLECT STAT.
void QuickSort3Stat(int a[], int left_index, int right_index,int& move,int& comparison)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[ rand()%(right_index-left_index) + left_index ]; //a random element is selected FOR PIVOT

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) {left++; comparison++; }//find low on the right //
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		while(a[right] > pivot) {right--; comparison++;}//find high on the left
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			move=move+3; //swap occurs
			left++; right--;
		}
	}

        // recursion
	QuickSort3Stat(a,left_index,right,move,comparison);
	QuickSort3Stat(a,left,right_index,move,comparison);
}

//// QUICK SORT 4- MEDIAN OF RANDOM 3 ELEMENTS***************************************************************
//// QUICK SORT 4- MEDIAN OF RANDOM 3 ELEMENTS***************************************************************
//// QUICK SORT 4- MEDIAN OF RANDOM 3 ELEMENTS***************************************************************
//// QUICK SORT 4- MEDIAN OF RANDOM 3 ELEMENTS***************************************************************
void QuickSort4(int a[], int left_index, int right_index,int random[])
{

	int left, right, pivot;
	if(left_index >= right_index) return;

    //random 3 elements seleceted
	random[0]=a[rand()%(right_index-left_index) + left_index ];
    random[1]=a[rand()%(right_index-left_index) + left_index ];
    random[2]=a[rand()%(right_index-left_index) + left_index ];

    BubbleSort(random,3); // to find the median of 3 randoms.

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = random[1]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) left++; //find low on the right
		while(a[right] > pivot) right--;//find high on the left
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			left++; right--;
		}
	}

        // recursion
	QuickSort4(a,left_index,right,random);
	QuickSort4(a,left,right_index,random);
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
void QuickSort4Stat(int a[], int left_index, int right_index,int random[],int& move,int& comparison)
{

	int left, right, pivot;
	if(left_index >= right_index) return;

    //random 3 elements seleceted
	random[0]=a[rand()%(right_index-left_index) + left_index ];
    random[1]=a[rand()%(right_index-left_index) + left_index ];
    random[2]=a[rand()%(right_index-left_index) + left_index ];

    BubbleSort(random,3); // to find the median of 3 randoms.

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = random[1]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) {left++; comparison++; } //find low on the right
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		while(a[right] > pivot) {right--; comparison++; }//find high on the left
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		if(left <= right) { //swap if properly placed
			Swap(a[left],a[right]);
			move=move+3;//swap occurs
			left++; right--;
		}
	}

        // recursion
	QuickSort4Stat(a,left_index,right,random,move,comparison);
	QuickSort4Stat(a,left,right_index,random,move,comparison);
}

//// INSERTION SORT****************************************************************************************
//// INSERTION SORT****************************************************************************************
//// INSERTION SORT****************************************************************************************
//// INSERTION SORT****************************************************************************************
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int low, int high) //to be used in my own algorithm
{
    int i, key, j;
    for (i = low+ 1 ; i < high+1 ; i++)
    {
        key = arr[i]; // STORES THE NEXT ITEM TO COMPARE
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= low && arr[j] > key) //CHECKS THE FORMER VALUES UNTIL RIGHT PLACE FOR KEY IS FOUND
        {
            arr[j + 1] = arr[j];
            j --; //SHIFTS THE BUG VALUES 1 PLACE
        }
        arr[j + 1] = key; //PLACES THE KEY INTO ITS CORRECTS POSITION
    }
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
void insertionSortStat(int arr[], int low, int high,int& move,int& comparison)
{
    int i, key, j;
    for (i = low+ 1 ; i < high+1 ; i++)
    {
        key = arr[i]; // STORES THE NEXT ITEM TO COMPARE
        move++;//data assignemtn occurs
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= low && arr[j] > key) //CHECKS THE FORMER VALUES UNTIL RIGHT PLACE FOR KEY IS FOUND
        {
            comparison++;//compares in while condition
            arr[j + 1] = arr[j];
            move++; //data assignmetn occurs
            j --; //SHIFTS THE BUG VALUES 1 PLACE
        }
        comparison++;
        arr[j + 1] = key; //PLACES THE KEY INTO ITS CORRECTS POSITION
        move++;//data assignment occurs
    }
}

/// MY OWN ALGORITHM-------------------------------------------------------------------------------------------
/// MY OWN ALGORITHM-------------------------------------------------------------------------------------------
/// MY OWN ALGORITHM-------------------------------------------------------------------------------------------
/// MY OWN ALGORITHM-------------------------------------------------------------------------------------------
/* I BUILT OWN SORT BY CHOOSING THE MAIN ALGORITHM TO BE: MIDDLE PIVOT QUICK SORT
AND CHOOSING THE SECONDARY ALGORITHM FOR SORTING SHORT ARRAYS: INSERTION SORT */
void OwnAlgorithm(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	if( right_index-left_index< 20 ){ //If array is small enough,Insertion sort is used,and quicksort bypassed.
        insertionSort(a,left_index,right_index); //exlained above
        return;
        }

	left = left_index; //scan up is the low value
	right = right_index;//scan down is the high value

        // pivot selection
	pivot = a[(left_index + right_index) /2]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) left++; //find low on the right
		while(a[right] > pivot) right--;//find high on the left
		if(left <= right) { //swap if scan values are properly placed
			Swap(a[left],a[right]);
			left++; right--;
		}
	}

        // recursion
	OwnAlgorithm(a,left_index,right);
	OwnAlgorithm(a,left,right_index);
}
//FOR DATA COMPARISONS AND DATA MOVES STATISTICS
void OwnAlgorithmStat(int a[], int left_index, int right_index,int& move,int& comparison)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	if( right_index-left_index< 20 ){ //If array is small enough,Insertion sort is used,and quicksort bypassed.
        insertionSortStat(a,left_index,right_index,move,comparison); //exlained above
        return;
        }

	left = left_index; //scan up is the low value
	right = right_index;//scan down is the high value

        // pivot selection
	pivot = a[(left_index + right_index) /2]; //middle element is selected

        // partition
	while(left <= right) {   //scan up and down are properly placed
		while(a[left] < pivot) {left++; comparison++;} //find low on the right
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		while(a[right] > pivot) {right--; comparison++;}//find high on the left
		comparison++;//FOR EACH WHILE LOOP COMPAROSIN OCCURS
		if(left <= right) { //swap if scan values are properly placed
			Swap(a[left],a[right]);
			move=move+3; //swap function occures
			left++; right--;
		}
	}

        // recursion
	OwnAlgorithmStat(a,left_index,right,move,comparison);
	OwnAlgorithmStat(a,left,right_index,move,comparison);
}






#endif // SORTINGALGORITHMS_H_INCLUDED
