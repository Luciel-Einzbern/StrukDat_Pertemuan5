#include <iostream>
using namespace std;

const int jumlahBatu = 3;

struct Stack {
    int batu[jumlahBatu]; 
    int top;     
    char nama;   
};

void menaraHanoi(Stack &menara, char namaMenara) {
    menara.top = -1; 
    menara.nama = namaMenara;
}

void push(Stack &menara, int batu) {
    if (menara.top < jumlahBatu - 1) { 
        menara.top++;
        menara.batu[menara.top] = batu;
    }
}

int pop(Stack &menara) {
    if (menara.top >= 0) {
        int batuDiambil = menara.batu[menara.top];
        menara.top--;
        return batuDiambil;
    }
    return -1; 
}

void pindahkanHanoi(int jumlahBatu, Stack &A, Stack &B, Stack &C, int &langkah) {
    if (jumlahBatu == 1) {
        int batu = pop(A);
        push(C, batu);
        cout << langkah << ". Pindahkan batu " << batu << " dari " << A.nama << " ke " << C.nama << endl;
        langkah++;
        return;
    }

    pindahkanHanoi(jumlahBatu - 1, A, C, B, langkah);

    int batu = pop(A);
    push(C, batu);
    cout << langkah << ". Pindahkan batu " << batu << " dari " << A.nama << " ke " << C.nama << endl;
    langkah++;

    pindahkanHanoi(jumlahBatu - 1, B, A, C, langkah);
}

int main() {
    int batu[jumlahBatu] = {10, 20, 30};

    Stack menaraA, menaraB, menaraC;
    menaraHanoi(menaraA, 'A');
    menaraHanoi(menaraB, 'B');
    menaraHanoi(menaraC, 'C');

    for (int i = (jumlahBatu - 1); i >= 0; i--) {
        push(menaraA, batu[i]);
    }

    cout << "\n======= Penyelesaian Menara Hanoi =======\n";
    cout << "Diketahui Menara A memiliki " << jumlahBatu << " batu.\n\n";
    cout << "\tBatu di Menara A:\n";
    for (int i = 0; i < jumlahBatu; i++) {
        cout << "\t\t" << batu[i] << '\n';
    }
    cout << "\nTujuan: Pindahkan semua batu ke Menara C.\n";
    cout << "-----------------------------------------\n";

    cout << ">> Langkah penyelesaian:\n";
    int langkah = 1;
    pindahkanHanoi(jumlahBatu, menaraA, menaraB, menaraC, langkah);
    cout << "-----------------------------------------\n";
    cout << "\tBatu di Menara C:\n";
    for (int i = menaraC.top; i >= 0; i--) {
        cout << "\t\t" << menaraC.batu[i] << '\n';
    }
    cout << " ";
    
    return 0;
}
