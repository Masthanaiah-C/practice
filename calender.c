//calender application

#include <stdio.h>
#include <stdlib.h>
 
int isLeapYear( int year );        /* True if leap year */
int leapYears( int year );         /* The number of leap year */
int todayOf( int y, int m, int d); /* The number of days since the beginning of the year */
long days( int y, int m, int d);   /* Total number of days */
void calendar(int y, int m);       /* display calendar at m y */
int getday();/*display day*/
int findm(int,int);
int weekday(int,int,int);
 int get_1st_weekday(int year);
 void dispyear();

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
 
typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;
 
int main(int argc, char* argv[]){
    int year,month, day;
    char choice;
    Note note;
    FILE *fp;
 
    fp = fopen("note.bin", "r");
    if (fp == NULL) {
      fp = fopen("note.bin", "w");
    } 
    fclose(fp);
 
    while(1) {
      printf("1. Find the day\n");
      printf("2. Display calendar of a month and notes existing\n");
      printf("3. Display calendar of a year\n");
      printf("4. Add note\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("\n%c", &choice);
      switch(choice) {
        case '1':
        getday();
        break;
        case '2':
        printf("Enter the month and year: ");
        scanf("%d %d", &month, &year);
        printf("Please enter 's' to see the notes\n Press any other key to continue\n");
        calendar(year, month);
        break;
        case '4':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &note.day, &note.month, &note.year);
        flush();
        printf("Enter the note: ");
        fgets(note.note, 255, stdin);
        fp = fopen("note.bin", "a+");
        if (fp == NULL) {
          printf("File note.bin can not be opened\n");
          exit(1);
        }
        fwrite(&note, sizeof(Note), 1, fp);
        printf("Note added sucessfully\n");
        fclose(fp);
        break;
        case '3':  dispyear();
        break;
        case '5':
        printf("Bye!!");
        exit(0);
        break;
        
        default:
        printf("Not a valid option\n");
        break;
      }
    }
    return 0;
}
 
int isLeapYear( int y ){
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}
 
int leapYears( int y ){
    return y/4 - y/100 + y/400;
}
 
int todayOf( int y, int m, int d) {
    static int DayOfMonth[] = 
        { -1,0,31,59,90,120,151,181,212,243,273,304,334};
    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}
 
long days( int y, int m, int d){
    int lastYear;
    lastYear = y - 1;
    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}
 
void calendar(int y, int m){
    FILE *fp;
    Note* notes, note;
    int len, j, hasNote = 0;
    char choice;
    const char *NameOfMonth[] = { NULL,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;
 
    weekOfTopDay = days(y, m, 1) % 7;
 
    fp = fopen("note.bin", "rb");
    if (fp == NULL) {
      printf("Couldn't read notes\n");
    }
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        len++;
      }
    }
    rewind(fp);
    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        notes[j] = note;
        j++;
      }
    }
 
    fclose(fp);
 
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);
 
    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%2d| ",day);
            hasNote = 1;
            break;
          }
        }
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }   
    printf("\n");
    scanf("\n%c", &choice);
    if (choice == 's') {
      printf("Here are list of notes for %d %d\n", m, y);
      for (j = 0; j < len; j++) {
        printf("%d: %s\n", notes[j].day, notes[j].note);
      }
    } else {
      return;
    }
}
 

int get_1st_weekday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

void dispyear()
{
   
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nEnter your desired year:");
   scanf("%d",&year);

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthDay[1]=29;

   startingDay=get_1st_weekday(year);

   for(month=0;month<12;month++){

      daysInMonth=monthDay[month];
      printf("\n\n---------------%s-------------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }
   }

   
    int getday(){
                  int dat, mont, years;
                  printf("Enter the year : ");
                  scanf("%d", &years);
                  printf("\n Enter the month : ");
                  scanf("%d", &mont);
                  printf("\n Enter the date : ");
                  scanf("%d", &dat);
                  weekday(dat, mont, years);
                  return 0;
                  }
    int weekday(int date, int month, int year) {
           int dayWeek, yr, yd;
           yr = year % 100;
           yd = year / 100;
           printf("\nThe Date Given is : %d / %d / %d \n\n", date, month, year);
           dayWeek = 1.25 * yr + findm(month, year) + date - 2 * (yd % 4);
           dayWeek = dayWeek % 7;
           switch (dayWeek){
           case 0:  printf("Day of Week of the Date is : Saturday\n");
                        break;
           case 1:  printf("Day of Week of the Date is : Sunday\n");
                        break;
           case 2:  printf("Day of Week of the Date is : Monday\n");
                        break;
           case 3:  printf("Day of Week of the Date is : Tuesday\n");
                        break;
           case 4:  printf("Day of Week of the Date is : Wednesday\n");
                        break;
           case 5:  printf("Day of Week of the Date is : Thursday\n");
                        break;
           case 6:  printf("Day of Week of the Date is : Friday\n");
                        break;
           default:  printf("The Given input data is wrong");
           }
           return 0;
           }
    int findm(int months, int yearss){
           int findmonth, leapyr;
           if ((yearss % 100 == 0) && (yearss % 400 != 0))
           leapyr = 0;
           else if (yearss % 4 == 0)
           leapyr = 1;
           else
           leapyr = 0;
           findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months))
+ (5 * months + months / 9) / 2;
           findmonth = findmonth % 7;
           return findmonth;
    }