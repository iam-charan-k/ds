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
     if(head!=NULL){
        print_reverse(head->next);
     }
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
