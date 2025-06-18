#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>
#include <cstdint>

namespace RANDOM{

    inline std::mt19937 generate(){
        //Generate random number through seeding Marsenne-Twister 
        //seed based on device random and system time

        std::random_device rd{};
        std::int64_t rt{std::chrono::steady_clock::now().time_since_epoch().count()};

        //create seed based on time and random device
        std::seed_seq ss{static_cast<std::mt19937::result_type>(rt), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

        //return PRNG MT number based on seed:
        return std::mt19937{ss};

    }

    //global variable holding seeded random number
    inline std::mt19937 mt_random{generate()};

    inline int in_range(int lb, int ub){
        //return random number in range
        return std::uniform_int_distribution{lb, ub}(mt_random);

    }


}

#endif