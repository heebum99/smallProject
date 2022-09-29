#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char f_num[1001], s_num[1001]; //숫자를 담기위해 char 배열 생성
int res[2001]; //계산한 숫자를 각 자리수마다 담기 위한 배열

int compare(char* a, char* b) { //입력받은 두 숫자의 길이를 비교하는 함수
	int fl = strlen(f_num), sl = strlen(s_num), i; //첫 번째,두 번째 입력한 수의 길이

	if (fl == sl) { //두 숫자의 길이가 같다면
		for (i = 0; i < fl; i++) {
			if (f_num[i] != s_num[i]) { //같은 자리수의 숫자가 같지 않을때
				return (f_num[i] > s_num[i]) ? 1 : -1;
				//숫자 크기를 비교해서 첫번째 수가 크면 1을 아니면 -1을 리턴
			}
		}
		return 0;
	}

	else { //숫자의 길이가 다르면 
		return (fl > sl) ? 1 : -1;
		//첫번째 수가 길면 1 아니면 -1을 리턴
	}
}

void plus(char* a, char* b) { //덧셈 연산 함수 
	int fl = strlen(f_num), sl = strlen(s_num), i; //첫 번째,두 번째 입력한 수의 길이

	res[0] = 0;

	for (i = 0; i < fl && i < sl; i++) { //i값이 첫번째, 두번째수의 길이보다 작은 동안 실행
		res[i] += a[fl - i - 1] - '0' + b[sl - i - 1] - '0';
		//각 수의 일의자리부터 더해서 res배열에 값을 담는다
		//두 숫자를 입력받은 배열은 char형 배열이므로 입력한 자리수보다 +1(널값)만큼 크다
		//입력 값이 char형이기 때문에 int형으로 바꿔주기위해 0의 아스키값 만큼을 빼준다.
		res[i + 1] = res[i] / 10; //덧셈의 받아올림 개념
		res[i] %= 10;
		//더한 결과값이 10보다 클 경우 받아올림이 생김
		//10으로 나눈 몫은 다음 자리수로 넘겨준다.
		//10으로 나눈 나머지를 현재 자리수 결과에 저장.
		//ex)7+8이면 15이므로 10은 다음 자리수에 1로 넘어가고 나머지 5만 써준다.
	}

	while (i < fl) { //첫번째 수가 두 번째 수보다 길다면 위 반복문 탈출 후 실행.
		//첫번째 수가 더 길기 때문에 첫번째 수만 남아있음. 
		//=> 첫번째 수의 i번째 자리의 값을 그대로 결과값에 입력하는 과정.
		res[i] += a[fl - i - 1] - '0';
		res[i + 1] = res[i] / 10;
		res[i++] %= 10;
	}

	while (i < sl) { //두번째 입력한 수가 더 긴 경우, 위와 동일
		res[i] += b[sl - i - 1] - '0';
		res[i + 1] = res[i] / 10;
		res[i++] %= 10;
	}

	if (res[i] == 0) {
		i--;
	}

	while (i >= 0) { //제일 큰 자릿수부터 일의자리까지 차례로 출력
		printf("%d", res[i--]);
	}
}



int main() {

	char* a = f_num, * b = s_num, am = 0, bm = 0, c;

	printf("두 수를 입력하세요.");
	scanf("%s %s", f_num, s_num);
	plus(a, b);

	return 0;
}