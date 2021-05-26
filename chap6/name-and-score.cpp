#include <iostream>
#include <vector>
#include <string>


class Record{
    public:
        std::string name;
        int value;
        Record(std::string n, int v = 0): name(n), value(v) {}

};

/**
 * Q4. Demonstrates storage of name-score pairs inside vector of type Record. 
 *     No duplicate names allowed. 
 */
int main(){

    std::string name;
    int score;
    std::vector<Record> records; 

    std::cout << "Please enter name-score pairs.\n";

    while(std::cin >> name >> score){
        bool duplicate = false;

        for(int i = 0; i < records.size(); i++){
            if(records[i].name == name)
                duplicate = true;
        }

        if(duplicate)
            std::cout << "Entered duplicate\n";
        else
            records.push_back(Record(name, score));
    }

    for(int i = 0; i < records.size(); i++)
        std::cout << records[i].name << ' ' << records[i].value << '\n';

    return 0;
}