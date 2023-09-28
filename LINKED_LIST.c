/*
    0)create                                
    1)display                               
    2)add_at_first                         
    3)add_at_last                           
    4-Delete first node
    5-Delete last node
    6-Insert node
    7-Delete node
    8-cnt odd&even
    9-cnt pos-neg
    10-search element
    11-cnt length
    12-append    
    13-display reverse
    14-reversing a linked list 
    15-swap
    16-getfirst
    17-getlast
    -free_all  
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
//#include"myll.h"
#define NEWNODE (struct node*)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node* next;
};

struct node* create_manually(int n)
{
    struct node *f=NULL,*t=NULL,*l=NULL;

    f = NEWNODE;
    if (f==NULL)
    {
        printf("unable to allocate memory !\n");
        exit(0);
    }
    
    printf("Enter the data : ");
    scanf("%d",&f->data);
    f->next = NULL;
    l = f;

    for (int i = 2; i <= n; i++)
    {
        t = NEWNODE;
        if (t == NULL)
        {
            printf("Unable to allocate memory !\n");
            free(f);
            return f;
        }
        
        printf("Enter the data : ");
        scanf("%d",&t->data);
        t->next = NULL;

        l->next = t ;
        l = l->next ;
    }
    
    return f;
}

struct node* create_auto(int n)
{
    struct node *f=NULL,*t=NULL,*l=NULL;
    int temp;

    f = NEWNODE;
    if (f==NULL)
    {
        printf("unable to allocate memory !\n");
        exit(0);
    }
    
    srand(time(NULL));

    while (1)
    {
        temp = rand() % 100;
        if (temp > 0)
            break;
    }
    
    f->data = temp;
    f->next = NULL;
    l = f;

    for (int i = 2; i <= n; i++)
    {
        t = NEWNODE;
        if (t == NULL)
        {
            printf("Unable to allocate memory !\n");
            free(f);
            return f;
        }
    
        while (1)
        {
            temp = rand() % 100;
            if (temp > 0)
                break;
        }
        t->data = temp;
        t->next = NULL;

        l->next = t ;
        l = l->next ;
    }
    
    return f;
}

void display(struct node*f)
{
    struct node *t;
    printf("Linked_List : ");

    for ( t = f ; t != NULL; t = t->next)
    {
        printf("%d -> ",t->data);
    }
     printf(" NULL\n");
}

struct node* add_first(struct node* f)
{
    struct node *t;

    t = NEWNODE;
    if (t == NULL)
    {
        printf("Unable to allocate memory !");
        return f;
    }
    
    printf("Enter the number : ");
    scanf("%d",&t->data);

    t->next = f;
    f = t;

    return f; 
}

struct node* del_first(struct node* f)
{
    struct node *t;

    t = f;
    f = f->next;
    free(t);
    return f;
}

struct node* add_last(struct node* f)
{
    struct node *t,*s;

    t = NEWNODE;
    if (t == NULL)
    {
        printf("Unable to allocate memory !\n");
        return f;
    }
    printf("Enter the data : ");
    scanf("%d",&t->data);
    t->next = NULL;

    for ( s = f; s->next != NULL; s = s->next);
    
    s->next = t;
    return f;
    
}

struct node* free_all(struct node *f)
{
    struct node *t;

    while (f!=NULL)
    {
        t=f;
        f=f->next;
        free(t);
    }
    return f;
}

struct node* del_last(struct node* f)
{
    struct node *t,*s;

    for ( t = f; t->next != NULL ; t = t->next);
    {
        s =  t;
    }

    free(t);
    s->next = NULL;

    return f;
    
}

struct node* insert(struct node* f , int pos)
{
    struct node *t,*s;

    t = NEWNODE;
    if (t == NULL)
    {
        printf("Unable to allocate memory !\n");
        return f;
    }
    printf("Enter the data : ");
    scanf("%d",&t->data);
    t->next = NULL;
    if (pos == 1)
    {
        t->next = f;
        f = t;
        printf("\nNode is successfully added !\n");
        return f;
    }
    else
    {
        s=f;
        for (int i = 1; i <= (pos-2) && s!=NULL ; i++)
                s=s->next;  

        if (s==NULL)
        {
            printf("Invalid position for INSERTION\n");
            free(t);
            return f;
        }
        else
        {
            t->next = s->next ;
            s->next = t;
            printf("\nNode is added successfully !\n");
            return f;
        }
    } // If of position
}// insert's bracket

struct node* delete(struct node* f,int pos)
{
    struct node *t=NULL,*s=NULL;

    if (pos == 1)
    {
        t = f;
        f = f->next;
        free(t);
        printf("\nNode deleted successfully !\n");
        return f;
    }
    else
    {
        s = f ;

        for (int i = 1; i <= (pos-2) && s != NULL; i++)
            s = s->next;

        if ((s == NULL) || (s->next == NULL) )
        {
            printf("\nInvalid position for deletion\n");
            return f;
        }
        else
        {
            t = s->next;
            s->next = t->next;
            free(t);
            printf("\nNode is deleted successfully !\n");
            return f;
        }  
    }
}

void odd_even(struct node* f)
{
    struct node *t=NULL;
    unsigned int even_cnt = 0 , odd_cnt = 0; 

    for ( t = f; t!=NULL;t = t->next)
    {
        if ((t->data % 2 ) == 0 )
            even_cnt++;
        else
           odd_cnt++;
    }

    printf("\nEven data values : ",even_cnt);
    printf("\nOdd data values  : ",odd_cnt);
}

void positive_negative(struct node*f)
{
    struct node *t=NULL;
    unsigned int positv_cnt = 0 , negatv_cnt = 0; 

    for ( t = f; t!=NULL;t = t->next)
    {
        if ((t->data % 2 ) == 0 )
            positv_cnt++;
        else
           negatv_cnt++;
    }

    printf("\nPositive data values : ",positv_cnt);
    printf("\nNegative data values : ",negatv_cnt);
}

int search(struct node* f,int key)
{
    unsigned int pos = 1;
    struct node * t = NULL;

    for ( t = f ; t != NULL ;t = t->next)
    {
        if (t->data == key)
            return pos;
        pos++;
    }
    return -1; 
}

struct node* append(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    {
        int n=0;
           printf("\nHow many nodes do you want to apppend : ");
           scanf("%d",&n);
           if (n<1)
           {
                printf("\nNumber is smaller than 1 ,Can't create nodes !\n");
                return f;
           }
           
           t = create_manually(n);
    }

    for ( s = f ;s->next != NULL;s = s->next);
    
    s->next = t;
    printf("\nNodes are added successfully !\n");

    return f;   
}

unsigned int llength(struct node* f)
{
    struct node *t = NULL;
    unsigned int cnt=1;

    for (t = f ; t->next != NULL ; t = t->next)
        cnt++;

    return cnt;   
}

void display_reverse(struct node* f)
{
    struct node *t=NULL;
    unsigned int cnt=0;
    cnt = llength(f); // counting length of lined list
    
    printf("\nNULL <- ");
    for (int i = cnt; i > 1 ; i--)
    {
        t = f;
        for (int j = 1; j < i; j++)
        {
            t = t->next;
        }

        printf("%d <- ",t->data); 
    }
    printf("%d",f->data);
    printf("\n");
}

struct node* reverse(struct node* f)
{
    struct node *p=NULL,*n=NULL,*s=NULL;
    s = f ; 
    while (s!=NULL)
    {
        n = s->next;
        s->next = p;
        p = s;
        s = n; 
    }
    f = p;

    printf("\nLinked list is reversed successfully !\n");
    return f;  
}

struct node* swap(struct node* f,unsigned int a_pos,unsigned int b_pos)
{
    struct node *t=NULL;
    struct node *a_pre = NULL, *b_pre = NULL ,*a=NULL , *b=NULL , *imp = NULL;

    if (a_pos == b_pos)
    {
        printf("\nCan not swap a single node !\n");
        return f;
    }

    if(a_pos>b_pos)
    {
        a_pos = a_pos + b_pos;
        b_pos = a_pos - b_pos;
        a_pos = a_pos - b_pos;
    }
    
    a=f;
    b=f;

    for (int i = 1; i <= (a_pos-1); i++)
    {
        a_pre = a;
        a = a->next;
    }
    for (int i = 1; i <= (b_pos-1); i++)
    {
        b_pre = b;
        b = b->next;
    }
    

    if ( (a == NULL) || (b == NULL))
    {
        printf("\nInvalid position !\n");
        return f;
    }
    
    if (a_pre== NULL)
    {
        a_pre = a;
        f = b;
    }
    if (b_pre== NULL)
    {
        b_pre = b;
        f = a;
    }
    if (a_pos - b_pos == 1 || b_pos - a_pos == 1)
    {
        a_pre->next = b;
        b_pre->next = a;

        imp = a->next;
        a->next = b->next;
        b->next = imp;
    }
    else
    {    imp = a->next;
        a_pre->next = b;
        b_pre->next = a;

        a->next = b->next;
        b->next = imp;
    }
    printf("\nNodes are swapped successfully !\n");
    return f;
    
}

int getfirst(struct node* f)
{
    struct node *t = f;
    return t->data;
}

int getlast(struct node* f)
{
    struct node *t=NULL;

    for (t = f;t->next!=NULL;t = t->next);
    
    return t->data;  
}

struct node* get(struct node* f,unsigned int pos) 
{
    struct node *t=NULL;
    int i;
    for (i=1,t=f; i <= (pos-1) && t != NULL ; i++,t=t->next);
    
    if ( t == NULL)
    {
        return NULL;
    }
    else
    {
        return t;
    }
}

unsigned int indexof(struct node* f,int data)
{
    struct node* t=NULL;
    unsigned int index=1;
    for (t=f; (t != NULL) &&(t->data != data) ; t = t->next )
            index++;
    
    if ( t == NULL)
    {
        return 0;
    }
    else
    {
       return index;
    }   
}

struct node* swap_pairwise(struct node* f)
{
    if (f == NULL || f->next == NULL)
    {
        printf("\nCan not swap pairwise !\n");
        return f;
    }
    
    struct node *imp=NULL,*a_pre = NULL,*a=NULL,*b=NULL,*b_pre = NULL;

    a=f;
    a_pre = a;
    b_pre = a;
    b = a->next;
    f = b;

    while ( b != NULL && b->next != NULL)
    {
        a_pre->next = b;
        b_pre->next = a;

        imp = a->next;
        a->next = b->next;
        b->next = imp;

        a_pre = a;
        a = a->next;
        b_pre = a;
        b = a->next;
    }
    printf("\nNode are swapped pairwise !\n");
    return f;
}

struct node* SWAP(struct node* f,unsigned int a_pos,unsigned int b_pos)
{
    struct node *t=NULL;
    struct node *a_pre = NULL, *b_pre = NULL ,*a=NULL , *b=NULL , *imp = NULL;

    if (a_pos == b_pos)
    {
        return f;
    }

    if(a_pos>b_pos)
    {
        a_pos = a_pos + b_pos;
        b_pos = a_pos - b_pos;
        a_pos = a_pos - b_pos;
    }
    
    a=f;
    b=f;

    for (int i = 1; i <= (a_pos-1); i++)
    {
        a_pre = a;
        a = a->next;
    }
    for (int i = 1; i <= (b_pos-1); i++)
    {
        b_pre = b;
        b = b->next;
    }
    

    if ( (a == NULL) || (b == NULL))
    {
        return f;
    }
    
    if (a_pre== NULL)
    {
        a_pre = a;
        f = b;
    }
    if (b_pre== NULL)
    {
        b_pre = b;
        f = a;
    }
    if (a_pos - b_pos == 1 || b_pos - a_pos == 1)
    {
        a_pre->next = b;
        b_pre->next = a;

        imp = a->next;
        a->next = b->next;
        b->next = imp;
    }
    else
    {    imp = a->next;
        a_pre->next = b;
        b_pre->next = a;

        a->next = b->next;
        b->next = imp;
    }
    return f;
    
}

struct node* shuffle(struct node *f)
{
    struct node *t=NULL,*s=NULL;
    unsigned int cnt=1;
    int temp;

    for ( t = f; t->next != NULL ; t = t->next)
    {
        cnt++;
    }
    
    srand(time(NULL));

    s=f;
    for (int i = 1; i <= cnt; i++)
    {
        while (1)
        {
            temp = rand() % cnt;
            if (temp >= 1)
                break;
        }
        s = SWAP(s,i,temp);
    }

    f = s;
    printf("\nLinked list is shuffled successfully !\n");

    return f;
}

struct node* sort_by_bubble_sort(struct node *f)
{
    struct node *t=NULL,*s=NULL;
    unsigned int cnt=1;
    register int i ,j;
    int k=1,p=2;

    for ( t = f; t->next != NULL ; t = t->next)
    {
        cnt++;
    }
    t = f;
    s = f;
    for ( i = cnt-1; i > 0 ; i--)
    {
        s = t;
        k = 1,p = 2;

        for ( j = 1; j <= i ; j++)
        {
            if ( s->data > s->next->data)
            {
                s = SWAP(t,k,p);
                t = s;
                for (int a = 1; a < j; a++)
                {
                    s = s->next;
                }
            }
            s = s->next;
            k++;
            p++;
        }
        
    }
    f = t;
    return f;
}

struct node* sort_by_selection_sort(struct node *f)
{
    struct node *t=NULL,*s=NULL,*l=NULL;
    unsigned int cnt=1;
    register int i ,j;
    int k=1,p=2;

    for ( t = f; t->next != NULL ; t = t->next)
    {
        cnt++;
    }
    
    s = l = t = f;

    k = 2;
    for ( i = 1; i < cnt ; i++)
    {
        s = l->next;
        p = k;
        for ( j = i+1; j <= cnt; j++)
        {
            if ( l->data > s->data)
            {
                s = SWAP(t,i,p);
                t = s;
                l = t;
                for (int a = 1; a < j; a++)
                {
                    s = s->next;
                }
                for (int a = 1; a < i; a++)
                {
                    l = l->next;
                }
                
            }
            s = s->next;
            p++;
        }
        k++;
        l = l->next;
    }
    f = t; 
    return f;
}

int main()
{
    struct node *head;
    unsigned int n=0;
    char ch;

    printf("\nHow many nodes do you want to create : ");
    scanf("%d",&n);
    if (n<1)
    {
        printf("Value given for creating nodes is less than 1 !\n");
        exit(0);
    }

    printf("\n*** Enter 1 if you are giving data ");
    printf("\n*** Enter 2 if you are not giving data  \n");
    printf("       Enter : ");
    getchar();
    scanf("%c",&ch);

    switch (ch)
    {
        case '1':
                head = create_manually(n);
                break;
        case '2':
                head = create_auto(n);
                break;
        default:
                printf("\nInvalid Input !\n");
                exit(0);
    }
    

    while (1)
    {
        short int choice=0; 
        unsigned int pos=0;
        sleep(1);
        printf("\n***_MENU_***\n");
        printf("1~>Display Linked List\n2~>Add node at first\n3~>Add node at last\n4~>Delete first node\n5~>Delete last node\n6~>Insert node\n7~>Delete node\n8~>Count odd & even Data\n9~>Count positive & negative Data\n10~>Search an element\n11~>Count length of linked list\n12~>Append linked list \n13~>Display reverse\n14~>Reversing a linked list\n");
        printf("15~>Swapping two nodes\n16~>Get data at first node\n17~>Get data at last node\n18~>Get data at any node\n19~>Get index of data\n20~>Swap Nodes Pairwise\n21~>Shuffle linked list\n22~>Sorting LINKED LIST by bubble sort\n23~>Sorting Linked list by Selection Sort ");
        printf("\n24~>Exit\n");
        printf("         ...NOTE :- PRESS 24 TO END THE PROGRAM \n");
        printf("\nChoose one of above : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                    display(head);
                    break;
            case 2:
                    head = add_first(head);
                    printf("\nNode is added successfully !\n");
                    break;
            case 3:
                    head = add_last(head);
                    printf("\nNode is added successfully !\n");
                    break;
            case 4:
                    head = del_first(head);
                    printf("\nNode is deleted successfully !\n");
                    break;
            case 5:
                    head = del_last(head);
                    printf("\nNode is deleted successfully !\n");
                    break;
            case 6:
                    printf("\nEnter the position to insert : ");
                    scanf("%d",&pos);
                    if (pos>1)
                    {
                        printf("Invalid position !\n");
                        break;
                    }
                    head = insert(head,pos);
                    break;
            case 7:
                    printf("\nEnter the position to delete : ");
                    scanf("%d",&pos);
                    if (pos<1)
                    {
                        printf("Invalid position !\n");
                        break;
                    }
                    head = delete(head,pos);
                    break;
            case 8:
                    odd_even(head);
                    break;
            case 9:
                    positive_negative(head);
                    break;
            case 10:
                    {
                        int key;
                        printf("\nEnter the element to search :");
                        scanf("%d",&key);
                        pos = search(head,key);
                        if (pos == -1)
                        {
                            printf("Element not found !\n");
                            break;
                        }
                        else
                        {
                            printf("%d is found at node No. %d \n",key,pos);
                            break;
                        }
                    }
            case 11:
                    {
                        int length = 0;
                        length = llength(head);
                        printf("\nThe length of the linked list is %d\n",length);
                    }
                    break;
            case 12:
                        head = append(head);
                        break;
            case 13:
                    display_reverse(head);
                    break;
            case 14:
                    head = reverse(head);
                    break;
            case 15:
                    {
                        unsigned int a_pos = 0, b_pos = 0;
                        printf("\nEnter the position of first node  : ");
                        scanf("%d",&a_pos);
                        printf("Enter the position of second node : ");
                        scanf("%d",&b_pos);
                    
                        if ( (a_pos < 1) || (b_pos < 1) )
                        {
                            printf("\nNumber is smaller than 1,Invalid Position !\n");
                            break;
                        }
                    
                        head = swap(head,a_pos,b_pos);
                    }
                        break;
            case 16:
                    printf("\nData at first node is %d\n",getfirst(head));
                    break;
            case 17:
                    printf("\nData at last node is %d \n",getlast(head));
                    break;
            case 18:
                    {
                        unsigned int pos;
                        struct node* temp;

                        printf("\nEnter the position of node :");
                        scanf("%d",&pos);
                        if (pos < 1)
                        {
                            printf("\nPositionis smaller tha one , Invalid position\n");
                            break;
                        }
                        temp = get(head,pos);
                        if (temp == NULL)
                        {
                            printf("\nInvalid position of node !\n");
                        }
                        else
                        {
                            printf("\nData at node No. %d is %d\n",pos,temp->data);
                        }
                        break;
                    }

            case 19:
                    {
                        unsigned int index = 0;
                        int data;
                        printf("\nEnter the data : ");
                        scanf("%d",&data);
                        index =  indexof(head,data);
                        if ( index == 0)
                        {
                            printf("\nData not found !\n");
                        }
                        else
                        {
                            printf("\nIndex of %d is %d \n",data,index);
                        }   
                        break;
                    }

            case 20:
                    head = swap_pairwise(head);
                    break;
            case 21:
                    head = shuffle(head);
                    break;
            case 22:
                    head = sort_by_bubble_sort(head);
                    printf("\nLinked list is sorted successfully !\n");
                    break;
            case 23:
                    head = sort_by_selection_sort(head);
                    break;
            case 24:
                    head = free_all(head);
                    printf("\n[ EXITED.. ]\n");
                    exit(0);        
        default:
            printf("Invalid option is selected !\n");
        }  // Switch
        getchar();
    } // While
    
    free_all(head);
    return 0;
} 
//🎶🎶(❁´◡`❁)