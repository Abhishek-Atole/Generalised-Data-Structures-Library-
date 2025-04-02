#include<iostream>
using namespace std;


#pragma pack(1)

// structure for Singly linked list
template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};


// structure for Doubly linked list
template<class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

/////// Singly Linear Linked List /////////

template<class T>
class SinglyLL
{
    public:
       struct nodeS <T>* Head;
       int Count;

       SinglyLL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();

};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    Head = NULL;
    Count = 0;  
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;   
}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int Pos)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    struct nodeS <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int Pos)
{
    struct nodeS <T>* temp1 = Head;
    struct nodeS <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    Count--;    
}

template<class T>
void SinglyLL<T> :: Display()
{
    struct nodeS <T>* temp = Head;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<< " |->";
        temp = temp->next;
    }
    cout<<"NULL\n";   
}



///////// Singly Circular Linked List ////////

template<class T>
class SinglyCL
{
    public:
        int Count;
        struct nodeS <T>* Head;
        struct nodeS <T>* Tail;

    SinglyCL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();
        
};

template<class T>
SinglyCL <T> :: SinglyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCL <T> :: InsertFirst(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL )
    {
        Head = Tail = newn;
        Tail->next = Head;
    }
    else
    {
        newn->next = Head;
        Head = newn;
        Tail->next = Head;
    }
    Count++;   
}


template<class T>
void SinglyCL <T> :: InsertLast(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
        (Tail)->next = Head;
    }
    else
    {
        (Tail)->next = newn;
        Tail = newn;
        (Tail)->next = Head;
    }
    Count++;    
}


template<class T>
void SinglyCL<T> :: Display()
{
    struct nodeS<T>* temp = Head;
    
    cout<<"<-";
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    } while (temp != Tail->next);
    cout<<"\n";   
}

template<class T>
void SinglyCL <T> :: DeleteFirst()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        Tail->next = Head;
        delete temp;
    }
    Count--;    
}

template<class T>
void SinglyCL <T>:: DeleteLast()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != Head)
        {
            temp = temp->next;
        }
        Tail->next = Head;
        Tail = temp;
        delete temp->next;
    }
    Count--;    
}

template<class T>
void SinglyCL <T> :: InsertAtPos(T no, int Pos)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    struct nodeS <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyCL <T> :: DeleteAtPos(int Pos)
{
    struct nodeS <T>* temp1 = Head;
    struct nodeS <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    Count--;      
}


///////// Doubly Linear Linked List ////////

template<class T>
class DoublyLL
{
    public:
        int Count;
        struct nodeD <T>* Head;

    DoublyLL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();
};

template<class T>
DoublyLL <T>:: DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL <T> :: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head -> prev = newn;
        Head = newn;
        Head->prev = NULL;
    }
    Count++;
}

template<class T>
void DoublyLL <T>:: InsertLast(T no)
{  
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head; 

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyLL <T> :: Display()
{
    struct nodeD <T>* temp = Head;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
void DoublyLL <T>:: DeleteFirst()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        delete temp;
    }
    Count--;   
}

template<class T>
void DoublyLL <T>:: DeleteLast()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;       
}

template<class T>
void DoublyLL <T>:: InsertAtPos(T no, int Pos)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyLL <T>:: DeleteAtPos(int Pos)
{

    struct nodeD <T>* temp1 = Head;
    struct nodeD <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    Count--;     
}

///////// Doubly Circukar Linked List ////////

template<class T>
class DoublyCL
{
    public:
        struct nodeD <T>* Head;
        struct nodeD <T>* Tail;
        int Count;

    DoublyCL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();   
};

template<class T>
DoublyCL <T> :: DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCL <T> :: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;    
    newn->prev = NULL ;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }   
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;   
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

template<class T>
void DoublyCL <T> :: InsertLast(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;    
    newn->prev = NULL ;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }   
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;   
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

template<class T>
void DoublyCL <T> :: DeleteFirst()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = temp->next;
        delete temp; 
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count--;
}

