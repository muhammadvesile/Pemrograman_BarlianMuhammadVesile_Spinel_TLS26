#include <iostream>

int main() {
    int N, K;

    std::cout << "Berapa banyak astronot (N): ";
    std::cin >> N;

    std::cout << "Interval (K): ";
    std::cin >> K;
 
    if (N <= 0) return 0;

    int* astronauts = new int[N];
    for (int i = 0; i < N; ++i) {
        astronauts[i] = i + 1;
    }

    int remaining = N;
    int current_index = 0;

    std::cout << "Urutan eliminasi: ";

    while (remaining > 1) {
        int elim_index = (current_index + K - 1) % remaining;
        int eliminated_id = astronauts[elim_index];

        std::cout << eliminated_id << (remaining > 2 ? " " : "");

        if (eliminated_id % 2 == 0) {
            K += 2; 
        } else {
            K -= 1; 
        }
        if (K < 2) {
            K = 2;
        }

        for (int i = elim_index; i < remaining - 1; ++i) {
            astronauts[i] = astronauts[i + 1];
        }

        remaining--;
        current_index = elim_index % remaining;
    }

    std::cout << "\nAstronot yang terakhir bertahan: " << astronauts[0] << std::endl;

    delete[] astronauts;
    return 0;
}