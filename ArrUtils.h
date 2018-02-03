#include <Windows.h>
#include <cstdio>

namespace ArrUtils {
	int IndexOf(char* arr, char c, int start = 0) {
		for (int i = start; i < strlen(arr); i++) {
			if (arr[i] == c) {
				return i;
			}
		}
		return -1;
	}

	int LastIndexOf(char* arr, char c, int start = 0) {
		for (int i = strlen(arr) - 1; i > start; i--) {
			if (arr[i] == c) {
				return i;
			}
		}
		return -1;
	}

	int IndexOf(char* arr, char* c, int start = 0) {
		for (int i = start; i < strlen(arr); i++) {
			if (arr[i] == c[0]) {
				bool flag = false;
				for (int j = 0; j < strlen(c); j++) {
					if (arr[i + j] != c[j]) {
						flag = true;
					}
				}
				if (!flag) {
					return i;
				}
			}
		}
		return -1;
	}

	char* SubArr(char* arr, int start, int end = -1) {
		int len = strlen(arr) - start - (end == -1 ? 0 : strlen(arr) - end);
		char* dest = new char[len + 1];
		dest[len] = '\0';
		memcpy(dest, &arr[0] + start, len);
		return dest;
	}

	char* Concat(char* arr, char* arr2) {
		int len = strlen(arr) + strlen(arr2);
		char* res = new char[len + 1];
		res[len] = '\0';
		memcpy(res, &arr[0], strlen(arr));
		memcpy(&res[strlen(arr)], &arr2[0], strlen(arr2));
		return res;
	}

	bool StartsWith(char* arr, char* sequence) {
		return strncmp(arr, sequence, strlen(sequence)) == 0;
	}

	int Length(char* arr) {
		return strlen(arr);
	}
}
