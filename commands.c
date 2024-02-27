#include <stdio.h>
#include <stdlib.h>

int create_new_database() {
    printf("What is the name of new database?\n");
    //extern char buffer[];
    scanf("%s", buffer);
    FILE* NewDB = fopen(buffer, "w+");
    return 1;
}
int print_user_info() {
    return 1;
}
int add_user_info() {
    return 1;
}
int edit_user_info() {
    return 1;
}
int find_user_by_phone() {
    return 1;
}
int find_user_by_name() {
    return 1;
}
int delete_user_info() {
    return 1;
}
int sort_database_contants() {
    return 1;
}

void exit_app() {
    printf("Closing application\n");
    exit(0);
}
