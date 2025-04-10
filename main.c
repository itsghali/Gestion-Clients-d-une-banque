#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTS 100
#define MAX_COMPTES 100
struct Client {
    int id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    char num_tel[20];
};

struct Compte {
    int id_compte;
    int id_client;
    float solde;
    char date_ouverture[20];
};

struct Client clients[MAX_CLIENTS];
struct Compte comptes[MAX_COMPTES];
int numClients = 0;
int numComptes = 0;

void ajouterClient() {
    if (numClients >= MAX_CLIENTS) {
        printf("Le gestionnaire de clients est plein.\n");
        return;
    }

    struct Client newClient;

    printf("ID du client: ");
    scanf("%d", &newClient.id_client);
    getchar(); // Pour consommer le caractère de nouvelle ligne restant

    printf("Nom: ");
    fgets(newClient.nom, sizeof(newClient.nom), stdin);
    newClient.nom[strcspn(newClient.nom, "\n")] = '\0';

    printf("Prénom: ");
    fgets(newClient.prenom, sizeof(newClient.prenom), stdin);
    newClient.prenom[strcspn(newClient.prenom, "\n")] = '\0';

    printf("Profession: ");
    fgets(newClient.profession, sizeof(newClient.profession), stdin);
    newClient.profession[strcspn(newClient.profession, "\n")] = '\0';

    printf("Numéro de téléphone: ");
    fgets(newClient.num_tel, sizeof(newClient.num_tel), stdin);
    newClient.num_tel[strcspn(newClient.num_tel, "\n")] = '\0';

    clients[numClients++] = newClient;

    printf("Client ajouté avec succès.\n");
}

void modifierClient() {
    int id;
    printf("ID du client à modifier: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < numClients; i++) {
        if (clients[i].id_client == id) {
            printf("Nouveau nom: ");
            fgets(clients[i].nom, sizeof(clients[i].nom), stdin);
            clients[i].nom[strcspn(clients[i].nom, "\n")] = '\0';

            printf("Nouveau prénom: ");
            fgets(clients[i].prenom, sizeof(clients[i].prenom), stdin);
            clients[i].prenom[strcspn(clients[i].prenom, "\n")] = '\0';

            printf("Nouvelle profession: ");
            fgets(clients[i].profession, sizeof(clients[i].profession), stdin);
            clients[i].profession[strcspn(clients[i].profession, "\n")] = '\0';

            printf("Nouveau numéro de téléphone: ");
            fgets(clients[i].num_tel, sizeof(clients[i].num_tel), stdin);
            clients[i].num_tel[strcspn(clients[i].num_tel, "\n")] = '\0';

            printf("Client modifié avec succès.\n");
            return;
        }
    }

    printf("Aucun client trouvé avec l'ID donné.\n");
}

void supprimerClient() {
    int id;
    printf("ID du client à supprimer: ");
    scanf("%d", &id);
    getchar();

for (int i = 0; i < numClients; i++) {
        if (clients[i].id_client == id) {
            // Décaler les clients suivants vers l'index précédent
            for (int j = i; j < numClients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            numClients--;
            printf("Client supprimé avec succès.\n");
            return;
        }
    }

    printf("Aucun client trouvé avec l'ID donné.\n");
}

void rechercherClient() {
    int choix;
    printf("1. Rechercher par ID\n");
    printf("2. Rechercher par nom\n");
    printf("3. Retour\n");
    printf("Choix: ");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
        case 1: {
            int id;
            printf("ID du client à rechercher: ");
            scanf("%d", &id);
            getchar();

            for (int i = 0; i < numClients; i++) {
                if (clients[i].id_client == id) {
                    printf("Client trouvé:\n");
                    printf("ID: %d\n", clients[i].id_client);
                    printf("Nom: %s\n", clients[i].nom);
                    printf("Prénom: %s\n", clients[i].prenom);
                    printf("Profession: %s\n", clients[i].profession);
                    printf("Numéro de téléphone: %s\n", clients[i].num_tel);
                    return;
                }
            }

            printf("Aucun client trouvé avec l'ID donné.\n");
            break;
        }
        case 2: {
            char nom[50];
            printf("Nom du client à rechercher: ");
            fgets(nom, sizeof(nom), stdin);
            nom[strcspn(nom, "\n")] = '\0';

            for (int i = 0; i < numClients; i++) {
                if (strcmp(clients[i].nom, nom) == 0) {
                    printf("Client trouvé:\n");
                    printf("ID: %d\n", clients[i].id_client);
                    printf("Nom: %s\n", clients[i].nom);
                    printf("Prénom: %s\n", clients[i].prenom);
                    printf("Profession: %s\n", clients[i].profession);
                    printf("Numéro de téléphone: %s\n", clients[i].num_tel);
                    return;
                }
            }

            printf("Aucun client trouvé avec le nom donné.\n");
            break;
        }
        case 3:
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
    }
}

