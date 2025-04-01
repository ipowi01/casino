#include <iostream>
#include <random>
using namespace std;

long long penz = 1000;
bool uccu;
void win(){
    cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$      /$$ /$$$$$$ /$$   /$$\n"
            "|  $$   /$$//$$__  $$| $$  | $$      | $$  /$ | $$|_  $$_/| $$$ | $$\n"
            " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$ /$$$| $$  | $$  | $$$$| $$\n"
            "  \\  $$$$/ | $$  | $$| $$  | $$      | $$/$$ $$ $$  | $$  | $$ $$ $$\n"
            "   \\  $$/  | $$  | $$| $$  | $$      | $$$$_  $$$$  | $$  | $$  $$$$\n"
            "    | $$   | $$  | $$| $$  | $$      | $$$/ \\  $$$  | $$  | $$\\  $$$\n"
            "    | $$   |  $$$$$$/|  $$$$$$/      | $$/   \\  $$ /$$$$$$| $$ \\  $$\n"
            "    |__/    \\______/  \\______/       |__/     \\__/|______/|__/  \\__/" << endl;
}
void lose(){
    cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$        /$$$$$$   /$$$$$$  /$$$$$$$$\n"
            "|  $$   /$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$__  $$| $$_____/\n"
            " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$      | $$  \\ $$| $$  \\__/| $$      \n"
            "  \\  $$$$/ | $$  | $$| $$  | $$      | $$      | $$  | $$|  $$$$$$ | $$$$$   \n"
            "   \\  $$/  | $$  | $$| $$  | $$      | $$      | $$  | $$ \\____  $$| $$__/   \n"
            "    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \\ $$| $$      \n"
            "    | $$   |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/| $$$$$$$$\n"
            "    |__/    \\______/  \\______/       |________/ \\______/  \\______/ |________/" << endl;
}
int szamcsinalo(int tartegy, int tartketto) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(tartegy, tartketto);
    int veletlen = dist(gen);
    return veletlen;
}

bool ujra() {
    cout << "akarsz még játszani? (0-1)" << endl;
    cin >> uccu;
    return (uccu == 1);
}

int main() {
    int tartegy, tartketto, veletlen;
    short jatek, tipp;
    bool jatszani = true;
    long bet;

    cout << "  /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$ \n"
            " /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/| $$$ | $$ /$$__  $$\n"
            "| $$  \\__/| $$  \\ $$| $$  \\__/  | $$  | $$$$| $$| $$  \\ $$\n"
            "| $$      | $$$$$$$$|  $$$$$$   | $$  | $$ $$ $$| $$  | $$\n"
            "| $$      | $$__  $$ \\____  $$  | $$  | $$  $$$$| $$  | $$\n"
            "| $$    $$| $$  | $$ /$$  \\ $$  | $$  | $$\\  $$$| $$  | $$\n"
            "|  $$$$$$/| $$  | $$|  $$$$$$/ /$$$$$$| $$ \\  $$|  $$$$$$/\n"
            "\\______/ |__/  |__/ \\______/ |______/|__/  \\__/ \\______/ " << endl;

    while (jatszani) {
        cout << "Pénz = " << penz << endl;
        cout << "Mivel szeretnél játszani?\n 1 = guess the number\n2 = blackjack" << endl;
        cin >> jatek;

       switch (jatek) {
           case 1:
               int szorzo;
               cout << "intervallum alsó határa" << endl;
               cin >> tartegy;
               cout << "intervallum felső határa" << endl;
               cin >> tartketto;
               if (tartketto - tartegy != 0) {
                   szorzo = tartketto - tartegy + 1;
               } else {
                   szorzo = 0;
               }
               cout << "tippelj egy számot" << endl;
               cin >> tipp;
               cout << "Tét?" << endl;
               cin >> bet;

               if (tipp > tartketto || tipp < tartegy) {
                   cout << "KYS NIGGER" << endl;
                   continue;
               }

               veletlen = szamcsinalo(tartegy, tartketto);

               if (veletlen == tipp) {
                   win();
                   penz += bet * szorzo;
               } else {
                   lose();
                   penz -= bet;
               }
               cout << penz << " ennyid maradt csoro cigany" << endl;
               jatszani = ujra();

           case 2:
               short bj_sump = 0, bj_sumh = 0, a, b;
               bool hit = true;
               bool choice;

               cout << "Tét?" << endl;
               cin >> bet;

               bj_sump += szamcsinalo(1, 11); // ász 11
               bj_sump += szamcsinalo(1, 10);
               a = szamcsinalo(1, 11);
               b = szamcsinalo(1, 10);
               bj_sumh = a + b;
               cout << "Te: " << bj_sump << endl;
               cout << "Huzz: " << a << " + ?" << endl;

               while (hit && bj_sump < 21) {
                   cout << "Akarsz lapot? (0-1)" << endl;
                   cin >> choice;
                   if (choice == 1) {
                       bj_sump += szamcsinalo(1, 11);
                       cout << "Te: " << bj_sump << endl;
                       if (bj_sump > 21) {
                           lose();
                           penz -= bet;
                           hit = false;
                       }
                   } else {
                       hit = false;
                   }
               }

               if (bj_sump <= 21) {
                   while (bj_sumh < 17) {
                       bj_sumh += szamcsinalo(1, 11);
                   }
                   cout << "Huzz: " << bj_sumh << endl;

                   if (bj_sumh > 21 || bj_sump > bj_sumh) {
                       win();
                       penz += bet;
                   } else if (bj_sump == bj_sumh) {
                       cout << "Döntetlen" << endl;
                   } else {
                       lose();
                       penz -= bet;
                   }
               }
           case 3:
               


        }
        cout << "Egyenleg: " << penz << endl;
        jatszani = ujra();
    }

    cout << penz << "-al távoztál a kaszinóból" << endl;
    return 0;
}