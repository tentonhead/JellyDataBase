typedef struct UserData {
    char id[10];
    char phone_number[12];
    char* name;
} UserData;

void get_user_command(int command_code);
void handle_user_input(int command_code);
int create_new_database();
int print_user_info();
int add_user_info();
int edit_user_info();
int find_user_by_phone();
int find_user_by_name();
int delete_user_info();
int sort_database_contants();
void exit_app();
/*
typedef struct Commands {
    char* make;
    char* print;
    char* append;
    char* edit;
    char* find_by_phone;
    char* find_by_name;
    char* delete;
    char* sort;
    char* exit;
} Commands;
*/
