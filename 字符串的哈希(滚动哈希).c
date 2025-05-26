#include <stdio.h>
#include <string.h>
#include <math.h>

// BKDR哈希函数
unsigned long BKDRHash(const char *str) {
    unsigned long hash = 0;
    while (*str) {
        hash = hash * 131 + (*str++);
    }
    return hash;
}

// 计算下一个子串的哈希值
unsigned long nextHash(unsigned long prevHash, char oldChar, char newChar, int len) {
    unsigned long newHash = prevHash - oldChar * pow(131, len - 1);
    newHash = newHash * 131 + newChar;
    return newHash;
}

// 在字符串中查找特定子串
int findSubstring(const char *str, const char *subStr) {
    int len = strlen(subStr);
    int strLen = strlen(str);

    unsigned long subHash = BKDRHash(subStr);
    unsigned long currentHash = 0;

    // 修正初始哈希值计算
    for (int i = 0; i < len; i++) {
        currentHash = currentHash * 131 + str[i];
    }

    for (int i = 0; i <= strLen - len; i++) {
        if (currentHash == subHash && strncmp(str + i, subStr, len) == 0) {
            return i;
        }
        if (i < strLen - len) {
            currentHash = nextHash(currentHash, str[i], str[i + len], len);
        }
    }
    return -1;
}

int main() {
    const char *str = "hello world";
    const char *subStr = "world";

    int position = findSubstring(str, subStr);
    if (position != -1) {
        printf("子串 '%s' 出现在字符串 '%s' 的位置 %d\n", subStr, str, position);
    } else {
        printf("子串 '%s' 未出现在字符串 '%s' 中\n", subStr, str);
    }

    return 0;
}