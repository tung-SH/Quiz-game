/*******************************************
 * question.c -- giá trị câu hỏi của 
 *      game câu đố 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: định nghĩa cho giá trị 
 *          câu hỏi và hàm template, to_string
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
 *      - PROGRAM: 9
 *      - FUNCTION: 20, 19
 * 
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header/general_function.h"
#include "header/interactive.c"
#include "header/input_file.c"
#include "header/setting_function.h"
#include "header/setting_program.h"


const int NUM_ANSWER = 4; /* NUMBER OF ANSWER OF A QUESTION */


struct question {
    char* content; /* content of the question */
    char** answers; /* 4 possible answers of the question */
    char right_answer; /* order of the right answer */
}; 

typedef struct question question; 

/************************************
 * question_template -- giá trị câu hỏi
 *      mẫu để gán vào biến câu hỏi 
 * 
 * 
*/
question question_template(const char* contentV, char** answersV, char right_answerV) {
    question result; 

    result.content = (char*)malloc(MAX_LENGTH); 
    strcpy(result.content, contentV); 
    result.answers = answersV; 
    result.right_answer = right_answerV; 

    #ifdef DEBUG_F20
        printf("Question template:\n%s\nA. %s\nB. %s\nC. %s\nD. %s\n", result.content, result.answers[0], result.answers[1], result.answers[2], result.answers[3]); 
    #endif 

    return result; 
}

/************************************
 * question_to_string -- chuyển đổi 
 *      giá trị câu hỏi sang xâu kí 
 *      tự 
 * 
 * NOTE: do di ra ngoài block ở ngoài nên chắc chắc mình 
 *      phải dùng cấp phát bộ nhớ động 
*/
char *question_to_string(question questionV) {
    char *result; 

    result = (char*)malloc(MAX_LENGTH); 
    sprintf(result, "%s\nA. %s\nB. %s\nC. %s\nD. %s\nRight answer is %c\n", questionV.content, questionV.answers[1 -1], questionV.answers[2 -1], questionV.answers[3 -1], questionV.answers[4 -1], TO_UPPER(questionV.right_answer));

    #ifdef DEBUG_F20
        printf("Question to string:\n%s", result); 
    #endif 

    return result; 
}

/*********************************************
 * question_template_by_file_line -- giá trị 
 *      câu hỏi mẫu được nhập vào từ tên file 
 *      và dòng của file 
 * 
 * Parameters: 
 *      file_name -- xâu kí tự thể hiện tên file
 *      line -- dòng trên file 
 * 
 * returns
 *      giá trị câu hỏi (question)
 * 
*/
question question_template_by_file_line(const char *file_name, int line) {
    question result; 

    char *content_mid = (char*)malloc(MAX_LENGTH); /* declare the middle string of content of question */ 
    char **answers_mid = (char**)malloc(4 * sizeof(char*)); /* declare the middle list of 4 answer string of question */
    for (int i = 1; i <= 4; ++i) {
        answers_mid[i -1] = (char*)malloc(MAX_LENGTH); /* delcare 4 each answer string */
    }
    char right_answer_mid; /* middle order of right answer */

    sscanf(content_line_file(file_name, line), "%[^,],%[^,],%[^,],%[^,],%[^,],%c", content_mid, answers_mid[1 -1], answers_mid[2 -1], answers_mid[3 -1], answers_mid[4 -1], &right_answer_mid);

    result = question_template(content_mid, answers_mid, right_answer_mid); 

    #ifdef DEBUG_F19
        printf("Question template by file:\n%s", question_to_string(result));
    #endif

    return result; 
}



#ifdef DEBUG_P9

const char FILE_NAME[] = "D:/program/Quiz-game/code/data/question_file.csv";

FILE *f; /* file pointer */

int main(void) {
    question myQuestion; 

    for (int i = 2; i <= 16; ++i) { /* from first question value to 15th one */
        printf("\nQuestion %dth:\n", i - 1); 
        myQuestion = question_template_by_file_line(FILE_NAME, i); 
    }

    
}


#endif 
