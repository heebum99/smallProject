#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//길이가 1000자리 미만의 긴 정수의 계산을 위한 계산기
//덧셈, 뺄셈, 곱셈 구현

char f_num[1002], s_num[1002]; //1000자리 숫자를 담기위해 char 배열 생성(부호와 널값자리만큼 +2)
int res[2100]; //계산한 숫자를 각 자리수마다 담기 위한 배열

int compare(char* a, char* b) { //입력받은 두 숫자의 길이를 비교하는 함수
	int fl = strlen(a), sl = strlen(b), i; //첫 번째,두 번째 입력한 수의 길이

	if (fl == sl) { //자리수가 같을 땐 결과 값의 부호 결정을 위해 맨 앞자리 수를 비교
		if (a[0] > b[0]) { //첫번째 수의 앞자리가 크면 1 아니면 -1 리턴
			return 1;
		}
		else {
			return -1;
		}
	}

	return (fl > sl) ? 1 : -1; //첫번째 수가 길면 1 아니면 -1을 리턴

}

void plus(char* a, char* b) { //덧셈 연산 함수 
	int fl = strlen(a), sl = strlen(b), i; //첫 번째,두 번째 입력한 수의 길이

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
		res[i++] %= 10; //10으로 나눈 나머지를 현재 자릿수에 저장한 후 i값 증가.
	}

	while (i < sl) { //두번째 입력한 수가 더 긴 경우, 위와 동일
		res[i] += b[sl - i - 1] - '0';
		res[i + 1] = res[i] / 10;
		res[i++] %= 10;
	}

	if (res[i] == 0) { //ex)2+5의 계산결과가 000000007로 출력되지 않게 맨 앞부분의 0은 삭제
		i--;
	}

	while (i >= 0) { //제일 큰 자릿수부터 일의자리까지 차례로 출력
		printf("%d", res[i--]);
	}
}

void minus(char* a, char* b) { //뺄셈 연산 함수
	//더 큰 값을 a에 작은값을 b에 인자로 넘겨서 줘야한다.
	int fl = strlen(a), sl = strlen(b), i;

	res[0] = 0;

	for (i = 0; i < fl && i < sl; i++) { //i값이 첫번째,두번째 숫자의 자리수보다 작은 동안 실행.
		res[i] += 10 + (a[fl - i - 1] - b[sl - i - 1]);
		res[i + 1] = (res[i] / 10) - 1;
		res[i] %= 10;
	}

	while (i < fl) { //첫번째 수가 두 번째 수보다 길다면 위 반복문 탈출 후 실행.
		//첫번째 수가 더 길기 때문에 첫번째 수만 남아있음. 
		//=> 첫번째 수의 i번째 자리의 값을 그대로 결과값에 입력하는 과정.
		res[i] += 10 + a[fl - i - 1] - '0'; //이전 자릿수에서 -1을 받고 현재 자릿수의 값이 0일경우 음수가 출력되기 때문에 마찬가지로 10을 더해준다.
		res[i + 1] = res[i] / 10 - 1; //10으로 나눈 몫을 구하고 위 과정에서 10을 더했으니 그만큼의 값을 빼준 후 다음 자릿수에 저장.
		res[i] %= 10; //10으로 나눈 나머지 값을 현재 자릿수에 저장한 후 다음 자릿수에 저장.
		i++;
	}

	while (res[i] == 0 || res[i] < 0) {
		i--;
	}

	while (i >= 0) { //맨 앞자리부터 일의자리까지 차례로 결과 값 출력
		printf("%d", res[i--]);
	}
}

void multiply(char* a, char* b) { //곱셈 연산 함수
	int fl = strlen(a) - 1, sl = strlen(b) - 1, i, j; //char형 배열안의 널값을 제외시키기 위해 -1

	for (i = 0; i < 2100; i++) { //최대 1000자리수라 가정하면 1000자리수 * 1000자리수 = 2000자리수이므로 범위는 약 2000자리수
		res[i] = 0; //모든 자리수를 0으로 초기화.
	}

	for (i = 0; i <= fl; i++) { //첫번째 수는 일의자리부터 높은 자리수로 이동하며 계산
		for (j = 0; j <= sl; j++) { //두번째 수는 일의자리부터 높은 자리수로 이동하며 곱셈 계산
			res[i + j] += (a[fl - i] - '0') * (b[sl - j] - '0');
			//같은 자리수의 결과 값은 서로 합해준다.
		}
	}

	for (i = 0; i < 2100; i++) {
		res[i + 1] += res[i] / 10; //곱으로 인해 나온 결과값이 10을 넘어가면 넘어가는 만큼의 몫을 다음 자릿수에 저장.	}
		res[i] %= 10; //10으로 나눈 나머지는 현재 자리수의 값으로 저장
	}

	while (res[i] == 0) {
		i--;
	}

	while (i >= 0) { //높은 자리수의 값부터 일의 자리수의 값까지 출력
		printf("%d", res[i--]);
	}
}