void menuGestionClients() {
    int choix;

    do {
        printf("\nMENU GESTION DES CLIENTS\n");
        printf("1. Ajouter un client\n");
        printf("2. Modifier un client\n");
        printf("3. Supprimer un client\n");
        printf("4. Rechercher un client\n");
        printf("5. MENU GENERAL\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                ajouterClient();
                break;
            case 2:
                modifierClient();
                break;
            case 3:
                supprimerClient();
                break;
            case 4:
                rechercherClient();
                break;
            case 5:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);
}

void nouveauCompte() {
    if (numComptes >= MAX_COMPTES) {
        printf("Le gestionnaire de comptes est plein.\n");
        return;
    }

    struct Compte newCompte;

    printf("ID du compte: ");
    scanf("%d", &newCompte.id_compte);
    getchar();

    printf("ID du client associé: ");
    scanf("%d", &newCompte.id_client);
    getchar();

    printf("Solde de base: ");
    scanf("%f", &newCompte.solde);
    getchar();

    printf("Date d'ouverture: ");
    fgets(newCompte.date_ouverture, sizeof(newCompte.date_ouverture), stdin);
    newCompte.date_ouverture[strcspn(newCompte.date_ouverture, "\n")] = '\0';

    comptes[numComptes++] = newCompte;

    printf("Nouveau compte ajouté avec succès.\n");
}

void consultationCompte() {
    int id;
    printf("ID du compte à consulter: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < numComptes; i++) {
        if (comptes[i].id_compte == id) {
            printf("Compte trouvé:\n");
            printf("ID du compte: %d\n", comptes[i].id_compte);
            printf("ID du client associé: %d\n", comptes[i].id_client);
            printf("Solde de base: %.2f\n", comptes[i].solde);
            printf("Date d'ouverture: %s\n", comptes[i].date_ouverture);
            return;
        }
    }

    printf("Aucun compte trouvé avec l'ID donné.\n");
}

void fermetureCompte() {
    int id;
    printf("ID du compte à fermer: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < numComptes; i++) {
        if (comptes[i].id_compte == id) {
            // Décaler les comptes suivants vers l'index précédent
            for (int j = i; j < numComptes - 1; j++) {
                comptes[j] = comptes[j + 1];
            }
            numComptes--;
            printf("Compte fermé avec succès.\n");
            return;
        }
    }

    printf("Aucun compte trouvé avec l'ID donné.\n");
}

void menuGestionComptes() {
    int choix;

    do {
        printf("\nMENU GESTION DES COMPTES\n");
        printf("1. Nouveau compte\n");
        printf("2. Consultation d'un compte\n");
        printf("3. Fermeture d'un compte\n");
        printf("4. MENU GENERAL\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                nouveauCompte();
                break;
            case 2:
                consultationCompte();
                break;
            case 3:
                fermetureCompte();
                break;
             case 4:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);
}

void retrait() {
    int id;
    float montant;
    printf("ID du compte: ");
    scanf("%d", &id);
    getchar();

    printf("Montant à retirer: ");
    scanf("%f", &montant);
    getchar();

    for (int i = 0; i < numComptes; i++) {
        if (comptes[i].id_compte == id) {
            if (comptes[i].solde >= montant) {
                comptes[i].solde -= montant;
                printf("Retrait effectué avec succès.\n");
            } else {
                printf("Solde insuffisant.\n");
            }
            return;
        }
    }

    printf("Aucun compte trouvé avec l'ID donné.\n");
}

void virement() {
    int idSource, idDest;
    float montant;
    printf("ID du compte source: ");
    scanf("%d", &idSource);
    getchar();

    printf("ID du compte destinataire: ");
    scanf("%d", &idDest);
    getchar();

    printf("Montant à transférer: ");
    scanf("%f", &montant);
    getchar();

    // Recherche du compte source
    int indexSource = -1;
    for (int i = 0; i < numComptes; i++) {
        if (comptes[i].id_compte == idSource) {
            indexSource = i;
            break;
        }
    }

    // Recherche du compte destinataire
    int indexDest = -1;
    for (int i = 0; i < numComptes; i++) {
        if (comptes[i].id_compte == idDest) {
            indexDest = i;
            break;
        }
    }

    if (indexSource == -1 || indexDest == -1) {
        printf("Compte source ou destinataire non trouvé.\n");
        return;
    }

    if (comptes[indexSource].solde >= montant) {
        comptes[indexSource].solde -= montant;
        comptes[indexDest].solde += montant;
        printf("Virement effectué avec succès.\n");
    } else {
        printf("Solde insuffisant.\n");
    }
}

void menuGestionOperations() {
    int choix;

    do {
        printf("\nMENU GESTION DES OPERATIONS\n");
        printf("1. Retrait\n");
        printf("2. Virement\n");
        printf("3. MENU GENERAL\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                retrait();
                break;
            case 2:
                virement();
                break;
            case 3:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);
}


void menuPrincipal() {
    char choix;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("A. Gestion des clients\n");
        printf("B. Gestion des comptes\n");
        printf("C. Gestion des opérations\n");
        printf("D. Quitter\n");
        printf("Choix: ");
        scanf(" %c", &choix);
        getchar();

        switch (choix) {
            case 'A':
            case 'a':
                menuGestionClients();
                break;
            case 'B':
            case 'b':
                menuGestionComptes();
                break;
            case 'C':
            case 'c':
                menuGestionOperations();
                break;
            case 'D':
            case 'd':
                printf("Merci d'avoir utilisé le programme. Au revoir !\n");
                return;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 'D' && choix != 'd');
}

int main() {
    menuPrincipal();
    return 0;
}
