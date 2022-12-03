#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

// Part 1
int get_score(std::string p1_move, std::string p2_move) {

    int score = 0;

    //Get score of move
    if (p2_move == "X") score += 1;
    else if (p2_move == "Y") score += 2;
    else if (p2_move == "Z") score += 3;

    // Get score based on round outcome

    // Draw
    if (p1_move == "A" && p2_move == "X") score += 3;
    else if (p1_move == "B" && p2_move == "Y") score += 3;
    else if (p1_move == "C" && p2_move == "Z") score += 3;

    // Win
    if (p1_move == "C" && p2_move == "X") score += 6;
    else if (p1_move == "A" && p2_move == "Y") score += 6;
    else if (p1_move == "B" && p2_move == "Z") score += 6;

    return score;
}

//Part 2
int get_task_2_score(std::string p1_move, std::string desired_end_state) {

    int score = 0;

    // Desired end state and moves required to make it happen

    // Lose
    if (desired_end_state == "X") {

        if (p1_move == "A") score += 3;
        else if (p1_move == "B") score += 1;
        else if (p1_move == "C") score += 2;
    }

    // Draw
    else if(desired_end_state == "Y") {

        score += 3;
        if (p1_move == "A") score += 1;
        else if (p1_move == "B") score += 2;
        else if (p1_move == "C") score += 3;
    }

    // Win
    else if(desired_end_state == "Z") {
        
        score += 6;
        if (p1_move == "A") score += 2;
        else if (p1_move == "B") score += 3;
        else if (p1_move == "C") score += 1;
    }

    return score;
}

int main() {

    std::fstream fs ("input.txt", std::fstream::in);
    std::string line;
    std::vector<std::string> split_vector;
    int final_score = 0;

    if (fs.is_open()) {
        while(std::getline(fs, line)) {

            // Get the two moves
            boost::algorithm::split(split_vector, line, boost::algorithm::is_any_of(" "));

            // Resolve score of move
            
            // Task 1
            //final_score += get_score(split_vector[0], split_vector[1]);

            final_score += get_task_2_score(split_vector[0], split_vector[1]);
        }

        std::cout << "Total score of moves is  " << final_score;
        fs.close();
        return 0;
    }
}