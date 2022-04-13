#include <stdio.h>

// ��� & ���� ���ϱ� 
int getLeapYear(int leapYear) {
	if((leapYear % 4 == 0 && leapYear % 100 != 0) || leapYear % 400 == 0) {
		return 1;
	} else {
		return 0;
	}
}

// ��� & ���� ���ϱ� 
int getDayOfMonth(int inputYear, int inputMonth) {
	int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
	dayOfMonth[2] = dayOfMonth[2] + getLeapYear(inputYear); // getLeapYear�Լ����� ������ ���, 2��(dayOfMonth[2])�� return�� 1�߰� 
	return dayOfMonth[inputMonth];
}

// inputYear�� & inputMonth���� �� �� ���ϱ� 
int getDay(int inputYear, int inputMonth) {
	int cnt = 0;
	// 1�� 1�� �����Ϻ��� 
	// ����� ��� 365��, ������ ��� 366���� ���ϱ� 
	for (int indexYear = 1; indexYear < inputYear; indexYear++) {
		cnt = cnt + 365 + getLeapYear(indexYear); 
	}
	// ��ް� ������ �� �� ���ϱ� 
	for (int indexMonth = 1; indexMonth < inputMonth; indexMonth++) {
		cnt = cnt + getDayOfMonth(inputYear, indexMonth); 
	}
	return (cnt + 1) % 7; 
}
// ��� 
void printOut(int startDay, int endDay) {
	printf("%4s%4s%4s%4s%4s%4s%4s\n", "��", "��", "ȭ", "��", "��", "��", "��");
	// �����ϱ��� ���� 
	for (int indexSpace = 0; indexSpace < startDay; indexSpace++) {
		printf("    ");
	}
	// startDay���� �� ���, 6(�����) ���� 
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
		printf("�⵵ �Է� : ");
		scanf("%d", &inputYear);
			if (inputYear == 0) {
				break;
			}
		printf("�� �Է� : ");
		scanf("%d", &inputMonth);  
		int startDay = getDay(inputYear, inputMonth);
		int endDay = getDayOfMonth(inputYear, inputMonth);
		printf("====== %d�� %d�� =====\n", inputYear, inputMonth);
		printOut(startDay, endDay);
	}
	printf("�����մϴ�.");
	
}
