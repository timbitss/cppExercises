#include "include/Name_pairs.h"
#include <iostream>
#include <algorithm>

namespace record
{

/**
 * @brief Reads series of names 
 */
void Name_pairs::read_names(void)
{
    std::string s; 
    int count = 0;
    std::cout << "Enter names separated by whitespace.\n"
              << "Enter 'q' to save and quit.\n";

    while(std::cin >> s && s != "q")
    {
        names.push_back(s);
        count++;
    }

    std::cout << count << " names have been entered\n"; 
}


/**
 * @brief Prompts user for an age for each name.
 * 
 * @pre Names vector must have at least one name
 */
void Name_pairs::read_ages(void)
{
    if (names.empty()) throw std::runtime_error("Names vector is empty");
    int age;

    for(auto name : names)
    {
        std::cout << "Enter " << name << "'s age: ";
        if(std::cin >> age && age > 0)
            ages.push_back(age);
        else
            throw std::runtime_error("Invalid age.");
    }

    std::cout << "All ages have been entered.\n";
}

/**
 * @brief Get index corresponding to name
 * 
 * @param s name to search for
 * @return int index of name
 */
int Name_pairs::get_idx(const std::string& s) const
{
    for(size_t i = 0; i < names.size(); i++)
        if(names[i] == s) return i;

    throw std::runtime_error("Name not found");
}

/**
 * @brief Sorts name by alphabetical order
 * 
 * @pre Vector of names and ages must be non-empty
 */
void Name_pairs::sort(void)
{
    if (names.empty() || ages.empty()) throw std::runtime_error("Empty vectors");

    std::vector<std::string> copy_names{names}; 
    std::vector<int> copy_ages;
    std::sort(copy_names.begin(), copy_names.end());

    for(size_t i = 0; i < copy_names.size(); i++){
        copy_ages.push_back(ages[ get_idx(copy_names[i]) ]);
    }

    // copy it back
    ages = copy_ages;
    names = copy_names;
}

/**
 * @brief Prints out all name and age pairs (one per line)
 * 
 */
void Name_pairs::print(void) const
{
    if (names.empty()) std::cout << "No names.\n";
    else
    {
        for (size_t i = 0; i < names.size(); i++)
            std::cout << names[i] << ' ' << ages[i] << '\n'; 
    }
}


std::ostream& operator<<(std::ostream& os, const Name_pairs& np)
{
    const std::vector<std::string>& names = np.get_names();
    const std::vector<int>& ages = np.get_ages();

    for(size_t i = 0; i < names.size(); i++)
        os << names[i] << ' ' << ages[i] << "\n";

    return os;
}

bool operator==(const Name_pairs& np1, const Name_pairs& np2)
{
    if(np1.size() != np2.size())
        return false;

    for(size_t i = 0; i < np1.size(); i++)
        if(np1.get_names()[i] != np2.get_names()[i] || np1.get_ages()[i] != np2.get_ages()[i])
            return false;

    return true;
}

bool operator!=(const Name_pairs& np1, const Name_pairs& np2)
{
    return !(np1 == np2);
}


}