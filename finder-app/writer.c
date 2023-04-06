#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int main(int argc, const char *argv[])
{
    openlog("writer", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

    if (argc < 3)
    {
        syslog(LOG_ERR, "Expected 2 arguments: finder.sh <writefile> <writestr");
        closelog();
        exit(1);
    }

    // 

    const char *file_name = argv[1];
    const char *write_str = argv[2];

    FILE *file = fopen(file_name, "w");

    if (file)
    {
        fprintf(file,"%s",write_str);
        fclose(file);
        syslog (LOG_DEBUG , "Writing %s to %s",write_str,file_name);
    }
    else
    {
        syslog(LOG_ERR, "failed to open <writefile>");
        closelog();
        exit(1);
    }

    closelog();
}