#include "serial.h"

Serial::Serial(const std::string &portOverride)
{
    serialPort = DEFAULT_PORT;
    if (!portOverride.empty())
    {
        serialPort = portOverride;
    }
};

void Serial::Open()
{
    fdPort = open(&serialPort[0], O_RDWR);
    if (fdPort == -1)
    {
        printf("Failed to open serial port.\n");
        return;
    }

    struct termios settings;
    tcgetattr(fdPort, &settings);

    cfsetospeed(&settings, BAUD); /* baud rate out */
    cfsetispeed(&settings, BAUD); /* baud rate in */
    settings.c_cflag &= ~PARENB;  /* no parity */
    settings.c_cflag |= CSTOPB;   /* 2 stop bits */
    settings.c_cflag &= ~CSIZE;
    settings.c_cflag |= CS8;      /* 8 bits */
    settings.c_cflag |= CLOCAL;   /* Turn on READ & ignore ctrl lines (CLOCAL = 1) */
    settings.c_lflag &= ~ICANON;  /* Disable canonical mode */
    settings.c_oflag &= ~OPOST;   /* Prevent special interpretation of output bytes (e.g. newline chars) */
    settings.c_oflag &= ~ONLCR;   /* Prevent conversion of newline to carriage return/line feed */
    settings.c_oflag &= ~CRTSCTS; /* Disable RTS/CTS hardware flow control (most common) */
    settings.c_lflag &= ~ECHO;
    settings.c_lflag &= ~ISIG;                                                        /* Disable interpretation of INTR, QUIT and SUSP */
    settings.c_iflag &= ~(IXON | IXOFF | IXANY);                                      /* Turn off s/w flow ctrl */
    settings.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); /* Disable any special handling of received bytes */
    settings.c_cc[VTIME] = 1;                                                         /* Wait for up to 1 deciseconds (unit of 0.1 seconds), returning as soon as any data is received. */
    settings.c_cc[VMIN] = 0;                                                          /* Min bytes to wait for */

    // Save tty settings, also checking for error
    if (tcsetattr(fdPort, TCSANOW, &settings) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        Close();
        return;
    }
    established = true;
    printf("Serial connection established.\n");
    return;
}

void Serial::Close()
{
    if (established)
    {
        printf("Closing serial connection.\n");
        close(fdPort);
    }
}

void Serial::Write(const std::string &command, bool expectsResponse)
{
    if (established)
    {
        const int maxSize = 32;
        uint8_t outBuffer[maxSize] = {""};

        int i = 0;
        for (char c : command)
        {
            if (i >= maxSize)
            {
                break;
            }
            outBuffer[i++] = static_cast<uint8_t>(c);
        }
        int bytesWritten = write(fdPort, &outBuffer, sizeof(outBuffer));
        if (bytesWritten == -1)
        {
            printf("Error writing to serial connection.\n");
            return;
        }

        if (expectsResponse)
        {
            Read();
        }
    }
    return;
}

void Serial::Read()
{
    int readin = 0;
    char buffer[256];
    char *bufptr;

    bufptr = buffer;
    while ((readin = read(fdPort, bufptr, buffer + sizeof(buffer) - bufptr - 1)) > 0)
    {
        bufptr += readin;
        if (bufptr[-1] == ';')
        {
            break;
        }
    }
    *bufptr = '\0';
    printf("Received message: %s\n", buffer);
    return;
}
