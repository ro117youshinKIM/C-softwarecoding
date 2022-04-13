#include <stdio.h>

// 평년 & 윤년 구하기 
int getLeapYear(int leapYear) {
	if((leapYear % 4 == 0 && leapYear % 100 != 0) || leapYear % 400 == 0) {
		return 1;
	} else {
		return 0;
	}
}

// 평월 & 윤달 구하기 
int getDayOfMonth(int inputYear, int inputMonth) {
	int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
	dayOfMonth[2] = dayOfMonth[2] + getLeapYear(inputYear); // getLeapYear함수에서 윤년일 경우, 2월(dayOfMonth[2])에 return값 1추가 
	return dayOfMonth[inputMonth];
}

// inputYear년 & inputMonth달의 일 수 구하기 
int getDay(int inputYear, int inputMonth) {
	int cnt = 0;
	// 1월 1일 월요일부터 
	// 평년일 경우 365일, 윤년일 경우 366일을 더하기 
	for (int indexYear = 1; indexYear < inputYear; indexYear++) {
		cnt = cnt + 365 + getLeapYear(indexYear); 
	}
	// 평달과 윤달의 일 수 구하기 
	for (int indexMonth = 1; indexMonth < inputMonth; indexMonth++) {
		cnt = cnt + getDayOfMonth(inputYear, indexMonth); 
	}
	return (cnt + 1) % 7; 
}
// 출력 
void printOut(int startDay, int endDay) {
	printf("%4s%4s%4s%4s%4s%4s%4s\n", "일", "월", "화", "수", "목", "금", "토");
	// 시작일까지 띄어쓰기 
	for (int indexSpace = 0; indexSpace < startDay; indexSpace++) {
		printf("    ");
	}
	// startDay부터 일 찍고, 6(토요일) 개행 
	for (int indexDay = 1, lineBreak = startDay; indexDay <= endDay; indexDay++, lineBreak++){
      printf("%4d", indexDay);
         if (lineBreak % 7 == 6) {
            printf("\n");
         }
   	}
   printf("\n");
}

int main() {
	int inputYear, inputMonth;
	
	while (true) {
		printf("년도 입력 : ");
		scanf("%d", &inputYear);
			if (inputYear == 0) {
				break;
			}
		printf("월 입력 : ");
		scanf("%d", &inputMonth);  
		int startDay = getDay(inputYear, inputMonth);
		int endDay = getDayOfMonth(inputYear, inputMonth);
		printf("====== %d년 %d일 =====\n", inputYear, inputMonth);
		printOut(startDay, endDay);
	}
	printf("종료합니다.");
	
}
