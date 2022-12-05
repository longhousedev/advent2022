#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <set>


int main() {
    std::fstream fs ("input.txt", std::fstream::in);
    std::string line;
    std::vector<std::string> split_vector;
    int score = 0;
    int intersects = 0;


    if (fs.is_open()) {
        while(std::getline(fs, line)) {

            std::set<int> set1;
            std::set<int> set2;
            std::set<int> intersect_set;

            //Split line into 4 numbers
            boost::algorithm::split(split_vector, line, boost::algorithm::is_any_of("-,"));

            //Create sets from these 4 numbers
            for (int i = stoi(split_vector[0]); i <= stoi(split_vector[1]); i++) set1.insert(i);
            for (int i = stoi(split_vector[2]); i <= stoi(split_vector[3]); i++) set2.insert(i);

            // Check for subsets
            if (std::includes(set1.begin(), set1.end(), set2.begin(), set2.end()) || 
                std::includes(set2.begin(), set2.end(), set1.begin(), set1.end())) score += 1;

            // Check for intersects
            std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                            std::inserter(intersect_set, intersect_set.begin()));
            if (intersect_set.size() > 0) intersects += 1;
        }
        fs.close();
    }
    std::cout << "Number of subsets: " << score << "\n";
    std::cout << "Number of intersecting pairs: " << intersects << "\n";
    return 0;
}