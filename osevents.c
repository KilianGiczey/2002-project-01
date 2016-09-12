/* 
    CITS2002 Project 1 2016
    Name(s):           Kilián Giczey (, Vaughan Ferguson)
    Student number(s): 21720994 (, 21316719)
    Date:       ??-09-16
*/

//  compile with cc -std=c99 -Wall -Werror -o osevents osevents.c
//  run with     ./osevents

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define scenario        "/Users/vaughan/Dropbox/CITS2002/project01/scenario.txt"

int main(void)
{
    //  READ FILE FOR NECESSARY ATTRIBUTES OF SIMULATION
    FILE *scenario_01 = fopen("scenario.txt", "r");

	char line[256];
	
	int timeQuantum;
	int RPM;
	int sectors;    	
    
    //  EXIT IF FAILURE
    if (scenario_01 == NULL)
    {
        printf("Couldn't open scenario file.\n");
        exit(EXIT_FAILURE);
    }
    
    else
    {
        while (fgets(line, sizeof line, scenario_01) != NULL)
        {
            printf("%s", line);
		
            //strstr is used to check if one string contains another string
            //sscanf allocates a certain data type to a corresponding variable

            //temporary name string
            char name[20];
            //finds time quantum
            if(strstr(line, "timequantum"))
            {
                sscanf( line, "%s %d", name, &timeQuantum);
            }
            //finds rpms
            else if(strstr(line, "diskrpm"))
            {
                sscanf( line, "%s %d", name, &RPM);
            }
            //finds sectors
            else if(strstr(line, "disksectors"))
            {
                sscanf( line, "%s %d", name, &sectors);
            }
		}
        printf("\n");
        printf("Time quantum is = %d\n", timeQuantum);
        printf("Disk RPMS is = %d\n", RPM);
        printf("Disk Sectors is = %d\n", sectors);
    }
    fclose(scenario_01);
    
    exit(EXIT_SUCCESS);
    return 0;
}

/*
int main(void)
{
    //  FINAL OUTPUT (MICROSECONDS)
    printf("%i      %i      %i", total_process_turnaround_time, total_blocked_reading_time, total_blocked_writing_time);
}
*/


