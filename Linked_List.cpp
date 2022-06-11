#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    int data;
    Node *next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    };

    Node(int k,int d){
        key=k;
        data=d;
        
    };
};

class Singlylinkedlist{
    public:
    Node* head;
    Singlylinkedlist(){
        head=NULL;
    }
    Singlylinkedlist(Node *n){
        head=n;
    }

    // 1 Checking whether that node existed or not
    Node* NodeExist(int k){
        Node *temp=NULL;
        Node *ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
             ptr=ptr->next;
            
        }
        return temp;
       
    };

    //2 Appending Node into the list
    void AppendNode(Node *n){
        if(NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already Exist"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Data appended Successfully."<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Data appended Successfully."<<endl;
            }
        }
    }

    //3 Inserting node at begining
    void prependNode(Node *n){
        if(NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already Exist"<<n->key<<"try with another key"<<endl;
        }
        else
        {
            n->next=head;
            head=n;
            cout<<"Data appended Successfully."<<endl;
        }
        
    }

    //4 Insert node after particular node in the list
    void InsertNode(int k,Node *n){
        Node *ptr=NodeExist(k);
        if(ptr==NULL)
        {
            cout<<"No node exist with key value"<<k<<endl;
        }
        else
        {
            if(NodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist"<<n->key<<"try with another key"<<endl;
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node Inserted Successfully."<<endl;
            }
        
            
        }
    }

    //5 Deleting node by unique key
    void DeletNode(int k){
        if(head==NULL)
        {
            cout<<"List is empty, how could you delete, u bloody fool"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
                head=head->next;
                cout<<"Node UNLINKED with keys value: "<<k<<endl;
            }
            else
            {
                Node *temp=NULL;
                Node *preptr=head;
                Node *currptr=head->next;
                while(currptr!=NULL)
                {
                    if(currptr->key==k)
                    {
                        temp=currptr;
                        currptr=NULL;
                    }
                    else{
                        preptr=preptr->next;
                        currptr=currptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    preptr->next=temp->next;
                    cout<<"Node UNLINKED with keys value : "<<k<<endl;
                }
                else{
                    cout<<"There is no node existed with this key value"<<k<<endl;
                }
            }
        }
    }

    //6 Update data of the node
    void UpdateNode(int k,int d){
        Node *ptr=NodeExist(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Node Data updated successfully."<<endl;
        }
        else{
            cout<<"Node Doesn't Exist with that key value: "<<k<<endl;
        }
    }

    //7 Printing Linked List
    void printlist(){
        if(head==NULL)
        {
            cout<<"List was Empty."<<endl;
        }
        else{
            cout<<"Singly Linked list is: "<<endl;
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<") --> ";
                temp=temp->next;
            }
        }
    }

};



int main(){
   Singlylinkedlist s; //object s created
   int option;
   int key1,data1,k1;
   do{
    cout<<"\nWhat Operation do you want perform? Select opton number 0 to 7:\n"<<endl;
    cout<<"1.Append Node()"<<endl;
    cout<<"2.Prepend Node(Begining)()"<<endl;
    cout<<"3.Insert Node(middle)()"<<endl;
    cout<<"4.Delete Node()"<<endl;
    cout<<"5.Update Node Value()"<<endl;
    cout<<"6.Print List()"<<endl;
    cout<<"7.Clear Screen"<<endl;

    cin>>option;
    Node* n1=new Node();
    
    switch(option)
    {
        case 0:
            break;
        case 1:
            cout<<"Append Node operation \nEnter key & data of the node to be append"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.AppendNode(n1);
            break;
        case 2:
            cout<<"Prepend Node operation \nEnter key & data to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;
        case 3:
            cout<<"Insert Node after operation\nEnter key of existing node after which you want to insert this new node:"<<endl;
            cin>>k1;
            cout<<"\nEnter key & data to insert:"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.InsertNode(k1,n1);
            break;
        case 4:
            cout<<"Delete node operation\nEnter key of the node to be deleted"<<endl;
            cin>>k1;
            s.DeletNode(k1);
            break;
        case 5:
            cout<<"Update node by key operation\nEnter key and NEW data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.UpdateNode(key1,data1);
            break;
        case 6:
            s.printlist();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<<"Enter Proper option number "<<endl;

    }

   }while(option!=0);


    return 0;
}