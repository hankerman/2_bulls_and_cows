#include <iostream>
using namespace std;

void fill(int arr[], int size) {
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }

}

void check(int arr[], int size) {
    int temp, temp2;
    int matches = 1;
    while (matches != 0) {
        matches = 0;
        for (int i = 0; i < size; i++) {
            temp = arr[i];
            for (int j = i + 1; j < size; j++) {
                temp2 = arr[j];
                if (temp == temp2) {
                    arr[i] += rand() % 3;
                    matches++;
                    if (arr[i] >= 10) {
                        arr[i] -= 5;
                    }
                }
            }
        }
        
    }
    
}


void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}
void inpt(int arr[], int size, int playerinput) {
    int num = playerinput, res;
    for (int i = 0; i < size; i++) {
        res = num % 10;
        arr[i] = res;
        playerinput /= 10;
        num = playerinput;
    }
    int temp;
    for (int i = 0, j = size -1; i < size / 2; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    

}

int bulld(int arr[], int size, int arr2[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr2[i]) {
            count++;
        }
    }
    return count;
}

int cows(int arr[], int arr2[], int size) {

    int temp, count = 0;
    for (int i = 0; i < size; i++) {
        temp = arr[i];
        for (int j = 0; j < size; j++) {
            if (temp == arr2[j]) {
                count++;
            }
        }
    }
    return count;
}



int main()
{
    /*Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий
    должен угадать его. После ввода пользователем числа программа сообщает, сколько цифр числа
    угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания
    числа на экран необходимо вывести количество сделанных пользователем попыток. В
    программе необходимо использовать рекурсию.
    */

    srand(time(NULL));
    const int size = 4;
    int number[size], numberplayer[size];
    int plauerinput, res = 1, counter = 0, n = 1;
    fill(number, size);  
    print(number, size);
    check(number, size);
    print(number, size);
    
    
    cin >> plauerinput;
    inpt(numberplayer, size, plauerinput);
    cout << "bulld - " << bulld(number, size, numberplayer) << endl;
    cout << "cows - " << cows(number, numberplayer, size) << endl;
    res = bulld(number, size, numberplayer);

    while (n != 0) {
        counter++;
        cin >> plauerinput;
        inpt(numberplayer, size, plauerinput);
        //print(numberplayer, size);
        cout << "bulld - " << bulld(number, size, numberplayer) << endl;
        cout << "cows - " << cows(number, numberplayer, size) << endl;
        res = bulld(number, size, numberplayer);
        if (res == 4) {
            n = 0;
        }
    }

    cout << "Number of attempts - " << counter;
}
