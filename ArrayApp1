#include <iostream>
#include <limits>

int main() {
    short arr[] = { 5, -3, 2, 7, -8, 4, 1, -2, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int minIndexOneBased = 0;
    long long sumBetween = 0;

    // --- 1. Поиск минимального элемента на ассемблере ---
    __asm {
        xor esi, esi              // ESI = смещение в байтах
        mov ecx, n

        mov ax, arr[esi]          // читаем первый элемент
        mov bx, ax                // BX = минимум (16 бит)
        mov edi, esi              // EDI = смещение минимума

        min_loop :
        cmp ecx, 0
            je min_loop_end

            mov cx, arr[esi]
            cmp cx, bx
            jge skip_update
            mov bx, cx
            mov edi, esi

            skip_update :
        add esi, 2
            dec ecx
            jmp min_loop

            min_loop_end :
        shr edi, 1                // смещение в байтах -> индекс элемента
            inc edi                   // 1-based номер
            mov minIndexOneBased, edi
    }

    // --- 2. Сумма между первым и вторым отрицательными на C++ ---
    int firstNegIndex = -1;
    int secondNegIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else if (secondNegIndex == -1) {
                secondNegIndex = i;
                break; // нашли два отрицательных, дальше не нужно
            }
        }
    }

    if (firstNegIndex != -1 && secondNegIndex != -1) {
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sumBetween += arr[i];
        }
    }

    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Index of minimum element (1-based): " << minIndexOneBased << "\n";
    std::cout << "Sum between first and second negative elements: " << sumBetween << "\n";

    return 0;
}
