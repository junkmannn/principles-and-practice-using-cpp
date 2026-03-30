#include <iostream>
#include <vector>
#include <random>

int main() {
    const int num_dice_at_start = 5;
    const int num_faces_on_die = 6;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> dis(1, num_faces_on_die);

    std::vector<int> trials;
    const int num_trials = 1000000;

    for (int i = 0; i < num_trials; ++i) {
        int num_throws = 0;
        int num_dice_available = num_dice_at_start;

        while (true) {
            ++num_throws;
    
            int num_dice_available_cpy = num_dice_available;
            for (int i = 0; i < num_dice_available_cpy; ++i) {
                if (dis(rng) == num_faces_on_die)
                    --num_dice_available;
            }

            if (num_dice_available == 0) {
                trials.push_back(num_throws);
                break;
            }
        }
    }

    double mean = 0;
    for (int i = 0; i < trials.size(); ++i)
        mean += trials[i];
    mean /= trials.size();

    std::cout << mean << '\n';

    return 0;
}
