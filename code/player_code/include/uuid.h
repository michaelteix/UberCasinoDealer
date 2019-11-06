//
//  uuid.h
//  Blackjack Game; Dealer
//
// Generates a unique user identifier using boost libraries
//

#ifndef uuid_h
#define uuid_h

// derived from uuid.cpp file provided by instructor
// from stack overflow
// http://stackoverflow.com/questions/3247861/example-of-uuid-generation-using-boost-in-c
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <iostream>

typedef boost::uuids::uuid UID;
UID new_uuid() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    return uuid;
}

#endif /* uuid_h */
