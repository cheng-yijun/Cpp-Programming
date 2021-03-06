#include <iostream>
#include "SpellChecker.h"
#include "WordCounts.h"
using namespace std;

int main(int argc, char const *argv[]) {

    string lang = "English";
    SpellChecker speller = SpellChecker(lang, "VALID_WORDS_3000.txt", "MISSPELLED.txt");

    cout << "\nrunning test case I" << endl;
    cout << speller.fixUp("todayy") << endl;
    cout << speller.fixUp("abouy todayy") << endl;
    cout << speller.fixUp("tod!ay") << endl;
    cout << speller.fixUp("!today!") << endl;
    cout << speller.fixUp("today!") << endl;
    cout << speller.fixUp("!abouy todayy!") << endl;
    cout << speller.fixUp("todayy, is teh day!") << endl;
    cout << speller.fixUp("ahsjdklfha") << endl;
    cout << speller.fixUp("tomor is another day!") << endl;
    cout << speller.fixUp("Teh brown asdhf jumped.") << endl;
    cout << speller.fixUp("aeap") << endl;

    cout << "\nRunning test case II" << endl;
    static const int SIZE = 10000;
    string words[SIZE];
    int counts[SIZE];
    string s;
    WordCounts wc = WordCounts();
    wc.resetCounts();
    wc.countWords("the the brown fox.");
    wc.countWords("The red fox.");
    wc.countWords("teh blue cat.");

    cout << wc.getCount("the") << endl;
    cout << wc.mostCommon(words, counts, 5) << endl;

    for(int i = 0; i < 10; i++) {
        cout << words[i] << ": " << counts[i] << endl;

    }

    return 0;
}
