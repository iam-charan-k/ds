#include<stdio.h>
#include<string.h>
#include<stdlib.h>s

typedef struct sll{
    int d;
    struct sll *next;
}SLL;

SLL *head=0;

void add_begin(){

    SLL *new = malloc(sizeof(SLL));
    if(new==0){
        perror("malloc");
        return;
    }
    printf("enter data:");
    scanf("%d",&new->d);
    new->next=0;

    new->next=head;
    head=new;
    printf("node added at begin");
}

void add_databased(){
    SLL *new = malloc(sizeof(SLL));
    if(new==0){
        perror("malloc");
        return;
    }
    printf("enter data:");
    scanf("%d",&new->d);
    new->next=0;

    if(head==NULL || new->d<head->d){
        new->next=head;
        head=new;
    }
    else{
        SLL *p=head;

        while(p->next && p->next->d<new->d){
            p=p->next;
        }
        new->next=p->next;
        p->next=new;
    }
}

void add_middle(){

    SLL *new = malloc(sizeof(SLL));
    if(new==0){
        perror("malloc");
        return;
    }
    printf("enter data:");
    scanf("%d",&new->d);
    new->next=0;

    if(head==NULL){
        new->next=head;
        head=new;
    }
    else{
        SLL *slow=head;
        SLL *fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        new->next=slow->next;
        slow->next=new;
    }
    

}

void add_position(){
    SLL *new = malloc(sizeof(SLL));
    if(new==0){
        perror("malloc");
        return;
    }
    printf("enter data:");
    scanf("%d",&new->d);
    new->next=0;

    int i=0;
    int pos=0;
    printf("enter pos:");
    scanf("%d",&pos);

    if(head==NULL || pos==1){
        new->next=head;
        head=new;
    }
    else{
        SLL *p=head;
        for(i=1;i<(pos-1) && p!=NULL ;i++){
            p=p->next;
        }
        if(p){
            new->next=p->next;
            p->next=new;
        }
        else{
            printf("invalid\n"):
        }
    }
}

void add_end(){
    
    SLL *new = malloc(sizeof(SLL));
    if(new==0){
        perror("malloc");
        return;
    }
    printf("enter data:");
    scanf("%d",&new->d);
    new->next=0;

    if(head==0){
        head=new;
    }
    else{
        SLL *p=head;
        while(p->next != NULL){
            p=p->next;
        }
        p->next=new;
    }
    printf("node added at end");
}

void delete_begin(){
    if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
    }
    else{
        SLL *del=head;
        head=head->next;
        free(del);
        del=0;

        printf("deleted first node");
    }
}

void delete_middle(){
   if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
   }
 
        SLL *prev=NULL;
        SLL *slow=head;
        SLL * fast =head;

        while(fast->next && fast->next->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
       if(prev==NULL){
           head=head->next;
       }
       else{
        prev->next=slow->next;
       }
        free(slow);
    
}

void delete_position(){
     if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
   }
   else{
       SLL *prev=NULL;
       SLL *p=head;
       int i=1
       while((i<pos) && (p!=NULL)){
           prev=p; 
           p=p->next;
           i++;
       }
       if(p!=NULL){
           if(pos==1){
                head=head->next;
           }
           else{
                prev->next=p->next;
           }
           free(p);
       }
       else{
           printf("invalid position\n");
       }
   }
}

void delete_end(){
    if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
    }
    else{
        
        SLL *del=head,*prev=0;

        while(del->next!=NULL){
            prev=del;
            del=del->next;
        }
        free(del);
        if(prev)
            prev->next=NULL;
        else{ //only 1 node and deleted and update head node
            head=NULL;
        }

        printf("deleted first node");
    }
}
void delete_middle(){
    if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
    }
    else{
        SLL *slow=head,*fast=head,*prev=head;
        if(head->next==NULL){
            free(head);
            head=NULL;
        }
        else{
            // in even mode 
            //delete 1st middle
            //delete 2nd middle[fast && fast->next]
            while(fast->next && fast->next->next){
                    prev=slow;
                    slow=slow->next;
                    fast=fast->next->next;
            }
            prev->next=slow->next;
            free(slow);
        
        }
    }
}

void delete_databased(){
    if(head==NULL){
        printf("no nodes exist to delete returned\n");
        return;
    }
    else{
        int d;
        printf("enter data:");
        scanf("%d",&d);
        SLL *p=head,*prev=0;

        while(p){
            if(p->d!=d){
                prev=p;
                p=p->next;
            }
            else{
                break;
            }
        }
        if(p && p->d==d){
            if(prev==NULL){
                //1st node update head;
                head=head->next;
            }
            else{
                prev->next=p->next;
            }
            free(p)
        }
        else{
            printf("node not found\n");
        }
    }
}

void print_all(){

    if(head==NULL){
        printf("no nodes to print\n");
        return;
    }
    else{
        SLL *p=head;
        while(p){
            printf("%d ",p->d);
            p=p->next;
        }
        printf("\n");
    }
}

void print_databased(){
    if(head==NULL){
        printf("no nodes to print\n");
        return;
    }
    else{
        int val=0;
        SLL *p=head;

        printf("enter data to print:");
        scanf("%d",&val);

        while(p){
            if(val==p->d){
                printf("data found:%d\n",p->d);
                return;
            }
            else{
                p=p->next;
            }
        }
        printf("data not found\n");
}

void print_reverse(SLL *head){
     if(head==NULL){
         printf("no nodes\n");
        return;
     }
     print_reverse(head->next);
     printf("%d\n",head->d);
}

void sort(){
    if(head==NULL){
        printf("no nodes to print\n");
        return;
    }
    SLL *i=head,*j=0;
    //sort assending order
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->d>j->d){
                t=i->d;
                i->d=j->d;
                j->d=t;
            }
        }
    }
    printf("data sorted\n");
}

void print_middle(){
    if(head==NULL){
        printf("no nodes\n");
        return;
    }
    else{
        SLL *slow=head,*fast=head;
        
        // VERSION 1 → fast && fast->next
        // → for EVEN nodes → slow stops at SECOND middle

        // VERSION 2 → fast->next && fast->next->next
        // → for EVEN nodes → slow stops at FIRST middle
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        pritnf("%d \n",slow->d);
}

void print_position(){
    if(head==NULL){
        printf("no nodes\n");
        return;
    }
    SLL *p=head;
    int i=1;
    while(i<pos && p!=NULL){
        p=p->next;
    }
    if(p){
        printf("%d \n",p->d)
    }
    else{
        printf("invalid data\n");
    }
}

void reverse_link(){
    if(head==NULL){
        printf("no nodes to print\n");
        return;
    }
    
    SLL *prev=0;
    SLL *next=0;
    SLL *cur=head;

    while(cur){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        
    }
    head=prev;

}
