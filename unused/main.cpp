#include <iostream>
#include <string>

#include "Array.hpp"
#include "Queue.hpp"
#include "Map.hpp"
#include "Linked_list.hpp"
#include "Menu.hpp"

using namespace std;

int main(){
    int dsOption, option;

    printf("***| STUDENT DATABASE MANAGEMENT SYSTEM |***");
    printf("\n\nPlease Select/Enter the System Structure you Want:\n");
    printf("\n1. Array\n2. Queue\n3. Map\n4. Linked List\n");

    cin << dsOption;
    
    switch(dsOption){
        case 1:
            menu();
            printf("*** Enter your option ***");
            cin << option;
            menuArray(option);
            break;
        case 2:
            menu();
            printf("*** Enter your option ***");
            cin << option;
            menuQueue(option);
            break;
        case 3:
            menu();
            printf("*** Enter your option ***");
            cin << option;
            menuMap(option);
            break;
        case 4:
            menu();
            printf("*** Enter your option ***");
            cin << option;
            menuLinkedList(option);
            break;
    }
    
}