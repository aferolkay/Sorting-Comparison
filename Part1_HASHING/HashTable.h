#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <math.h>
using namespace std;

// Hash Functions
int Folding(long long key,int N){
    int div1,div2,div3,div4;
    // already know it'll be 11 digit number
    div4 = key % 100; //FIND LAST 2
    key = key / 100;//DELETE LAST DIGITS
    div3= key % 1000; //FIND GROUPS OF 3
    key=key/ 1000;//DELETE LAST DIGITS
    div2= key % 1000;//FIND GROUPS OF 3
    key=key/ 1000; //DELETE LAST DIGITS
    div1= key % 1000;//FIND GROUPS OF 3
    return (div1+div2+div3+div4)%N ;
}
int MiddleSquaring(long long key,int N){ //WORKS FINE
    // already know it'll be 11 digit number
    long middle = ( key % (long)(pow(10,7) )) /pow(10,4); //FINDS MIDDLE 3 DIGITS
    return (middle*middle)%N;
}
int Truncation(long long key,int N){ //WORKS FINE
    return (key%100)%N; //FIRST FIND LAST 2 DIGIT THEN TAKE MOD
}
//NOW FUNCTIONS TO INITIALIZE HASH TABLE
Node** InitHashTable(int N){ //Initializes hash table with size N and assigns NULL to each.
    Node ** address;
    address = new Node*[N]; // TO ASSIGN NODE POINTER TO EACH TABLE SLOT
    for (int i=0 ; i<N ; i++ )  address[i]=NULL; // AT FIRST THEY ARE EMPTY
    return address; //RETURN TABLE POINTER
}

Node* Search(long long key, int hash_out, Node**HashTable ); //PRE DECLARATION, FUNCTION BELOW


void AddNumber(long long key,int place,Node ** HashTable){ //TO ADD TCS
    if( HashTable==NULL ) {cout<<"Hash Table hasn't been initialized!"; return;} //NO INITIALIZATION YET
    else{ //INITIALIZED
        if( HashTable[place]!=NULL ){ //collison occurs
            Node* temp=HashTable[place];
            while( temp->GetNext() !=NULL ){//get to the last link
                if( Search(key,place,HashTable)!=NULL ){  //CHECK IF TC ALREADY EXIST
                    cout<<"TC already exists"<<endl;
                    return ;
                }//TC already exist, RETURN IMMDEIATELY
                temp=temp->GetNext(); //JUM TO NEXT LINK
            }
            temp->AddAfter(key);        //append the new key to the end of the list
        }

        else
           HashTable[place]= new Node(key); // no collison SO PLACE IT IMMEDIATELY
    }
}

void PrintTable(Node** HashTable,int N){ //PRINTS TABLE
    Node* temp;

    for(int i=0; i<N ; i++){
        temp=HashTable[i];
        cout<<i<<".";
        if(temp!=NULL){ // slot is not empty
            cout<<temp->GetTC();
            temp=temp->GetNext();
            while(temp!=NULL){ //IF COLLISION, MAKES SURE TO PRINT IN SAME ROW
                cout<<"-->"<<temp->GetTC();
                temp=temp->GetNext();
            }
            cout<<endl;
        }
        else cout<<"Empty"<<endl;
    }
}

Node* Search(long long key, int hash_out, Node**HashTable ){ // takes table and the hash(key) as input and searches if key exists.
    if( HashTable==NULL ) {cout<<"Hash Table hasn't been initialized!"; return NULL;}
    Node* temp=HashTable[hash_out];
    if(temp!=NULL){
        while(temp!=NULL){ //slot is not empty
            if( key == temp->GetTC() ){ //loops until TC is found
                //cout<<"TC number is found!";
                return temp;
            }
            temp=temp->GetNext();

        }
        return NULL; //TC isn't found so don't exist  cout<<"TC number doesn't exist!";
        }

    else{ //Slot is empty.
        return NULL;} //empty cout<<"TC number doesn't exist!"


}

bool Delete(long long key,int hash_out, Node**HashTable){ //DELETE
    Node* temp=HashTable[hash_out];

    if(temp!=NULL){ //slot is not empty

        if(temp->GetTC() == key){ //key is in the first node
            HashTable[hash_out]=temp->GetNext(); //first node is now not a part of the chain
            delete temp; // node containing the key is deleted.
            cout<<"TC number is found and deleted!"<<endl;

            return true; //deletion competed
        }

        else{ //key is deeper into the chain
                while(temp != NULL){ //travel until we found the key.
                    if( temp->GetNext()!=NULL  ){// check if the value is the key only if the value exists.
                        if( key == temp->GetNext()->GetTC() ){ //Next TC is the one we search for.

                            cout<<"TC number is found and deleted!"<<endl;//IF EXECUTED, DELETION OCCUR.
                            temp->DeleteAfter();
                            return true;
                        }
                    }
                    temp=temp->GetNext(); //to go deeper
                }
        }

        return false ; //TC isn't found so don't exist 1 100 truncation 2 4 52436392198
    }

    else{ return false;} //slot is empty
}

int CalculateCollision(Node** HashTable,int N){
    int count=0;
    for(int i=0; i<N; i++ ){  // go through every slot
        if( HashTable[i]!=NULL ){ //slot is not empty
            Node* temp= HashTable[i]->GetNext();
            while(temp!=NULL){ //count++ everytime collision happens
                count++;
                temp=temp->GetNext();
            }
        }
    }
    return count;
}




#endif // HASHTABLE_H_INCLUDED
