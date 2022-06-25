#include "list.hpp"

int main () {
    size_t t;
    t = clock();
    tf_idf();
    t = clock() - t;

    std::cout << "\nTempo total: " << float(t)/CLOCKS_PER_SEC << std::endl << std::endl;
}