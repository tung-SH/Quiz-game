# test plan cho mô hình theo phong cách bottom up 

tức là test thử mô hình với các bài test chi tiết nhỏ từ file nhỏ nhất 

1. file: question.c - nên hiện ra câu hỏi "Nguyễn Thanh Tùng thích chơi game gì nhất?" với 4 câu trả lời "A. freefire" "B. genshin impact" "C. aspalt 8" "D. gunny" 
 
2. file: question.c - nên hiện ra như ở dưới: 
`Nguyen Thanh Tung thich nhat game gi?`
`A. Freefire`
`B. Genshin Impact`
`C. Aspalt 8`
`D. Gunny`

và sau đó nhấn phím c thì hiện ra màn hình:
`Correct!!!`

Còn nếu nhấn phím a, b hoặc d thì nhấn phím: 
`Incorrect!`

Sau đó chương trình nên đứng yên trong vòng 3s rồi kết thúc chương trình 

3. file