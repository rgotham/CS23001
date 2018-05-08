//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "logentry.hpp"
#include "string.hpp"
////////////////////////////////////////////////////////// 
// REQUIRES: String s == singular line from input file  
// ENSURES:  LogEntry == respective values within line in input file
//
LogEntry::LogEntry(String s) {
    std::vector<String> vec = s.split(' ');
  if(vec.size() == 10){
    host = vec.at(0);
    String dateTimeTemp = vec.at(3);
    std::vector<String> vecTime = dateTimeTemp.split(':');
    time = Time(vecTime.at(1).strToInt(),
                vecTime.at(2).strToInt(),
                vecTime.at(3).strToInt());
    String dateTemp = vecTime.at(0);
    std::vector<String> vecDate = dateTemp.split('/');
    date = Date(vecDate.at(0),
                vecDate.at(1),
                vecDate.at(2).strToInt());
    request = vec.at(5) + vec.at(6) + vec.at(7);
    status = vec.at(8);
    number_of_bytes = vec.at(9).strToInt();
    isEmpty = false;
  }else{
    host = String();
    date = Date();
    time = Time();
    request = String();
    status = String();
    number_of_bytes = 0;
    isEmpty = true;
    }  
}
////////////////////////////////////////////////////////// 
// REQUIRES: An input file for in  
// ENSURES:  Result returned contains log entries
//
std::vector<LogEntry> parse(std::istream& in) {
   std::vector<LogEntry> result;
    String line;
    while(!in.eof()){
      line.getline(in, line);
      LogEntry log;
      log = LogEntry(line);
      result.push_back(log);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES: File passed into out and a constructed LogEntry vector  
// ENSURES:  Outputs are the log vectors
//
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
  for(unsigned int i = 0; i < logs.size(); ++i){
    out << logs[i]; 
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES: File passed into out and a constructed LogEentry vector
// ENSURES:  Outputs are the host of each LogEntry
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
  for(unsigned int i = 0; i < logs.size(); ++i){
    out << logs[i].gethost() << std::endl;
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES: LogEntry vector passed into function
// ENSURES: byte count returned as int
//
int byte_count(const std::vector<LogEntry>& logs) {
  int count = 0;
  for(unsigned int i = 0; i < logs.size(); ++i){
    count += logs[i].getbytes();
    std::cout << "Byte count: " << count << std::endl;
  }
  return count;
}

std::ostream& operator<<(std::ostream& out, const LogEntry log){
  out << "Host: " << log.host << '\n';
  
  out << "Day: " << log.date.getday() << ' ';
  out << "Month: " << log.date.getmonth() << ' ';
  out << "Year: " << log.date.getyear() << '\n';
  
  out << "Hour: " << log.time.gethour() << ' ';
  out << "Minute: " << log.time.getminute() << ' ';
  out << "Second: " << log.time.getsecond() << '\n';
  
  out << "Request: " << log.request << '\n';
  out << "Status: " << log.status << ' ';
  out << "Bytes: " << log.number_of_bytes << '\n';
 
  return out;
}
