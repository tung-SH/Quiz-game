/*******************************************
 * question_list.c -- giá trị ngân hàng câu 
 *      hỏi cho game câu đố 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: định nghĩa giá trị ngân hàng câu 
 *          hỏi, 2 hàm cơ bản và hàm mẫu lấy giá trị 
 *          từ file .csv tải xuống từ google sheet 
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
 *      - PROGRAM: 8
 *      - FUNCTION: 18
 * 
**********************************************/
#include "question.c"

struct question_list {
    int num_question; /* number of questions */
    question *questions; /* a list of questions */
}; 

typedef struct question_list question_list;

/************************************
 * question_list_template -- giá trị 
 *      danh sách câu hỏi mẫu để gán
 *      vào biến danh sách câu hỏi 
 * 
 * 
*/
question_list question_list_template(int num_questionV, question *questionsV) {
    question_list result; 

    result.num_question = num_questionV; 
    result.questions = questionsV; 

    // lâu là viết debug cho mỗi hàm chứ bản chất thì nhanh 

    return result; 
}

/************************************
 * 
 * 
 * 
*/
char *question_list_to_string(question_list question_listV) {
    char *result; 
    
    result = (char*)malloc(MAX_LENGTH); 
    sprintf(result, "--------QUESTION LIST-------\n"); 
    char mid[100];
    sprintf(mid, "Number of question: %d\n", question_listV.num_question);
    strcat(result, mid); 
    for (int i = 1; i <= question_listV.num_question; ++i) {
        strcat(result, question_to_string(question_listV.questions[i -1])); 
        strcat(result, "--------------\n");
    }

    return result; 
}


/***********************************
 * 
 * 
*/
question_list question_list_template_by_file(const char *file_name) {
    question_list result; 

    result.num_question = file_num_line(file_name) - 1;
    result.questions = (question*)malloc(result.num_question * sizeof(question));

    for (int i = 1; i <= result.num_question; ++i) {
        result.questions[i -1] = question_template_by_file_line(file_name, i + 1);
    }

    #ifdef DEBUG_F17
        printf("Question list template by file:\n%s", question_list_to_string(result));
    #endif

    return result; 
}

#ifdef DEBUG_P8

const char FILE_NAME[] = "D:/program/Quiz-game/code/data/question_file.csv";

question_list bank; /* question bank */
int choice; /* user choice */
int reward; /* reward for user */
int i; /* index for question in question bank */

int main(void) {
    bank = question_list_template_by_file(FILE_NAME);

    reward = 0; /* initialize the reward */
    i = 1; 

    while (1) {
        clrscr(); 
        printf("%s", question_to_string(bank.questions[i -1]));

        choice = getch();
        choice = TO_LOWER(choice);

        if (bank.questions[i -1].order_of_right_answer == 1) {
            if (choice == 'a') {
                printf("Correct");
                wait_1ms(5000);
                ++reward; 
                ++i;  
            } else if (choice == 'b') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'c') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'd') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } 
        } else if (bank.questions[i -1].order_of_right_answer == 2) {
            if (choice == 'b') {
                printf("Correct");
                wait_1ms(5000);
                ++reward; 
                ++i;  
            } else if (choice == 'a') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'c') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'd') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } 
        } else if (bank.questions[i -1].order_of_right_answer == 3) {
            if (choice == 'c') {
                printf("Correct");
                wait_1ms(5000);
                ++reward; 
                ++i;  
            } else if (choice == 'b') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'a') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'd') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } 
        } else if (bank.questions[i -1].order_of_right_answer == 4) {
            if (choice == 'd') {
                printf("Correct");
                wait_1ms(5000);
                ++reward; 
                ++i;  
            } else if (choice == 'b') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'c') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } else if (choice == 'a') {
                printf("Incorrect");
                wait_1ms(5000);
                break;
            } 
        }
        
    }

    clrscr(); 
    printf("The reward of gamer is %d minutes", reward * 5); 
    getch(); 
    

}

#endif



