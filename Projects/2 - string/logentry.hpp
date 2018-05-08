#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
  Date      ()  {day = String(); month = String(); year = 0;}
  Date(String D, String M, int Y){day = D; month = M; year = Y;}
  String   getday    ()      const {return day;};
  String   getmonth  ()      const {return month;};
  int      getyear   ()      const {return year;};
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
  Time      ()  {hour = 0; minute = 0; second = 0;};
  Time(int H, int M, int S){hour = H; minute = M; second = S;}
  int      gethour   ()      const {return hour;};
  int      getminute ()      const {return minute;};
  int      getsecond ()      const {return second;};
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
           LogEntry ()            {};
           LogEntry (String);
  String   gethost  ()      const {return host;};
  int      getbytes ()      const {return number_of_bytes;};
  friend  std::ostream& operator<<(std::ostream&, const LogEntry);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
    bool    isEmpty;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
#endif

