#ifndef _NAME_PAIRS_H_
#define _NAME_PAIRS_H_

#include <string>
#include <vector>

namespace record
{
    class Name_pairs
    {
        public:
            void read_names(void); // modifying member functions
            void read_ages(void);
            void sort(void);

            int get_idx(const std::string& s) const; // non-modifying member functions 
            void print(void) const; 
            const std::vector<std::string>& get_names(void) const { return names; };
            const std::vector<int>& get_ages(void) const { return ages; };
            size_t size(void) const { return names.size(); }; // returns number of items in vector

        private:
            std::vector<std::string> names; // vectors are default-initialized as empty 
            std::vector<int> ages;
    };

    std::ostream& operator<<(std::ostream& os, const Name_pairs& np);

    bool operator==(const Name_pairs& np1, const Name_pairs& np2);

    bool operator!=(const Name_pairs& np1, const Name_pairs& np2);
}

#endif 