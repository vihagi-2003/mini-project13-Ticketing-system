void viewReservation()
{
    if(bookedSeats == 0)
    {
        printf("No reservations made yet.");
        return;
    }

    printf("\nAll reservations:\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < bookedSeats; ++i)
    {
        printf("Seat No. \t%d \n",bookings[i].seatNo);
        printf("Name: \t\t%s \n", bookings[i].name);
        printf("Source: \t%s \n", bookings[i].source);
        printf("Destination: \t%s \n\n", bookings[i].destination);
    }
}

void editReservation()
{
    int seatToEdit;
    printf("Enter seat number to edited: ");
    scanf("%d",&seatToEdit);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i)
    {
        if (bookings[i].seatNo == seatToEdit)
        {
            printf("Enter new name:");
            scanf("%s",bookings[i].name);

            printf("Enter new Source:");
            scanf("%s",bookings[i].source);

            printf("Enter new Destination:");
            scanf("%s",bookings[i].destination);

            printf("Reservation edited successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Reservation not found.");
    }
}

void printTicket()
{
    int seatToPrint;
    printf("Enter seat number to print ticket:");
    scanf("%d",&seatToPrint);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i)
    {
        if (bookings[i].seatNo == seatToPrint)
        {
            printf("Ticket for Seat No. \t\t%d \n",bookings[i].seatNo);
            printf("Passenger Name: %s \t\t\n", bookings[i].name);
            printf("Pasenger Source: %s \t\t\n", bookings[i].source);
            printf("Pasenger Destination: \t\t%s \n", bookings[i].destination);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Reservation not found.");
    }
}


