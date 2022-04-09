#include <iostream> // used in hash table
#include "Node.h"
#include "HashTable.h"
using namespace std;

// TIME SPENT FOR PART 1: 14 HOURS

//my power function
long long power(int a,int b){
    long long result=1;
    for (int i=0;i<b;i++)
        result=result*a;
    return result;
}

#include <time.h>
#include <math.h>
// To create Random TC
unsigned long long Randomize(){ //WORKS FINE
    unsigned long long randnumber = 0;
    int digits[11];


    for (int i = 11; i >= 1; i--)
    {
      digits[i]=rand()%10;
    }
    for(int i=11; i>=1; i--)
    {
       unsigned long long power = pow(10, i-1);

        if (power%2 != 0 && power != 1)     //eliminates "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power * digits[i];
    }
return randnumber;
}


// reading a text file
#include <fstream>
#include <sstream>
#include <string>
//creates  a fitting matrix containing the TCs in the file
long long* LoadFromFile(string filename){
    string line;
    ifstream myfile (filename);
    int i=0,count=0;
    long long* myArray;
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

    myArray = new long long[count]; // create an proper matrix to store the file

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


int main() {

    int N=1;
    string method;
    Node** HashTable=NULL;
    int operation=0;
    long long key;
    long long*file;
    char a='y';


    while(a=='y'){
        cout<<endl<<"-------------MENU--------------"<<endl;
        cout<<"1. Initialize Hash Table"<<endl;
        cout<<"2. Load T.C. ID Numbers from file"<<endl;
        cout<<"3. Add new T.C. ID Number"<<endl;
        cout<<"4. Delete a T.C. ID Number"<<endl;
        cout<<"5. Search for a T.C. ID Number"<<endl;
        cout<<"6. Print out Hash Table"<<endl;
        cout<<"7. Count Collisions"<<endl; //FOR REPORT
        cout<<"8. Leave"<<endl;


        cout<<"Choose your operation:"; cin>>operation;

        switch(operation){

        case 1:
            {
            cout<<"Please enter the size of Hash Table:";
            cin>>N; cout<<endl;
            cout<<"Please enter the Hash Function:";
            cin>>method; cout<<endl; //INPUTS METHOD TO LATER HASH ACCORDINGLY
            /*
            NOTE: In console application, when asked to enter the hashing function,
            write the corresponding:
            Folding: “folding “
            Middle Squaring: “middlesquaring”
            Truncation: ”truncation
            */
            if(method!="folding"&&method!="middlesquaring"&&method!="truncation"){
                cout<<"invalid function, please try initializing again"; break;}
            HashTable = InitHashTable(N); //INITIATES TABLE ACCORDING TO INPUTTED N
            cout<<"Hash Table successfully created!"<<endl;
            break;
            }
        case 2:
            {
            file = LoadFromFile("hash_table_init.txt"); //file is loaded into array
            int i=0;
            //applies the entered hash function
            if(method=="folding")
                while (file[i]!=(int)NULL ){ //ONE BY ONE ADDS THE TC TO THE TABLE
                    AddNumber( file[i] , Folding(file[i],N) , HashTable );
                    i++;
                }
            else if(method=="middlesquaring")
                while (file[i]!=(int)NULL ){//ONE BY ONE ADDS THE TC TO THE TABLE
                    AddNumber( file[i] , MiddleSquaring(file[i],N) , HashTable );
                     i++;
                }
                else if(method=="truncation")
                    while (file[i]!=(int)NULL ){//ONE BY ONE ADDS THE TC TO THE TABLE
                        AddNumber( file[i] , Truncation(file[i],N) , HashTable );
                         i++;
                    }
                    else cout<<"Hash Function name entered incorrectly!"<<endl; //ERROR HANDLING
            if(i==0){cout<<"File couldn't be loaded, possible Hash table haven't been initialized!"<<endl; break;}//ERROR HANDLING
            cout<<i<<" T.C. ID numbers successfully loaded!"<<endl;//NO ERROR SO SUCCESSFULL
            break;
            }
        case 3:
            {
            cout<<"Enter the T.C. ID Number to be added:"; cin>>key; //MANUALLY ADD TC
            if ( power(10,10) <= key && key < power(10,11) ){//CONTROLS IF 11 DIGIT IF NOT GIVES ERROR
                if(method=="folding") {
                    if(Search(key,Folding(key,N),HashTable)==NULL){//CHECKS IF KEY EXISTS ALREADY
                        AddNumber(key,Folding(key,N),HashTable);//IF NOT ADDS ACCORDING TO FOLDING
                        cout<<key<<" is successfully added!";
                    }
                    else
                        cout<<key<<" already exist! ";//ERROR HANDLING
                }

                else if(method=="middlesquaring"){
                    if(Search(key,MiddleSquaring(key,N),HashTable)==NULL){//CHECKS IF KEY EXISTS ALREADY
                        AddNumber(key,MiddleSquaring(key,N),HashTable);//IF NOT ADDS ACCORDING MIDDLE SQUARING
                        cout<<key<<" is successfully added!";
                    }
                    else
                        cout<<key<<" already exist! ";//ERROR HANDLING
                }

                    else{
                        if(Search(key,Folding(key,N),HashTable)==NULL){//CHECKS IF KEY EXISTS ALREADY
                            AddNumber(key,Truncation(key,N),HashTable);//IF NOT ADDS ACCORDING TRUNCATION
                            cout<<key<<" is successfully added!";
                        }
                        else
                            cout<<key<<" already exist! ";//ERROR HANDLING
                    }
                break;
            }
            else {cout<<"Invalid input: T.C. ID should be consisting of 11 digits!"; break;}//ERROR HANDLING

            }
        case 4:
            {
            cout<<"Enter the T.C. ID Number to be deleted:"; cin>>key; //TO DELETE EXISTING TC
            if ( power(10,10) <= key && key < power(10,11) ){//CONTROLS IF 11 DIGIT IF NOT GIVES ERROR
                if(method=="folding"){
                    if(Delete(key,Folding(key,N),HashTable)); //CHECKS IF EXIST AND IF SO DELETE
                    else
                        cout<<"TC number couldn't be deleted:Either doesn't exist or falsely placed."<<endl;
                }
                else if(method=="middlesquaring"){
                    if(Delete(key,MiddleSquaring(key,N),HashTable));//CHECKS IF EXIST AND IF SO DELETE
                    else
                        cout<<"TC number couldn't be deleted:Either doesn't exist or falsely placed."<<endl;
                }
                    else{
                        if(Delete(key,Truncation(key,N),HashTable));//CHECKS IF EXIST AND IF SO DELETE
                        else
                            cout<<"TC number couldn't be deleted:Either doesn't exist or falsely placed."<<endl;

                    }
            }
            else
                cout<<"Invalid input: T.C. ID should be consisting of 11 digits!";//ERROR HANDLING
            break;
            }

        case 5:
            {
            cout<<"Enter the T.C. ID Number to be searched:"; cin>>key; //CONTROLS IF TC EXISTS IN TABLE
            if ( power(10,10) <= key && key < power(10,11) ){//CONTROLS IF 11 DIGIT IF NOT GIVES ERROR
                if(method=="folding")//CHECKS ACCORDING TO INPUTTED METOD
                    if(Search(key,Folding(key,N),HashTable)!=NULL) cout<<"T.C. ID Number found!"<<endl; //CHEKS IF EXIST
                    else cout<<"T.C. ID Number cannot found!"<<endl;
                else if(method=="middlesquaring")//CHECKS ACCORDING TO INPUTTED METOD
                    if(Search(key,MiddleSquaring(key,N),HashTable)!=NULL) cout<<"T.C. ID Number found!"<<endl;//CHEKS IF EXIST
                    else cout<<"T.C. ID Number cannot found!"<<endl;
                    else//CHECKS ACCORDING TO INPUTTED METOD
                        if(Search(key,Truncation(key,N),HashTable)!=NULL) cout<<"T.C. ID Number found!"<<endl;//CHEKS IF EXIST
                        else cout<<"T.C. ID Number cannot found!"<<endl;
            }
            else {cout<<"Invalid input: T.C. ID should be consisting of 11 digits!"; break;}
            break;
            }
        case 6:
            {
            cout<<"***HASH TABLE***"<<endl;
            PrintTable(HashTable,N); //PRINTS TCS
            break;
            }

        case 7:
            {
            cout<<"Number of collisions for N="<<N<<" and method="<<method<<":"<<CalculateCollision(HashTable,N)<<endl; //FOR REPORT WRITING
            break;
            }
        case 8:
            a='n'; //TO EXIST CHANGE WHILE CONDITION
            break;
        default:
            {
            cout<<"Please enter a valid operation!";// ERROR HANDLING
            a='n';
            break;
            }
        }


  }
return 0;
}
