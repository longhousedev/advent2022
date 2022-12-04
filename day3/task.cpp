#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include <set>
#include <algorithm>

// Converts characters in a set to their score value provided
int set_to_score(std::set<char> set) {

    int upper_mod = 38;
    int lower_mod = 96;
    int score = 0;

    for (auto c : set) {
        if (isupper(c)) score += c - upper_mod;
        else if (islower(c)) score += c - lower_mod;
    }

    return score;
}

int task1() {

    std::fstream fs ("input.txt", std::fstream::in);
    std::string line;
    std::string compartment_1;
    std::string compartment_2;
    int final_score = 0;

    if (fs.is_open()) {
        while(std::getline(fs, line)) {

            int line_score = 0;

            // Get two compartments
            int midpoint = line.length() / 2;
            compartment_1 = line.substr(0, midpoint);
            compartment_2 = line.substr(midpoint, line.length() - midpoint);

            // Get common letters
            std::set<char> compartment_1_set(std::begin(compartment_1), std::end(compartment_1));
            std::set<char> compartment_2_set(std::begin(compartment_2), std::end(compartment_2));
            std::set<char> intersect;

            std::set_intersection(compartment_1_set.begin(), compartment_1_set.end(),
                                    compartment_2_set.begin(), compartment_2_set.end(),
                                    std::inserter(intersect, intersect.begin()));
            // Get score
            final_score += set_to_score(intersect);
        }
        fs.close();
    }
    return final_score;
}

int task2() {

    std::fstream fs ("input.txt", std::fstream::in);
    std::string line;
    int final_score = 0;
    std::string elves[3];

    if (fs.is_open()) {

        int count = 0;
        while(std::getline(fs, line)) {

            // Get elves into groups
            count += 1;
            if (count == 1) elves[0] = line;
            else if (count == 2) elves[1] = line;
            else if (count == 3) {

                elves[2] = line;
                std::set<char> sets[3];
                std::set<char> intersects[2];
                sets[0] = std::set<char>(std::begin(elves[0]), std::end(elves[0]));
                sets[1] = std::set<char>(std::begin(elves[1]), std::end(elves[1]));
                sets[2] = std::set<char>(std::begin(elves[2]), std::end(elves[2]));

                // Get common letters of three sets
                std::set_intersection(sets[0].begin(), sets[0].end(),
                        sets[1].begin(), sets[1].end(),
                        std::inserter(intersects[0], intersects[0].begin()));
                
                std::set_intersection(sets[2].begin(), sets[2].end(),
                        intersects[0].begin(), intersects[0].end(),
                        std::inserter(intersects[1], intersects[1].begin()));
                final_score += set_to_score(intersects[1]);

                count = 0;
            }
        }
        fs.close();
    }
    return final_score;
}

int main() {

    std::cout << "Score for task 1: " << task1() << "\n";
    std::cout << "Score for task 2: " << task2() << "\n";
}