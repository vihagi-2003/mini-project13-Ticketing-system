// Book a seat

void bookSeat() {
    if (bookedSeats >= MAX_SEATS) {
        printf("No more seats available.\n");

        return;
    }

    struct Booking newBooking;

    printf("Enter name: ");
    clearInputBuffer();
    fgets(newBooking.name, MAX_NAME_LENGTH, stdin);
    newBooking.name[strcspn(newBooking.name, "\n")] = '\0'; // Remove newline

    do {

        printf("Enter seat number: ");
        scanf("%d", &newBooking.seatNo);

        if (isSeatBooked(newBooking.seatNo)) {
            printf("This seat is already booked. Please choose another seat.\n");
        }
    } while (isSeatBooked(newBooking.seatNo));

    printf("Enter source: ");
    clearInputBuffer();
    fgets(newBooking.source, MAX_NAME_LENGTH, stdin);
    newBooking.source[strcspn(newBooking.source, "\n")] = '\0';

    printf("Enter destination: ");
    fgets(newBooking.destination, MAX_NAME_LENGTH, stdin);
    newBooking.destination[strcspn(newBooking.destination, "\n")] = '\0';


    bookings[bookedSeats++] = newBooking;
    printf("\nSeat booked successfully.\n");
}

// View all reservations
void viewReservation() {
    if (bookedSeats == 0) {
        printf("No reservations made yet.\n");
        return;
    }

    printf("\nAll Reservations:\n");

    printf("---------------------------------------\n");

    for (int i = 0; i < bookedSeats; ++i) {
        printf("Seat No.       : %d\n", bookings[i].seatNo);
        printf("Name           : %s\n", bookings[i].name);
        printf("Source         : %s\n", bookings[i].source);
        printf("Destination    : %s\n", bookings[i].destination);
        printf("---------------------------------------\n");
    }
}

// Edit an existing reservation
void editReservation() {
    int seatToEdit;
    printf("Enter seat number to be edited: ");
    scanf("%d", &seatToEdit);


    int found = 0;
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatToEdit) {
            printf("Enter new name: ");
            clearInputBuffer();
            fgets(bookings[i].name, MAX_NAME_LENGTH, stdin);
            bookings[i].name[strcspn(bookings[i].name, "\n")] = '\0';

            printf("Enter new source: ");
            fgets(bookings[i].source, MAX_NAME_LENGTH, stdin);
            bookings[i].source[strcspn(bookings[i].source, "\n")] = '\0';

            printf("Enter new destination: ");
            fgets(bookings[i].destination, MAX_NAME_LENGTH, stdin);
            bookings[i].destination[strcspn(bookings[i].destination, "\n")] = '\0';


            printf("Reservation edited successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

// Print a ticket

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

// Main menu

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
