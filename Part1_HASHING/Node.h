#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
using namespace std;

// FIRST DEFINE NODE TO IMPLEMENT LINKED LISTS
class Node{
private:
    long long TC;
    Node* next;
public:
    Node();//TC IS ZERO AND NEXT IS NULL
    Node(long long input);//INPUT IS THE NEW TC AND NEXT IS NULL
    void AddAfter(long long item);//CREATE NEXT LINK AND ASSIGN ITEM TO ITS TC
    void DeleteAfter(); //Makes necessary adjustments, then deletes next node
    void SetNext(Node* item); //To change the next variable
    Node* GetNext();//RETURN NEXT LINK LOCATION
    long long GetTC();//RETURN TC VALUE
};
Node::Node(){
    TC=0;
    next=NULL; //incase of creating a node with no input
    cout<<"A default node is created"<<endl; // it is unwanted so i want an error message
}
Node::Node(long long input){
    TC=input;
    next=NULL;
}
void Node::AddAfter(long long item){
    next=new Node(item);
}
Node* Node::GetNext(){
    return next;
}
long long Node::GetTC(){
    return TC;
}
void Node::SetNext(Node* input){
    next=input;
}
void Node::DeleteAfter(){
    Node* temp;
    temp=next;
    next= next->GetNext(); //save the rest of the chain
    delete temp;  //delete the next node
}


#endif // NODE_H_INCLUDED
