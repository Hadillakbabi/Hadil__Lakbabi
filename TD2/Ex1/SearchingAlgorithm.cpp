#include "SearchingAlgorithm.h"

long int SearchingAlgorithm::totalComparisons = 0;
long int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparaisons = 0;
}

void SearchingAlgorithm::displaySearchResults(ostream& os, int result, int target) {
    
    totalComparisons += numberComparaisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    os << "Target : " << target << endl;
    os << "Indice : " << result << endl;
    os << "Comparaisons pour cette recherche : " << numberComparaisons << endl;
    os << "Total comparaisons : " << totalComparisons << endl;
    os << "Moyenne comparaisons : " << averageComparisons << endl;
}