#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "db.h"

#define loop for(;;)

char* commands = "1) create\n2) print\n3) add\n4) edit\n5) find by phone\n6) find by name\n7) delete\n8) sort\n9) exit\n";
bool db_is_up;


int main() {
    int user_input;
    char buffer[112];

    printf("Start of application\n");
    FILE* Data = fopen("data", "r+");

    if (Data != NULL) {
        db_is_up = 1;
        printf("The commands are:\n%s", commands);
        printf("Please type the corresponding digit\n");
    }
    else {
        printf("\033[31mError:\033[0mThe file is missing\n");
        db_is_up = 0;
    }

    //while (db_is_up) {

    get_user_command(user_input);
    handle_user_input(user_input);

    //}
    
    fclose(Data);
    return 0;
}

void get_user_command(int command_code) {
    int read = scanf("%d", &command_code);

    if (read == 0) {
        printf("\033[31mError:\033[0m failed to read user input\n");
        abort();
    }
}

void handle_user_input(int command_code) {
    int cmd_result;
    switch (command_code) {
    case 1:
        cmd_result = create_new_database();
        break;
    case 2:
        cmd_result = print_user_info();
        break;
    case 3:
        cmd_result = add_user_info();
        break;
    case 4:
        cmd_result = edit_user_info();
        break;
    case 5:
        cmd_result = find_user_by_phone();
        break;
    case 6:
        cmd_result = find_user_by_name();
        break;
    case 7:
        cmd_result = delete_user_info();
        break;
    case 8:
        cmd_result = sort_database_contants();
        break;
    case 9:
        exit_app();
        break;

    }
}