template<class T>
void DoublyCL <T> :: DeleteLast()
{
    struct nodeD <T>* temp = Tail;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = temp->prev;
        delete temp; 
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count--;
}

template<class T>
void DoublyCL <T> :: InsertAtPos(T no, int Pos)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyCL <T> :: DeleteAtPos(int Pos)
{
    struct nodeD <T>* temp1 = Head;
    struct nodeD <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    Count--;   
}

template<class T>
void DoublyCL <T> :: Display()
{
    struct nodeD <T>* temp = Head;

    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    } while (temp != Tail->next);
    cout<<"\n";    
}


int main()
{
    
    printf("\nJay Ganesh...\n");
    cout<<"\n";
    
    int iPos = 0,iChoice = 0;
    int iNo = 0;
    char ch = '\0';

    SinglyLL<int>iobj;
    SinglyLL<char>cobj;

    SinglyCL<int>Ciobj;
    SinglyCL<char>Ccobj;  

    DoublyLL <int> diobj;
    DoublyLL <char> dcobj;   

    DoublyCL <int> DCiobj;
    DoublyCL <char> DCcobj;       

    cout<<"-----------------------------------------------------------------\n";

    cout<<"\nWelcome to"<<" Data Structure"<<" Application Written by Suraj Sakhare\n";

        cout<<"\n-----------------------------------------------------------------\n";
        
        cout<<"1  : Insert Integer new node at First Postion : \n";
        cout<<"2  : Insert Character new node at First Postion : \n";

        cout<<"\n";
        cout<<"3  : Insert Integer new node at Last Postion : \n";
        cout<<"4  : Insert Character new node at Last Postion : \n";

        cout<<"\n";
        cout<<"5  : Insert Integer new node at Given Postion : \n";
        cout<<"6  : Insert Character new node at Given Postion : \n";

        cout<<"\n";
        cout<<"7  : Delete Integer node From First Postion : \n";
        cout<<"8  : Delete Character node From First Postion : \n";

        cout<<"\n";
        cout<<"9  : Delete Integer node From Last Postion : \n";
        cout<<"10 : Delete Character node From Last Postion : \n";

        cout<<"\n";
        cout<<"11 : Delete Integer node From Given Postion : \n";
        cout<<"12 : Delete Character node From Given Postion : \n";

        cout<<"\n";
        cout<<"13 : Display the int Contents from Linked List : \n";
        cout<<"14 : Display the char Contents from Linked List : \n";

        cout<<"\n";
        cout<<"15 : Exit\n";

        cout<<"-----------------------------------------------------------------\n";     

    while(1)
    {
        cout<<"Choose your Option : \n";
        cin>>iChoice;
        switch (iChoice)
        {
        case 1 : 
            cout<<"Enter the Integer data that you want to insert : \n";
            cin>>iNo;

            iobj.InsertFirst(iNo);

            Ciobj.InsertFirst(iNo);

            diobj.InsertFirst(iNo);

            DCiobj.InsertFirst(iNo);
            break;

        case 2 :
            cout<<"Enter the Character data that you want to insert : \n";
            cin>>ch;

            cobj.InsertFirst(ch);

            Ccobj.InsertFirst(ch);

            dcobj.InsertFirst(ch);

            DCcobj.InsertFirst(ch);
            break;

        case 3 :
            cout<<"Enter the Integer data that you want to insert : \n";
            cin>>iNo;

            iobj.InsertLast(iNo);

            Ciobj.InsertLast(iNo);

            diobj.InsertLast(iNo);

            DCiobj.InsertLast(iNo);
            break;

        case 4 :
            cout<<"Enter the Character data that you want to insert : \n";
            cin>>ch;

            cobj.InsertLast(ch);

            Ccobj.InsertLast(ch);

            dcobj.InsertLast(ch);

            DCcobj.InsertLast(ch);
            break;    

        case 5 :
            cout<<"Enter the Integer data that you want to insert : \n";
            cin>>iNo;

            cout<<"Enter the Position : \n";
            cin>>iPos;

            iobj.InsertAtPos(iNo,iPos);

            Ciobj.InsertAtPos(iNo,iPos);

            diobj.InsertAtPos(iNo,iPos);

            DCiobj.InsertAtPos(iNo,iPos);
            break;            

        case 6 :
            cout<<"Enter the Character data that you want to insert : \n";
            cin>>ch;

            cout<<"Enter the Position : \n";
            cin>>iPos;            

            cobj.InsertAtPos(ch,iPos);

            Ccobj.InsertAtPos(ch,iPos);

            dcobj.InsertAtPos(ch,iPos);

            DCcobj.InsertAtPos(ch,iPos);
            break;  


        case 7 :

            iobj.DeleteFirst();

            Ciobj.DeleteFirst();

            diobj.DeleteFirst();

            DCiobj.DeleteFirst();

            cout<<"First Node Delete Successfully..\n";

            break;            
        
        case 8 : 

            cobj.DeleteFirst();

            Ccobj.DeleteFirst();

            dcobj.DeleteFirst();

            DCcobj.DeleteFirst();

            cout<<"First Node Delete Successfully..\n";

            break;  

        case 9 :

            iobj.DeleteLast();

            Ciobj.DeleteLast();

            diobj.DeleteLast();

            DCiobj.DeleteLast();

            cout<<"Last Node Delete Successfully..\n";

            break;

        case 10 : 

            cobj.DeleteLast();

            Ccobj.DeleteLast();

            dcobj.DeleteLast();

            DCcobj.DeleteLast();
            cout<<"Last Node Delete Successfully..\n";

            break; 

        case 11 :

            cout<<"Enter the Position : \n";
            cin>>iPos;

            iobj.DeleteAtPos(iPos);

            Ciobj.DeleteAtPos(iPos);

            diobj.DeleteAtPos(iPos);

            DCiobj.DeleteAtPos(iPos);
            break;  

        case 12 :

            cout<<"Enter the Position : \n";
            cin>>iPos;            

            cobj.DeleteAtPos(iPos);

            Ccobj.DeleteAtPos(iPos);

            dcobj.DeleteAtPos(iPos);

            DCcobj.DeleteAtPos(iPos);
            break; 

        case 13 : 

        cout<<"\t\t\t----Nodes are---- \t\t\t\n";
        cout<<"-----------------------------------------------------------------\n";
           cout<<"\nUsing Singly Linear Linked List :\n";
           iobj.Display();
           cout<<"Number of Nodes : "<<iobj.Count<<"\n";
           //cobj.Display();

           cout<<"\nUsing Singly Circular Linked List :\n";
           Ciobj.Display();
           cout<<"Number of Nodes : "<<Ciobj.Count<<"\n";
           //Ccobj.Display();

           cout<<"\nUsing Doubly Linear Linked List :\n";
           diobj.Display();
           cout<<"Number of Nodes : "<<diobj.Count<<"\n";
           //dcobj.Display();

           cout<<"\nUsing Doubly Circular Linked List :\n";
           DCiobj.Display();
           cout<<"Number of Nodes : "<<DCiobj.Count<<"\n";
           //DCcobj.Display();  

        cout<<"\n-----------------------------------------------------------------\n";           
           break;  
        
        case 14 :

        cout<<"\t\t\t----Nodes are---- \t\t\t\n";
        cout<<"-----------------------------------------------------------------\n";
           cout<<"\nUsing Singly Linear Linked List :\n";
           //iobj.Display();
           cobj.Display();
           cout<<"Number of Nodes : "<<cobj.Count<<"\n";

           cout<<"\nUsing Singly Circular Linked List :\n";
           //Ciobj.Display();
           Ccobj.Display();
           cout<<"Number of Nodes : "<<Ccobj.Count<<"\n";

           cout<<"\nUsing Doubly Linear Linked List :\n";
           //diobj.Display();
           dcobj.Display();
           cout<<"\nNumber of Nodes : "<<dcobj.Count<<"\n";

           cout<<"\nUsing Doubly Circular Linked List :\n";
           //DCiobj.Display();
           DCcobj.Display(); 
           cout<<"Number of Nodes : "<<DCcobj.Count<<"\n";
        cout<<"\n-----------------------------------------------------------------\n";
           break;  
        case 15 :

           cout<<"\nThank You !!! For using Application... \n";
           return 0;          

        default:
            
            cout<<"Invalid Option!!!\n";
            break;
        }     
    }



/*
///////// Singly Linear //////////

////// InsertFirst and InsertLast///////////

    printf("\n--------------Singly Linear Linked List-------------------\n");
    SinglyLL<int>iobj;
    cout<<"Using InsertFirst : \n";
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    SinglyLL<char>cobj;
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');

    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";

    cout<<"Using InsertLast : \n";
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    cobj.InsertLast('d');
    cobj.InsertLast('e');
    cobj.InsertLast('f');


    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";
    

///// DeleteFirst and DeleteLast ////////////
    cout<<"Using DeleteFirst : \n";
    iobj.DeleteFirst();

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    cobj.DeleteFirst();

    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";

    cout<<"Using Deletelast : \n";
    iobj.DeleteLast();

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    cobj.DeleteLast();

    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";


///// InsertAtPosition and DeleteAtPostion ///////

    cout<<"Using InsertAtPos : \n";
    iobj.InsertAtPos(105,3);

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    cobj.InsertAtPos('x',3);

    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";

    cout<<"Using DeleteAtPos : \n";
    iobj.DeleteAtPos(3);

    iobj.Display();
    cout<<"Number of Nodes are : "<<iobj.Count<<"\n";
    cout<<"\n";

    cobj.DeleteAtPos(3);

    cobj.Display();
    cout<<"Number of Nodes are : "<<cobj.Count<<"\n";
    cout<<"\n";


/////// Singly Circular ////////

////// InsertFirst and InsertLast //////// 

    printf("\n--------------Singly Circular Linked List-------------------\n"); 
    SinglyCL<int>Ciobj;
    SinglyCL<char>Ccobj;

    cout<<"Using InsertFirst : \n";
    Ciobj.InsertFirst(51);
    Ciobj.InsertFirst(21);
    Ciobj.InsertFirst(11);

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";

    Ccobj.InsertFirst('c');
    Ccobj.InsertFirst('b');
    Ccobj.InsertFirst('a');

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";    

    cout<<"Using InsertLast : \n";
    Ciobj.InsertLast(101);
    Ciobj.InsertLast(111);
    Ciobj.InsertLast(121);

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";


    cout<<"Using InsertLast : \n";
    Ccobj.InsertLast('d');
    Ccobj.InsertLast('e');
    Ccobj.InsertLast('f');

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";
  
/////// DeleteFirst and DeleteLast ////////////  
    cout<<"Using DeleteFirst : \n";
    Ciobj.DeleteFirst();

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";

    Ccobj.DeleteFirst();

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";

    cout<<"Using DeleteLast : \n";

    Ciobj.DeleteLast();

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";

    Ccobj.DeleteLast();

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";


/////// InsertAtPos and DeleteAtPos //////////////

    cout<<"Using InsertAtPos : \n";  

    Ciobj.InsertAtPos(105,3);

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";

    Ccobj.InsertAtPos('x',3);

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";      

    cout<<"Using DeleteAtPos : \n";
    Ccobj.DeleteAtPos(3);

    Ccobj.Display();
    cout<<"Number of Nodes are : "<<Ccobj.Count<<"\n";
    cout<<"\n";    

    Ciobj.DeleteAtPos(3);

    Ciobj.Display();
    cout<<"Number of Nodes are : "<<Ciobj.Count<<"\n";
    cout<<"\n";


//////////////////// Doubly Linear ///////////////////////////

    printf("\n--------------Doubly Linear Linked List-------------------\n"); 
    
    DoublyLL <int> diobj;
    DoublyLL <char> dcobj;

////// InsertFirst and InsertLast //////// 

    cout<<"Using InsertFirst : \n";
    diobj.InsertFirst(51);
    diobj.InsertFirst(21);
    diobj.InsertFirst(11);

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n";    

    dcobj.InsertFirst('c');
    dcobj.InsertFirst('b');
    dcobj.InsertFirst('a');

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n"; 



    cout<<"Using InsertLast : \n";
    diobj.InsertLast(101);
    diobj.InsertLast(111);
    diobj.InsertLast(121);

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n";    

    dcobj.InsertLast('d');
    dcobj.InsertLast('e');
    dcobj.InsertLast('f');

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n"; 

////// DeleteFirst and DeleteLast //////// 

    cout<<"Using DeleteFirst : \n";

    diobj.DeleteFirst();

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n"; 

    dcobj.DeleteFirst();

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n";  


    cout<<"Using DeleteLast : \n";

    diobj.DeleteLast();

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n"; 

    dcobj.DeleteLast();

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n";     


 ////// InsertAtPos and DeleteAtPos ////////   

    cout<<"Using InsertAtPos : \n"; 

    diobj.InsertAtPos(105,3);

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n"; 

    dcobj.InsertAtPos('x',3);

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n"; 

    cout<<"Using DeleteAtPos : \n"; 

    diobj.DeleteAtPos(3);

    diobj.Display();
    cout<<"Number of Nodes are : "<<diobj.Count<<"\n";
    cout<<"\n"; 

    dcobj.DeleteAtPos(3);

    dcobj.Display();
    cout<<"Number of Nodes are : "<<dcobj.Count<<"\n";
    cout<<"\n"; 

//////////////////// Doubly Circular ///////////////////////////    

    printf("\n--------------Doubly Circular Linked List-------------------\n"); 
    
    DoublyCL <int> DCiobj;
    DoublyCL <char> DCcobj;

////// InsertFirst and InsertLast //////// 

    cout<<"Using InsertFirst : \n";
    DCiobj.InsertFirst(51);
    DCiobj.InsertFirst(21);
    DCiobj.InsertFirst(11);

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n";    

    DCcobj.InsertFirst('c');
    DCcobj.InsertFirst('b');
    DCcobj.InsertFirst('a');

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n"; 

    cout<<"Using InsertLast : \n";
    DCiobj.InsertLast(101);
    DCiobj.InsertLast(111);
    DCiobj.InsertLast(121);

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n";    

    DCcobj.InsertLast('d');
    DCcobj.InsertLast('e');
    DCcobj.InsertLast('f');

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n"; 

////// DeleteFirst and DeleteLast ////////

    cout<<"Using DeleteFirst : \n";

    DCiobj.DeleteFirst();

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n"; 

    DCcobj.DeleteFirst();

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n"; 



    cout<<"Using DeleteLast : \n";

    DCiobj.DeleteLast();

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n"; 

    DCcobj.DeleteLast();

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n"; 


 ////// InsertAtPos and DeleteAtPos ////////   

    cout<<"Using InsertAtPos : \n"; 

    DCiobj.InsertAtPos(105,3);

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n"; 

    DCcobj.InsertAtPos('x',3);

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n";

    cout<<"Using DeleteAtPos : \n"; 

    DCiobj.DeleteAtPos(3);

    DCiobj.Display();
    cout<<"Number of Nodes are : "<<DCiobj.Count<<"\n";
    cout<<"\n"; 

    DCcobj.DeleteAtPos(3);

    DCcobj.Display();
    cout<<"Number of Nodes are : "<<DCcobj.Count<<"\n";
    cout<<"\n";

*/
    return 0;
}