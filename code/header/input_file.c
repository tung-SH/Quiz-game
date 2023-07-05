/****************************************
 * input_file.c -- cung cấp các hàm làm 
 *      việc nhanh với file input 
 *  
 * lỗi: tại dòng số 87 
 *      tại sao ko mở được file mặc dù đúng tên rồi 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setting_general.h"


const long long MAX_LENGTH = 10000; /* MAX LENGTH OF STRING */

/*************************************
 * file_num_line -- số dòng trong file
 * 
 * parameters 
 *      file_name -- xâu kí tự tên của 
 *          file 
 * 
 * return 
 *      số nguyên: 
 *          0, 1, 2, 3, ... 
 *          -1 nếu ko mở được file 
 * 
*/
int file_num_line(const char *file_name) {
    int result; 

    FILE *fin = fopen(file_name, "r"); /* open file */    
    result = 0; /* initialize counter */
    char *string_ptr; /* pointer to check status of fgets function */
    char line[10000]; /* input line */

    if (fin == NULL) { /* file pointer don't link to actual file */
        result = -1; 
    } else {
        while(1) {
            string_ptr = fgets(line, sizeof(line), fin); /* read a line in file */

            if (string_ptr == NULL) { /* end of file */
                break; 
            } else {
                ++result; /* increment a line in file */
            }

        }
    }

    fclose(fin); 

    return result; 
}



/**************************************
 * content_line_file -- nội dung 1 dòng 
 *      của file input
 * 
 * parameters
 *      file_name -- xâu kí tự tên file
 *      line -- dòng cần lấy nội dung
 * 
 * return
 *      xâu kí tự
*/
char *content_line_file(const char *file_name, int line) {
    char *result; 

    FILE *fin; /* input file pointer */
    char line_input[1000]; /* input line */

    result = (char*)malloc(MAX_LENGTH); /* allocate the memory */
    fin = fopen(file_name, "r"); /* open file */

    if (line > file_num_line(file_name)) { 
        result = NULL;
    } else {
        for (int i = 1; i <= line; ++i) {
            fgets(line_input, sizeof(line_input), fin);
        } /* read the line nth content into line_input string */

        strcpy(result, line_input); /* cóp nội dung xâu kí từ từ line vào result */
    }

    return result; 
}




/**************************************
 * content_file -- nội dung cả file 
 * 
 * parameters
 *      fin -- input file pointer
 * 
 * return 
 *      xâu kí tự
 * 
 * 
 * NOTE: chưa cần thiết nên mình chưa làm 
 *      những cái ở trên là đủ để viết tiêp 
 *      cho question rồi 
*/


#ifdef DEBUG_G

const char FILE_NAME[] = "D:/program/Quiz-game/code/data/question_file.csv"; 

int main(void) {

    printf("%s", content_line_file(FILE_NAME, 1)); 

}


#endif