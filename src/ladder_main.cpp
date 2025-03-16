#include "ladder.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    cout << (is_adjacent("tom", "tam") ? "true" : "false") << endl; // T
    cout << (is_adjacent("bam", "bar") ? "true" : "false") << endl; // T

    cout << (is_adjacent("mar", "mov") ? "true" : "false") << endl; // F
    cout << (is_adjacent("dav", "vad") ? "true" : "false") << endl; // F

    // left < right
    cout << (is_adjacent("ray", "raye") ? "true" : "false") << endl; // T
    cout << (is_adjacent("tar", "taar") ? "true" : "false") << endl; // T

    cout << (is_adjacent("rov", "rooe") ? "true" : "false") << endl; // F
    cout << (is_adjacent("had", "paad") ? "true" : "false") << endl; // F


    // left > right
    cout << (is_adjacent("park", "par") ? "true" : "false") << endl; // T
    cout << (is_adjacent("more", "ore") ? "true" : "false") << endl; // T

    cout << (is_adjacent("tera", "tar") ? "true" : "false") << endl; // F
    cout << (is_adjacent("moat", "mam") ? "true" : "false") << endl; // F


    // diff is > 1
    cout << (is_adjacent("mom", "m") ? "true" : "false") << endl; // F
    cout << (is_adjacent("dad", "daddd") ? "true" : "false") << endl; // F

    print_word_ladder({});

}
