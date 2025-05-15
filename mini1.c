#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SEATS 30
#define MAX_NAME_LENGTH 50

struct Booking
{
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];

};

struct Booking bookings[MAX_SEATS];
int bookedSeats = 0;

void bookSeat(){
    if (bookedSeats >= MAX_SEATS){
        printf("No more seats avalible");
        return;
    }

    struct Booking newBooking;

    printf("Enter name:");
    scanf("%s",newBooking.name);

    printf("Enter seat number:");
    scanf("%d",&newBooking.seatNo);

    printf("Enter source:");
    scanf("%s",&newBooking.source);

    printf("Enter destination:");
    scanf("%s",&newBooking.destination);

    bookings[bookedSeats++] = newBooking;
    printf("\nSeat booked successfully.\n");
}
