/***********************************************
 * game.c -- giá trị game của trò chơi giải đố
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: định nghĩa giá trị trò chơi, 
 *          tạo ra 2 hàm cơ bản cho nó
 * 
 * STATUS: 
 *      - [x]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 
 *      - PROGRAM: 7
 *      - FUNCTION: 
 * 
**********************************************/
#include "question_list.c"

enum game_status {RUNNING, OVER}; 

typedef enum game_status game_status; 

struct game {
    question_list question_bank; /* question bank */
    game_status status; /* status of game */
    int gamer_reward; /* reward of gamer playtime in minutes */
}; 

typedef struct game game; 

/************************************
 * 
 * 
 * 
*/
void game_init(game *game_ptr) {
    const char FILE_QUESTION_BANK[] = "D:/program/Quiz-game/code/data/question_file.csv";

    (*game_ptr).gamer_reward = 0;
    (*game_ptr).question_bank = question_list_template_by_file(FILE_QUESTION_BANK);
    (*game_ptr).status = RUNNING; 
}

/************************************
 * 
 * 
 * 
*/
game_status game_run(game *game_ptr) {
    game_status result; 

    static int i = 1; /* index of question list */

    clrscr(); 
    printf("%s", question_to_string((*game_ptr).question_bank.questions[i -1]));

    int choice = getch();
    choice = TO_LOWER(choice);

    if ((*game_ptr).question_bank.questions[i -1].order_of_right_answer == 1) {
        if (choice == 'a') {
            printf("Correct");
            wait_1ms(5000);
            ++((*game_ptr).gamer_reward); 
            ++i;  
        } else if (choice == 'b') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER; 
        } else if (choice == 'c') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER; 
        } else if (choice == 'd') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER; 
        } 
    } else if ((*game_ptr).question_bank.questions[i -1].order_of_right_answer == 2) {
        if (choice == 'b') {
            printf("Correct");
            wait_1ms(5000);
            ++((*game_ptr).gamer_reward);
            ++i;  
        } else if (choice == 'a') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'c') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'd') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } 
    } else if ((*game_ptr).question_bank.questions[i -1].order_of_right_answer == 3) {
        if (choice == 'c') {
            printf("Correct");
            wait_1ms(5000);
            ++((*game_ptr).gamer_reward);
            ++i;  
        } else if (choice == 'b') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'a') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'd') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } 
    } else if ((*game_ptr).question_bank.questions[i -1].order_of_right_answer == 4) {
        if (choice == 'd') {
            printf("Correct");
            wait_1ms(5000);
            ++((*game_ptr).gamer_reward);
            ++i;  
        } else if (choice == 'b') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'c') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } else if (choice == 'a') {
            printf("Incorrect");
            wait_1ms(5000);
            (*game_ptr).status = OVER;
        } 
    }

    result = (*game_ptr).status; 

    return result; 
}


/************************************
 * 
 * 
 * 
*/
void game_display_instruction(void) {
    type_writing("Chon dap an cho cau tra loi hien ra tren man hinh", 1, 3);
    type_writing("\nSau do se hien thi ket qua va neu dung thi se qua cau hoi tiep theo", 1, 3);
}

/************************************
 * 
 * 
 * 
*/
void game_display_reward(game *game_ptr) {
    clrscr(); 
    printf("So thoi gian choi gianh them duoc la %d phut\n", (*game_ptr).gamer_reward * 3);
    printf("Press any key to exit game ... "); 
    int ch = getch(); 
}

#ifdef DEBUG_P7

game quiz_game; 

int main(void) {
    game_init(&quiz_game);

    game_display_instruction(); 

    while (1) {
        game_status status = game_run(&quiz_game); 

        if (status = OVER) {
            break; 
        }
    }

    game_display_reward(&quiz_game); 
}

#endif