#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <regex>

class WebResource {
    private:
        static std::uint_least16_t id = 0;
        std::uint_least16_t adress;
        std::string *information;
        double ranking;

    public:
        WebResource (std::string information) {
            this->adress = id++;
            this->information = new std::string(information);
            this->ranking = 0.0;
        }

        WebResource () {
            this->adress = id++;
            this->information = new std::string;
            this->ranking = 0.0;
        }

        void setInformation(std::string information) {
            *(this->information) = information;
        }

        ~WebResource() {
            delete this->information;
        }

        void calculateRanking(int seed) {
            srand(seed);
            this->ranking = rand() % 101 / 10; //creates a random value between 0.0 and 10.0
        }
};

class System {
    private:
        std::string last_query;
        int outputs;
        int searches;
        WebResource res[100];
        int num_pages;
    
    public:
        System () : last_query(""), outputs(1), searches(0), num_pages(0) {};



        void displayInfo() {
            using namespace std;
            cout << "     Search Engine Version 1.1\n";
            cout << "-----------------------------------\n";
            cout << "Last Search: " << this->last_query << endl;
            cout << "Searches done: " << this->searches << endl;
            cout << "Stored Pages: " << this->num_pages << endl;
        }

        std::string searchWeb(std::string query) {
            
            std::regex pattern("(\\d+)");
            std::smatch matches;

            while (std::regex_search(query, matches, pattern)) {
                std::cout << "Found integer: " << matches.str() << std::endl;
                query = matches.suffix().str();
            }
}

        }
};


#endif