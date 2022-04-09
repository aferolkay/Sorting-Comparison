#include <iostream>
#include "SortingAlgorithms.h"
#include <ctime>
using namespace std;
//TIME SPENT  PART 2 OF THE PA3 IS 12 HOURS

// reading a text file
#include <fstream>
#include <sstream>
#include <string>
//creates  a fitting matrix containing the TCs in the file
int* LoadFromFile(string filename){ //WORKS FINE
    string line;
    ifstream myfile (filename);
    int i=0,count=0;
    int* myArray;
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //load to file, find number of elements
        {
            getline (myfile,line);
            count++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    myArray = new int[count]; // create an proper matrix to store the file

    ifstream myfile2 (filename); //again load the file,but this time store
    if (myfile2.is_open())
    {
        while (! myfile2.eof() )
        {
            getline (myfile2,line);
            stringstream converter(line);//convert strings into numbers
            converter>>myArray[i]; // load into the array
            i++;
        }
        myArray[i]=(int)NULL;
        myfile2.close();
    }

    else cout << "Unable to open file";
    return myArray;
}

int** RandomInput5(int N){ //CREATES 5 RANDOM ARRAY WITH N ELEMENTS FOR AVERAGE STATISTIC CALCULATION
    srand(time(0));
    int** output;
    output = new int*[5];
    for(int j=0;j<5;j++){
        output[j]= new int[N];
        for(int i=0;i<N;i++)
            output[j][i]=rand();
        output[j][N]=(int)NULL;
    }
    return output;
}

void AverageStatistics(int N,int** Array){ //THIS FUNCTION IS ORIGINALLY TAKEN FROM CASE 7 BELOW, IN THE MAIN FUNCTION
                                            // BUT MODIFIED TO BE APPLIED TO 5 DIFFERENT ARRAYS TO CALCULATE AVERAGE STATISTICS
            double start,finish,elapsed_time=0;
            //CREATING resolution IDENTICAL DUMMY ARRAYS TO BE SORTED FOR ELAPSE TIME TESTINH.
            //(LATER TO BE DEALLOCATED)
            int** dummy;
            int resolution=200; //THIS PARAMETER DECIDES NUMBER OF IDENTICAL ARRAYS TO BE SORTED, NAME IS RESOLUTION SINCE MORE THE ARRAYS MORE CORRECT RESULT.

            dummy= new int*[resolution+1];/*TO HOLD RESOULTION+1 ARRAYS
                                            RESOLUTION TO BE NORMALLY SORTED,
                                            +1 FOR ACQUIRING STATISTICS OF ALGORITHMS.*/
            for(int i=0;i<resolution+1;i++)
                dummy[i] = new int[N];
            //For keeping track of statistics
            int move=0,avg_move=0;
            int comparison=0,avg_comparison=0;
            int* stat;
            cout<<"Array Size:"<<N<<"numbers"<<endl;
            cout<<"Algorithm    #comparisons    #moves  time (ms)"<<endl;

            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///BUBBLE SORT TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];

                //cout<<"Bubble Sort Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    BubbleSort(dummy[i],N);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW

                stat=BubbleSortStat(dummy[resolution],N);

                avg_comparison+=stat[0];
                avg_move+=stat[1];
            }
            cout<<"Bubble       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl;//  /5 FOR TAKING AVERAGE

            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;

            for(int z=0;z<5;z++){ //APPLY TO 5 DIFFERENT ARRAYS
            ///QUICK SORT 1 TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"Quick Sort 1 Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    QuickSort1(dummy[i],0,N-1);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"Quick Sort 1 Performing Time:"<<elapsed_time<<" ms"<<endl;
                move=0;
                comparison=0;
                QuickSort1Stat( dummy[resolution] ,0,N-1,move,comparison);
                avg_comparison+=comparison; //SUM ALL 5
                avg_move+=move;
            }
            cout<<"Quick1       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl;//5 FOR TAKING AVERAGE


            //RESTART THE STATS FOR THE NEXT
            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;






            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///QUICK SORT 2 TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"Quick Sort 2 Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    QuickSort2(dummy[i],0,N-1);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"Quick Sort 2 Performing Time:"<<elapsed_time<<" ms"<<endl;
                move=0;
                comparison=0;
                QuickSort2Stat(dummy[resolution],0,N-1,move,comparison);
                avg_comparison+=comparison;
                avg_move+=move;//SUM ALL 5
            }
            cout<<"Quick2       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl;//5 FOR TAKING AVERAGE

        //RESTART TO USE AGAIN
            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;



            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///QUICK SORT 3 TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"Quick Sort 3 Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    QuickSort3(dummy[i],0,N-1);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"Quick Sort 3 Performing Time:"<<elapsed_time<<" ms"<<endl;
                move=0;
                comparison=0;
                QuickSort3Stat(dummy[resolution],0,N-1,move,comparison);
                avg_comparison+=comparison;
                avg_move+=move;//SUM ALL 5
            }
            cout<<"Quick3       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl;//5 FOR TAKING AVERAGE
        //TO USE THEM AGAIN
            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;


            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///QUICK SORT 4 TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"Quick Sort 4 Testing..."<<endl;
                int random[3]; // NECESSARY FOR FINDING A MEDIAN
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    QuickSort4(dummy[i],0,N-1,random);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"Quick Sort 4 Performing Time:"<<elapsed_time<<" ms"<<endl;
                move=0;
                comparison=0;
                QuickSort4Stat(dummy[resolution],0,N-1,random,move,comparison);
                avg_comparison+=comparison;
                avg_move+=move;//SUM ALL 5
            }
            cout<<"Quick4       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl; // DIVIDE BY 5 TO TAKE AVERAGE
            //USE THEM AGAIN
            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;



            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///SELECTION SORT TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"Selection Sort Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    SelectionSort(dummy[i],N);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"Selection Sort Performing Time:"<<elapsed_time<<" ms"<<endl;
                stat=SelectionSortStat(dummy[resolution],N);
                comparison=stat[0];
                move=stat[1];
                avg_comparison+=stat[0]; //SUM ALL 5
                avg_move+=stat[1];
            }
            cout<<"Selection       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl;//DIVIDE BY5 TO AVERAGE

            //RESTART TO USE AGAIN
            avg_comparison=0;
            avg_move=0;
            elapsed_time=0;

            for(int z=0;z<5;z++){//APPLY TO 5 DIFFERENT ARRAYS
                ///OWN ALGORITHM TESTING
                //Making the arrays identical to original
                for(int i=0;i<resolution+1;i++)
                    for(int j=0;j<N;j++)
                        dummy[i][j]=Array[z][j];
                //cout<<"My Own Sort Testing..."<<endl;
                //time resolution operation
                start= double(clock());
                for(int i=0;i<resolution;i++)
                    OwnAlgorithm(dummy[i],0,N-1);
                finish= double(clock());
                elapsed_time+=(finish-start)/resolution; //DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                //cout<<"My Own Sort Performing Time:"<<elapsed_time<<" ms"<<endl;
                move=0;
                comparison=0;
                OwnAlgorithmStat(dummy[resolution],0,N-1,move,comparison);
                avg_comparison+=comparison;
                avg_move+=move;//SUM ALL 5

            }
            cout<<"Own Algorithm       "<< avg_comparison/5<<"            "<<avg_move/5<<"     "<<elapsed_time/5<<endl; //DIVIDE BY 5 TO TAKE AVERAGE



            // deleting the memory allocated for testing
            for(int i=0;i<resolution+1;i++)
                delete[] dummy[i];
            delete [] dummy;



}


