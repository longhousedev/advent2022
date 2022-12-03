#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int main(){

    // List containing how many calories each elf is carrying
    std::vector<int> elves;

    int current_cals = 0;
    int total_cals = 0;
    std::string line;

    std::fstream fs ("input.txt", std::fstream::in);

    if (fs.is_open()) {
        while(std::getline(fs, line)) {

            //There is a space, new elf
            if (line == "") {

                elves.push_back(current_cals);
                current_cals = 0;
            }
            // Count calories
            else {
                current_cals += stoi(line);
            }
        }

        std::sort(elves.begin(), elves.end());

        for (std::vector<int>::iterator it=elves.end(); it > elves.end()-4; it--) {
            std::cout << *it << "\n";
            total_cals += *it;
        }

        std::cout << "The three elves are carrying " << total_cals << " calories.";
        fs.close();
        return 0;
    }
}