#include <stdio.h>
#include <string.h>
#include "mini4.h"  // optional: if you're using header files

#define MAX_SEATS 30
#define MAX_NAME_LENGTH 50

// Structure for booking information
struct Booking {
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
};

// Array to store bookings
struct Booking bookings[MAX_SEATS];
// Counter to keep track of how many seats are booked
int bookedSeats = 0;

// Function to check if a seat is already booked
int isSeatBooked(int seatNo) {
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatNo)
            return 1;
    }
    return 0;
}

// Clear input buffer (to handle stray newlines)
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
