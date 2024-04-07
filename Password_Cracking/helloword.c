#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TYPES 7 // 패스워드 유형의 개수
#define MAX_LEN 8 // 패스워드의 최대 길이
#define NUM_PASSWORDS 10 // 각 유형별 패스워드 개수

// 각 패스워드 유형을 상수로 정의
const char* PASSWORD_TYPES[NUM_TYPES] = {
    "0123456789", // 숫자
    "abcdefghijklmnopqrstuvwxyz", // 소문자
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // 대문자
    "!@#$%^&*()_+~`|}{[]\\:;\"'<>,.?/", // 특수문자
    "0123456789abcdefghijklmnopqrstuvwxyz", // 숫자 + 소문자
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", // 소문자 + 대문자
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~`|}{[]\\:;\"'<>,.?/" // 모든 유형
};

// 무작위로 패스워드를 생성하는 함수
char* generate_password() {
    int len = rand() % (MAX_LEN - 3) + 4; // 패스워드 길이를 4~8 사이의 무작위 값으로 지정
    char* password = malloc(len + 1); // 패스워드 버퍼 할당
    int type = rand() % NUM_TYPES; // 무작위로 유형 선택
    const char* charset = PASSWORD_TYPES[type]; // 선택한 유형에 해당하는 문자셋
    int charset_len = strlen(charset); // 문자셋의 길이
    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % charset_len]; // 무작위로 문자 선택하여 패스워드 생성
    }
    password[len] = '\0'; // 문자열 끝을 표시하는 NULL 문자 추가
    return password;
}

// 패스워드 크래킹 함수
int crack_password(char* password) {
    time_t start_time = time(NULL); // 시작 시간 기록
    int found = 0; // 패스워드를 찾았는지 여부
    for (int i = 0; i < NUM_TYPES && !found; i++) { // 각 유형에 대해
        const char* charset = PASSWORD_TYPES[i]; // 해당 유형에 해당하는 문자셋
        int charset_len = strlen(charset); // 문자셋의 길이
        for (int j = 0; j < charset_len && !found; j++) { // 해당 유형의 문자셋에 대해
            for (int k = 4; k <= MAX_LEN && !found; k++) { // 길이를 4~8로 바꿔가며
                char* test_password = malloc(k + 1); // 테스트할 패스워드 버퍼 할당
                for (int l = 0; l < k; l++) { // 무작위로 문자 선택하여 패스워드 생성
if (l == 0 && i <= 3) { // 첫 글자가 숫자 또는 특수문자인 경우
test_password[l] = charset[rand() % (charset_len - 10)]; // 숫자와 특수문자에서는 첫 글자로 0~9와 특수문자를 제외한 문자만 사용
} else {
test_password[l] = charset[rand() % charset_len];
}
}
test_password[k] = '\0'; // 문자열 끝을 표시하는 NULL 문자 추가
if (strcmp(test_password, password) == 0) { // 패스워드를 찾았으면
found = 1; // found 플래그를 설정하고
printf("Password cracked! Password is %s\n", test_password); // 패스워드를 출력
}
free(test_password); // 할당한 버퍼 해제
}
}
}
time_t end_time = time(NULL); // 끝 시간 기록
return (int)(end_time - start_time); // 걸린 시간 반환
}

int main() {
srand(time(NULL)); // 난수 생성기 초기화
// 조건에 맞는 패스워드 생성
char* passwords[NUM_TYPES * NUM_PASSWORDS];
for (int i = 0; i < NUM_TYPES; i++) {
    for (int j = 0; j < NUM_PASSWORDS; j++) {
        passwords[i * NUM_PASSWORDS + j] = generate_password();
    }
}

// 생성된 패스워드 출력
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    printf("%s\n", passwords[i]);
}

// 패스워드 크래킹 및 시간 측정
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    printf("Cracking password: %s\n", passwords[i]);
    int time_taken = crack_password(passwords[i]);
    printf("Time taken: %d seconds\n", time_taken);
}

// 생성된 패스워드 메모리 해제
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    free(passwords[i]);
}

return 0;
}
