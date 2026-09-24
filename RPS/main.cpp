#include <iostream>
#include <random>

using namespace std;

int main() {
    // déclaration des variables :
    string jouable[3] = {"feuille","pierre","ciseaux"};
    int choix; 
    int choixOrdi;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);

    // choix du joueur 

    cout << "Entrez un nombre (1: feuille, 2: pierre, 3 ciseaux): ";
    cin >> choix;
    while (choix < 1 || choix >3){
        cout << "Veuillez entrer un nombre entre 1 et 3 ";
        cin >> choix;
    }
    cout << "Vous avez choisi " << jouable[choix-1] << "\n";
    
    // choix de l'ordi

    cout << "choix du robot : ";
    choixOrdi = dist(gen);
    cout << jouable[choixOrdi -1] << "\n";

    //  en cas d'égalité :

    while (choixOrdi == choix){
        cout << "Egalite ! \n";
        cout << "Entrez un nombre (1: feuille, 2: pierre, 3 ciseaux): ";
        cin >> choix;
        while (choix < 1 || choix >3){
            cout << "Veuillez entrer un nombre entre 1 et 3 :";
            cin >> choix;
        }
        cout << "Vous avez choisis " << jouable[choix-1] << "\n";
        cout << "choix du robot : ";
        choixOrdi = dist(gen);
        cout << jouable[choixOrdi -1] << "\n";
    }
    // verification du gagnant :
    if ((choix==1 and choixOrdi ==2) || (choix==2 and choixOrdi ==3) || (choix==3 and choixOrdi ==1)){
        cout << "Le joueur a gagne !";
    }
    else{
        cout << "L'ordi a gagne !";
    }
    return 0;
}