#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    int op=0;

    while(1){
        
        printf("1.add begin    2.add_databased     3.add_middle     4.add_end\n");
        printf("5.delete_begin 6.delete_databased  7.delete_middle  8.delete_end\n");
        printf("9.print_all    10.print_databased  11.print_reverse\n");
        printf("12.sort        13.reverse_link\n");

        scanf("%d",&op);

        switch(op){
            case 1: add_begin();
                    break;
            case 2:add_databased();
                    break;
            case 3:add_middle();
                    break;
            case 4:add_end();
                    break;
            case 5:delete_begin();
                    break;
            case 6:delete_databased();
                    break;
            case 7:delete_middle();
                    break;
            case 8:delete_end();
                    break;
            case 9:print_all();
                    break;
            case 10:print_databased();
                    break;
            case 11:print_reverse(head);
                    break;
            case 12:sort();
                    break;
            case 13:reverse_link();
                    break;
            case 14:
                    exit(0);
            default:
                    printf("invalid input\n");     
        }
    }

}