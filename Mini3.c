void printTicket() {
    int seatToPrint;
    printf("Enter seat number to print ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatToPrint) {
            printf("\n---------- TICKET ----------\n");
            printf("Seat No.             : %d\n", bookings[i].seatNo);
            printf("Passenger Name       : %s\n", bookings[i].name);
            printf("Source               : %s\n", bookings[i].source);
            printf("Destination          : %s\n", bookings[i].destination);
            printf("-----------------------------\n\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n=== Train Seat Booking System ===\n");
        printf("1. Book a Seat\n");
        printf("2. View Reservations\n");
        printf("3. Edit a Reservation\n");
        printf("4. Print a Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                viewReservation();
                break;
            case 3:
                editReservation();
                break;
            case 4:
                printTicket();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
