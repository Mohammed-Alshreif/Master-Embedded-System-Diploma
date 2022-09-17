/*
 * util.h
 *
 * Created: 17/09/2022 04:28:09 م
 *  Author: 20102
 */ 


#ifndef UTIL_H_
#define UTIL_H_

#define setpit(port,pin)    (port|=(1<<pin))
#define clearpit(port,pin)  (port&=~(1<<pin))
#define toglpit(port,pin)   (port^=(1<<pin))
#define readpit(port,pin)   ((port>>pin)&1)
#define setport(port)    (port=0xff)

#endif /* UTIL_H_ */