#include "020_inheritance.h"

string SpellJournal::journal = "";


unsigned int longest_substring(string first, string second);

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Fireball* fireball = dynamic_cast<Fireball*> (spell);
    if (fireball != NULL) {
        return fireball->revealFirepower();
    }

    Frostbite* frostbite = dynamic_cast<Frostbite*> (spell);
    if (frostbite != NULL) {
        return frostbite->revealFrostpower();
    }

    Thunderstorm* thunderstorm = dynamic_cast<Thunderstorm*> (spell);
    if (thunderstorm != NULL) {
        return thunderstorm->revealThunderpower();
    }

    Waterbolt* waterbolt = dynamic_cast<Waterbolt*> (spell);
    if (waterbolt != NULL) {
        return waterbolt->revealWaterpower();
    }

    cout << longest_substring(spell->revealScrollName(), SpellJournal::journal) << endl;

}

unsigned int longest_substring(const string first, const string second) {
    vector<vector<unsigned int>> matrix(second.length() + 1);
    for (int i = 0; i < second.length() + 1; ++i) {
        matrix[i].resize(first.length() + 1);
    }
    for (int i = 1; i < second.length() + 1; i++) {
        for (int j = 1; j < first.length() + 1; ++j) {
            matrix[i][j] = second[i-1] == first[j-1] ? matrix[i-1][j-1] + 1 : max(matrix[i][j-1], matrix[i-1][j]);
        }
    }

    return matrix[second.length()][first.length()];
}