int* RandomInput(int N){ //CREATES A SINGLIE ARRAY WITH N ELEMENTS TO BE SORTED
    int* output;
    output= new int[N];
    for(int i=0;i<N;i++)
        output[i]=rand();

    output[N]=(int)NULL;
    return output;
}

void Print(int* Array,int N){ // PRINTS ARRAY , 4 ELEMENT EACH ROW TO BE MORE READABLE
    cout<<"*********ARRAY CONTENT**********"<<endl;
    for(int i=0;i<N;i++){
        cout<<Array[i]<<"   ";
        if( (i+1)%4==0)
            cout<<endl;
    }
    cout<<endl;
}


int main(){

    int* Array=NULL;// STORE ARRAY TO BE SORTED
    char a='y'; //TO BE ABLE TO FINISH PROGRAM
    int operation;//TO STORE THE INPUT FOR WHICH OPERATION TO EXECUTE
    int N;//NUMBER OF ELEMENT OF THE ARRAY TO BE SORTED
    int type;//TO DECIDE ON WHICH VARIANT OF THE QUICKSORT TO EXECUTE
    double start,finish,elapsed_time;//STORE TIME

    while(a=='y'){
        cout<<endl<<"-------------MENU--------------"<<endl;
        cout<<"1. Initialize input array randomly"<<endl;
        cout<<"2. Load input from a file"<<endl;
        cout<<"3. Perform Bubble Sort"<<endl;
        cout<<"4. Perform Quick Sort"<<endl;
        cout<<"5. Perform Selection Sort"<<endl;
        cout<<"6. Perform Your Own Sort"<<endl;
        cout<<"7. Compare sorting algorithms"<<endl;
        cout<<"8. Print Array"<<endl;
        cout<<"9. Leave"<<endl;
        cout<<"10. Average Statistics(for report)"<<endl;


        cout<<"Choose your operation:"; cin>>operation;

        switch(operation){

        case 1:
            {
            cout<<"Please enter the desired size of the random array to be created:";
            cin>>N; //array sıze
            cout<<endl;
            Array=RandomInput(N);// CREATE RANDOM ARRAY ACCORDING TO N
            cout<<"Array created!"<<endl;
            break;
            }
        case 2:
            {
            int i=1;
            Array=LoadFromFile("input_array.txt"); // ARRAY IS LOADED FROM FILE
            while(Array[i]!=(int)NULL)
                i++;//TO FIND HOW MANY ELEMENTS FILE CONTAINS
            N=i;//NOW WE KNOW N
            cout<<"Array with N="<<N<<" is created!"<<endl;
            break;
            }
        case 3:
            {
            if(Array==NULL) {cout<<"Array hasn't initialized yet!"<<endl; break;}
            BubbleSort(Array,N);//BUBBLE SORTED
            cout<<"Sorted!"<<endl;
            Print(Array,N);

            break;
            }


        case 4:
            {
            if(Array==NULL) {cout<<"Array hasn't initialized yet!"<<endl; break;}
            cout<<"Please enter which type of QuickSort to perform:";
            cin>>type;
            if(type==1) QuickSort1(Array,0,N-1); //USES THE INPUTTED VARIANT FOR QS
            if(type==2) QuickSort2(Array,0,N-1);
            if(type==3) QuickSort3(Array,0,N-1);
            if(type==4){int random[3];   QuickSort4(Array,0,N-1,random);}//RANDOM ARRAY IS INPUTTED TO CHOOSE RANDOM PIVOT
            cout<<endl<<"Sorted!"<<endl;
            Print(Array,N);

            break;
            }

        case 5:
            {
            if(Array==NULL) {cout<<"Array hasn't initialized yet!"<<endl; break;}
            SelectionSort(Array,N);//SELECTION SORTED
            cout<<"Sorted!"<<endl;
            Print(Array,N);
            break;
            }
        case 6:
            {
            if(Array==NULL) {cout<<"Array hasn't initialized yet!"<<endl; break;}
            OwnAlgorithm(Array,0,N-1);//MY OWN ALGORITHM IS USED
            cout<<"Sorted!"<<endl;
            Print(Array,N);
            break;
            }

        case 7:
            {
            if(Array==NULL) {cout<<"Array hasn't initialized yet!"<<endl; break;}
            //CREATING resolution IDENTICAL DUMMY ARRAYS TO BE SORTED FOR ELAPSE TIME TESTINH.
            //(LATER TO BE DEALLOCATED)
            int** dummy;
            int resolution=200; //THIS PARAMETER DECIDES NUMBER OF IDENTICAL ARRAYS TO BE SORTED, NAME IS RESOLUTION SINCE MORE THE ARRAYS MORE CORRECT RESULT.
            dummy= new int*[resolution+1];/*TO HOLD RESOULTION+1 ARRAYS
                                            RESOLUTION TO BE NORMALLY SORTED,
                                            1 FOR ACQUIRING STATISTICS OF ALGORITHMS.*/
            for(int i=0;i<resolution+1;i++)
                dummy[i] = new int[N];
            //For keeping track of statistics
            int move;
            int comparison;
            int* stat;
            cout<<"Array Size:"<<N<<"numbers"<<endl;
            cout<<"Algorithm    #comparisons    #moves  time (ms)"<<endl;

            ///BUBBLE SORT TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Bubble Sort Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
                BubbleSort(dummy[i],N);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;
            //cout<<"Bubble Sort Performing Time:"<<elapsed_time<<" ms"<<endl;
            stat=BubbleSortStat(dummy[resolution],N);
            comparison=stat[0];
            move=stat[1];
            cout<<"Bubble   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;

            ///QUICK SORT 1 TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Quick Sort 1 Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                QuickSort1(dummy[i],0,N-1);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"Quick Sort 1 Performing Time:"<<elapsed_time<<" ms"<<endl;
            move=0;
            comparison=0;
            QuickSort1Stat(dummy[resolution],0,N-1,move,comparison);
            cout<<"Quick1   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;


            ///QUICK SORT 2 TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Quick Sort 2 Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                QuickSort2(dummy[i],0,N-1);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"Quick Sort 2 Performing Time:"<<elapsed_time<<" ms"<<endl;
            move=0;
            comparison=0;
            QuickSort2Stat(dummy[resolution],0,N-1,move,comparison);
            cout<<"Quick2   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;

            ///QUICK SORT 3 TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Quick Sort 3 Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                QuickSort3(dummy[i],0,N-1);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"Quick Sort 3 Performing Time:"<<elapsed_time<<" ms"<<endl;
            move=0;
            comparison=0;
            QuickSort3Stat(dummy[resolution],0,N-1,move,comparison);
            cout<<"Quick3   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;


            ///QUICK SORT 4 TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Quick Sort 4 Testing..."<<endl;
            int random[3]; // NECESSARY FOR FINDING A MEDIAN
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                QuickSort4(dummy[i],0,N-1,random);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"Quick Sort 4 Performing Time:"<<elapsed_time<<" ms"<<endl;
            move=0;
            comparison=0;
            QuickSort4Stat(dummy[resolution],0,N-1,random,move,comparison);
            cout<<"Quick4   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;





            ///SELECTION SORT TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"Selection Sort Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                SelectionSort(dummy[i],N);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"Selection Sort Performing Time:"<<elapsed_time<<" ms"<<endl;
            stat=SelectionSortStat(dummy[resolution],N);
            comparison=stat[0];
            move=stat[1];
            cout<<"Selection   "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;



            ///OWN ALGORITHM TESTING
            //Making the arrays identical to original
            for(int i=0;i<resolution+1;i++)
                for(int j=0;j<N;j++)
                    dummy[i][j]=Array[j];
            //cout<<"My Own Sort Testing..."<<endl;
            //time resolution operation
            start= double(clock());
            for(int i=0;i<resolution;i++)
                OwnAlgorithm(dummy[i],0,N-1);
            finish= double(clock());
            elapsed_time=(finish-start)/resolution;//DIVIDES BY HOW MANY ARRAYS IT SORTED IN TIME WINDOW
            //cout<<"My Own Sort Performing Time:"<<elapsed_time<<" ms"<<endl;
            move=0;
            comparison=0;
            OwnAlgorithmStat(dummy[resolution],0,N-1,move,comparison);
            cout<<"Own Algo    "<<comparison<<"    "<<move<<"  "<<elapsed_time<<endl;


            // deleting the memory allocated for testing
            for(int i=0;i<resolution+1;i++)
                delete[] dummy[i];
            delete [] dummy;

            break;
            }
        case 8:
            {
              Print(Array,N);
            break;
            }
        case 9:
            a='n';
            break;

        case 10:
            cout<<"Please enter the array size N:";
            cin>>N;
            cout<<endl;
            AverageStatistics(N,RandomInput5(N) ); //EXPLAINED AT THE TOP

            break;

        default:
            {
            cout<<"Please enter a valid operation!";
            a='y';
            break;
            }
        }
    }


return 0;
}
