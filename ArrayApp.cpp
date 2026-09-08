// arrayApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{

    short dim[] = { 15, 42, 8, -5, 12, 0, 7, 8, 9, 10, 20 };
    int count = 0;

    __asm {
        //esi индекс 
        xor esi, esi
        //в регстре ecx 11 повторений
        mov ecx, 11
        go: 
        //берем eci элемент из dim в регистр bx
            mov bx, dim[esi]
                //сравнение с 10h
            cmp bx, 10h
                //если сравнение <= 16 прыгаем на метку skip
            jle skip
                //инкремент
            inc count

                skip: 
            // смещение на 2 байта
            add esi, 2

            loop go

    }

    std::cout << "numbers count > 10h = " << count << std::endl;
}

