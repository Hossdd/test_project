#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TYPES 7 // �н����� ������ ����
#define MAX_LEN 8 // �н������� �ִ� ����
#define NUM_PASSWORDS 10 // �� ������ �н����� ����

// �� �н����� ������ ����� ����
const char* PASSWORD_TYPES[NUM_TYPES] = {
    "0123456789", // ����
    "abcdefghijklmnopqrstuvwxyz", // �ҹ���
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // �빮��
    "!@#$%^&*()_+~`|}{[]\\:;\"'<>,.?/", // Ư������
    "0123456789abcdefghijklmnopqrstuvwxyz", // ���� + �ҹ���
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", // �ҹ��� + �빮��
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~`|}{[]\\:;\"'<>,.?/" // ��� ����
};

// �������� �н����带 �����ϴ� �Լ�
char* generate_password() {
    int len = rand() % (MAX_LEN - 3) + 4; // �н����� ���̸� 4~8 ������ ������ ������ ����
    char* password = malloc(len + 1); // �н����� ���� �Ҵ�
    int type = rand() % NUM_TYPES; // �������� ���� ����
    const char* charset = PASSWORD_TYPES[type]; // ������ ������ �ش��ϴ� ���ڼ�
    int charset_len = strlen(charset); // ���ڼ��� ����
    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % charset_len]; // �������� ���� �����Ͽ� �н����� ����
    }
    password[len] = '\0'; // ���ڿ� ���� ǥ���ϴ� NULL ���� �߰�
    return password;
}

// �н����� ũ��ŷ �Լ�
int crack_password(char* password) {
    time_t start_time = time(NULL); // ���� �ð� ���
    int found = 0; // �н����带 ã�Ҵ��� ����
    for (int i = 0; i < NUM_TYPES && !found; i++) { // �� ������ ����
        const char* charset = PASSWORD_TYPES[i]; // �ش� ������ �ش��ϴ� ���ڼ�
        int charset_len = strlen(charset); // ���ڼ��� ����
        for (int j = 0; j < charset_len && !found; j++) { // �ش� ������ ���ڼ¿� ����
            for (int k = 4; k <= MAX_LEN && !found; k++) { // ���̸� 4~8�� �ٲ㰡��
                char* test_password = malloc(k + 1); // �׽�Ʈ�� �н����� ���� �Ҵ�
                for (int l = 0; l < k; l++) { // �������� ���� �����Ͽ� �н����� ����
if (l == 0 && i <= 3) { // ù ���ڰ� ���� �Ǵ� Ư�������� ���
test_password[l] = charset[rand() % (charset_len - 10)]; // ���ڿ� Ư�����ڿ����� ù ���ڷ� 0~9�� Ư�����ڸ� ������ ���ڸ� ���
} else {
test_password[l] = charset[rand() % charset_len];
}
}
test_password[k] = '\0'; // ���ڿ� ���� ǥ���ϴ� NULL ���� �߰�
if (strcmp(test_password, password) == 0) { // �н����带 ã������
found = 1; // found �÷��׸� �����ϰ�
printf("Password cracked! Password is %s\n", test_password); // �н����带 ���
}
free(test_password); // �Ҵ��� ���� ����
}
}
}
time_t end_time = time(NULL); // �� �ð� ���
return (int)(end_time - start_time); // �ɸ� �ð� ��ȯ
}

int main() {
srand(time(NULL)); // ���� ������ �ʱ�ȭ
// ���ǿ� �´� �н����� ����
char* passwords[NUM_TYPES * NUM_PASSWORDS];
for (int i = 0; i < NUM_TYPES; i++) {
    for (int j = 0; j < NUM_PASSWORDS; j++) {
        passwords[i * NUM_PASSWORDS + j] = generate_password();
    }
}

// ������ �н����� ���
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    printf("%s\n", passwords[i]);
}

// �н����� ũ��ŷ �� �ð� ����
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    printf("Cracking password: %s\n", passwords[i]);
    int time_taken = crack_password(passwords[i]);
    printf("Time taken: %d seconds\n", time_taken);
}

// ������ �н����� �޸� ����
for (int i = 0; i < NUM_TYPES * NUM_PASSWORDS; i++) {
    free(passwords[i]);
}

return 0;
}
