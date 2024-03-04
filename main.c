#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db.h"


int match_command(char* argv[]);
int launch_command(int command_code, char* argv[]);
bool is_enough_arguments(int command_code, int argcount);

int create_new_base(char* base_name);
int append_to_base(char* what_base, char* what);
int find_mail_in_base(char* what_base, char* what_mail);
int find_group_in_base(char* what_base, char* what_group);
void print_base_struct(char* what_base, char* what);
int sort_base(char* what_base, char* how);
int edit(char* what_base, char* what, char* to_what);
int delete_from_base(char* what_base, char* what);


int main(int argc, char* argv[]) {
    int cmd;

    if (argc > 1)
        cmd = match_command(argv);
    else {
        fprintf(stderr, "jdb: "RED"Error: "NC "No args supplied\n");
        exit(1);
    }

    if (!is_enough_arguments(cmd, argc)) {
        fprintf(stderr, "jdb: "RED"Error: "NC"Not enough args aupplied\n");
        exit(2);
    }

    launch_command(cmd, argv);

    
    return 0;
}


int match_command(char* arg[]) {

    if (strcmp(arg[1], "create") == 0)
        return 1;

    if (strcmp(arg[1], "append") == 0)
        return 2;

    if (strcmp(arg[1], "findmail") == 0)
        return 3;

    if (strcmp(arg[1], "findgroup") == 0)
        return 4;

    if (strcmp(arg[1], "print") == 0)
        return 5;

    if (strcmp(arg[1], "edit") == 0)
        return 6;

    if (strcmp(arg[1], "sort") == 0)
        return 7;

    if (strcmp(arg[1], "delete") == 0)
        return 8;

    else {
        fprintf(stderr, "jdb: "RED"Error: "NC"No command matched\n");
        return -1;
    }
}


int launch_command(int command_code, char* argv[]) {
    int status;

    switch (command_code) {
        case 1:
            status = create_new_base(argv[2]);
            break;
        case 2:
            status = append_to_base(argv[2], argv[3]);
            break;
        case 3:
            status = find_mail_in_base(argv[2], argv[3]);
            break;
        case 4:
            status = find_group_in_base(argv[2], argv[3]);
            break;
        case 5:
            print_base_struct(argv[2], argv[3]);
            break;
        case 6:
            status = sort_base(argv[2], argv[3]);
            break;
        case 7:
            status = edit(argv[2], argv[3], argv[4]);
            break;
        case 8:
            status = delete_from_base(argv[2], argv[3]);
            break;
    }

    return status;

}


bool is_enough_arguments(int command_code, int argcount) {
    switch (command_code) {
        case 1: 
            if (argcount == 3)
                return 1;
        case 2: 
        case 3:
        case 4:
        case 5: 
        case 6: 
        case 8:
            if (argcount == 3)
                return 1;
        case 7:
            if(argcount == 5)
                return 1;
        default:
            return 0;
    }
}


int create_new_base(char* base_name) {
    int status;
    FILE* NewBase = fopen(base_name, "w");
    if (NewBase != NULL) {
        status = 0;
        fclose(NewBase);
    }
    else {
        status = 3;
        fprintf(stderr, "jdb: "RED"Error: "NC"Couldn't create file\n");
    }
    return status;

}


int append_to_base(char* what_base, char* what) {
    int status = 0;
    FILE* Base = fopen(what_base, "wr");
    if (Base != NULL) {


    }
    else {
        fprintf(stderr, "jdb: "RED"Error: "NC"Couldn't open %s\n",
                what_base);
    }

    return status;
}


int find_mail_in_base(char* what_base, char* what_mail) {
    int status = 0;
    return status;
}


int find_group_in_base(char* what_base, char* what_group) {
    int status = 0;
    return status;
}


void print_base_struct(char* what_base, char* what) {
    printf("Let's pretend that's what you wanted\n");
}


int sort_base(char* what_base, char* how) {
    int status = 0;
    return status;
}


int edit(char* what_base, char* what, char* to_what) {
    int status = 0;
    return status;
}


int delete_from_base(char* what_base, char* what) {
    printf("%s", what);
    char ans;
    int status = 0;
    /*
    fprintf(stdout, "Are you sure you want to delete %s?\n[y/n]: ",
            what);
    fscanf(stdin, "%c", &ans);
    if (ans == 'y') {
        printf("OK\n");
        // char* syscall = "rm " what;
        // system("rm ");

    }
    else {
        printf("that was close\n");

    }
    */
    return status;
}