int main() {

	char* a = f_num, * b = s_num, am = 0, bm = 0, c, op;
	//am과 bm은 입력된 수의 부호 => 0은 양수, 1은 음수 

	printf("자리수가 큰 정수의 덧셈, 뺄셈, 곱셈이 가능한 계산기 입니다.\n");
	printf("두 수를 입력하세요. ex) 2 + 3 >> ");
	scanf("%s %c %s", f_num, &op, s_num);
	printf("\n결과값:");

	if (f_num[0] == '-') { //첫번째 입력한 수가 음수라면
		a++; //부호를 제외한 숫자부터 읽기 위해서 포인터 변수가 f_num[1]부터 가리키게 한다.
		am++; //음수 처리
	}

	if (s_num[0] == '-') { //두번째 수가 음수라면
		b++; //부호를 제외한 숫자를 읽기위해 포인터 변수가 s_num[1]부터 가리키게 한다.
		bm++; //음수처리
	}

	c = compare(a, b); //첫번째, 두번째 입력한 수의 길이 비교후 첫번째가 더 길면 1 아니면 -1을 반환

	if (am == bm) { //두 수의 부호가 같을 때
		if (a[0] == '0' && b[0] == '0') { //두 수 모두 0이면 0을 출력
			printf("0");
		}
		else { // 두 수 중 하나라도 0이 아니면

			if (am == 1 && c > 0) { //둘 다 음수면서 첫번째 수의 길이가 더 길 때
				switch (op) {
				case '+':
					printf("-");
					plus(a, b);
					break;
				case '-': //첫번째 수가 더 크므로 뺄셈의 결과값은 음수
					printf("-");
					minus(a, b);
					break;
				case '*': //부호가 서로 같은 정수의 곱셈의 결과값은 양수
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 1 && c < 0) { //둘 다 음수면서 두번째 수의 길이가 더 길 때
				switch (op) {
				case '+':
					printf("-");
					plus(a, b);
					break;
				case '-': //두번째 수가 더 크므로 뺄셈의 결과값은 양수
					minus(b, a);
					break;
				case '*': //부호가 서로 같은 정수의 곱셈의 결과값은 양수
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 0 && c > 0) { //둘 다 양수면서 첫번째 수가 더 길 때
				switch (op) {
				case '+':
					plus(a, b);
					break;
				case '-':  //첫번째 수가 더 크므로 뺄셈의 결과값은 양수
					minus(a, b);
					break;
				case '*': //두 양수의 곱셈의 결과값은 양수
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 0 && c < 0) { //둘 다 양수면서 두번째 수가 더 길 때
				switch (op) {
				case '+':
					plus(a, b);
					break;
				case '-': //첫번째 수가 더 작으므로 뺄셈의 결과값은 음수
					printf("-");
					minus(b, a);
					break;
				case '*':
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
		}
	}
	else { //두 수의 부호가 서로 다를 때
		if (a[0] == '0' && b[0] == '0') { //두 수 모두 0이면 0을 출력
			printf("0");
		}
		else { // 두 수 중 하나라도 0이 아니면
			if (am == 1 && c > 0) { //첫번째 수는 음수, 두번째 수는 양수이며 첫번째 수가 더 길 때
				switch (op) {
				case '+': //음수인 첫번째 수가 더 크므로 덧셈의 결과값은 음수
					printf("-");
					minus(a, b); //음수 + 양수 => 양수 - 양수와 같이 생각할수 있으므로 minus()함수 호출
					break;
				case '-': //음수 - 양수 = 음수
					printf("-");
					plus(a, b); //음수 - 양수 => 음수 + 음수 => -(양수 + 양수)와 같이 생각할 수 있으므로 plus()함수 호출
					break;
				case '*': //음수와 양수의 곱셈의 결과는 음수
					printf("-");
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 1 && c < 0) { //첫번째 수는 음수, 두번째 수는 양수이며 두번째 수가 더 길 때
				switch (op) {
				case '+': //음수보다 양수인 두번째 수가 더 크기때문에 덧셈의 결과는 양수
					minus(b, a); //음수 + 양수 => 양수 - 양수와 같으므로 minus()함수 호출하되 길이가 긴 숫자를 먼저 인자로 보낸다.
					break;
				case '-': //음수 - 양수 => -양수 - 양수 => -(양수+양수)이므로 plus()함수 호출
					printf("-");
					plus(a, b);
					break;
				case '*': //서로 다른 부호의 두 정수 곱셈의 결과값은 음수
					printf("-");
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 0 && c > 0) { //첫번째 수는 양수, 두번째 수는 음수이며 첫번째 수가 더 길 때
				switch (op) {
				case '+': //양수 + 음수 => 양수 - 양수이므로 minus()함수 호출
					minus(a, b);
					break;
				case '-':  //양수 - 음수 => 양수 + 양수이므로 plus()함수 호출
					plus(a, b);
					break;
				case '*': //서로 다른 부호의 두 정수 곱셈의 결과값은 음수
					printf("-");
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
			else if (am == 0 && c < 0) { //첫번째 수는 양수, 두번째 수는 음수이며 두번째 수가 더 길 때
				switch (op) {
				case '+': //음수인 두번째 수가 더 크기때문에 덧셈의 결과값은 음수
					printf("-");
					minus(b, a); //양수 + 음수 => 양수 - 양수이므로 minus()함수 호출하되 큰 값을 인자로 먼저 보내준다.
					break;
				case '-': //양수 - 음수 => 양수 + 양수이므로 plus()함수 호출
					plus(a, b);
					break;
				case '*': //서로 다른 부호의 두 정수 곱셈의 결과값은 음수
					printf("-");
					multiply(a, b);
					break;
				default:
					printf("+, -, * 중에서 입력해주세요\n");
				}
			}
		}
	}

	return 0;
}