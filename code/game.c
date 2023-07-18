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
 * game_run -- Chạy game đồng thời 
 *      trả về trạng thái của game 
 * 
 * 
*/
game_status game_run(game *game_ptr) {
    game_status result; 

    static int i = 1; /* index of question list */

    /******
     * 1. in ra màn hình câu hỏi hiện tại 
    */
    printf("%s", question_to_string((*game_ptr).question_bank.questions[i -1]));

    /*******************
     * 2. chờ lấy giá trị 
     *      phím được 
     *      nhấn trên bàn 
     *      phím 
    */
    int choice = getch();
    choice = TO_LOWER(choice);

    /**************************
     * 3. xác định có 
     * 
    */
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


/***************************************
 * game_display_instruction -- hiển thị 
 *      màn hình hướng dẫn cho game 
 * 
 * 
*/
void game_display_instruction(void) {
    printf("HUONG DAN CHOI:\n");
    printf("1. Game co luat choi giong nhu ai la trieu phu\n");
    printf("2. Co 15 cau hoi trong game\n");
    printf("3. cau hoi so 5 va 10 la moc cau hoi\n4. Vi du nguoi choi tra loi sai cau hoi so 6, 7, 8 hoac 9 thi se rot ve phan thuong danh cho cau hoi so 5\n");
    printf("5. Tuong tu cho cau hoi moc so 10\n");
    printf("== Phan thuong cho cac cau hoi duoc ghi o duoi:\n");
    printf("15. 75 phut choi game\n14. 70 phut choi game\n13. 65 phut choi game\n12. 60 phut choi game\n11. 55 phut choi game\n10. 40 phut choi game\n09. 36 phut choi game\n08. 32 phut choi game\n07. 28 phut choi game\n06. 24 phut choi game\n05. 15 phut choi game\n04. 12 phut choi game\n03. 09 phut choi game\n02. 06 phut choi game\n01. 03 phut choi game\n");
    printf("Press any key to start game ... \n");
    getch(); 
}

/************************************
 * 
 * 
 * 
*/
void game_display_reward(game *game_ptr) {
    clrscr(); 
    printf("So thoi gian choi gianh them duoc la %d phut\n", (*game_ptr).gamer_reward * 3);
    printf("Press any key to exit game ...\n"); 
    getch(); 
}

#ifdef DEBUG_P7

game quiz_game; 

int main(void) {
    /*******************
     * 1. khởi tạo game
    */
    game_init(&quiz_game); 

    /*****************
     * 2. hiển thị 
     *      màn hình 
     *      hướng dẫn 
    */
    game_display_instruction(); 

    while (1) {
        /*******************
         * 3. xóa màn hình
         * 
        */
        clrscr(); 

        /********************
         * 4. chơi game 
         * 
        */
        game_status status = game_run(&quiz_game); 

        if (status = OVER) {
            break; 
        }
    }

    game_display_reward(&quiz_game); 
}

#endif