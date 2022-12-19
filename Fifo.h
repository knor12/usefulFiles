/*
 * Fifo.h
 *
 *  Created on: Dec 1, 2020
 *      Author: n.kessa
 */

#ifndef FIFO_H_
#define FIFO_H_

/*
** queue-valvano.c
**
** Macro to create thread-safe queues. Originally from the book Embedded
** Systems, by Jonathan W. Valvano, chapter 3, page 130.
*/

/*
** To use it:
**
** 20-element queue storing unsigned 16-bit numbers:
**
** AddPointerFifo(Rx, 20, unsigned short, 1, 0)
**
** which will create RxFifo_Init(), RxFifo_Get and Rx_Fifo_Put().
**
** 150-element queue of struct sensor_data:
**
** AddPointerFifo(Sensor, 150, struct sensor_data, 1, 0)
**
** which will create SensorFifo_Init(), SensorFifo_Get() and SensorFifo_Put().
*/

#define AddPointerFifo(NAME,SIZE,TYPE,SUCCESS,FAIL) \
TYPE volatile *NAME ## PutPt;                                           \
TYPE volatile *NAME ## GetPt;                                           \
TYPE static NAME ## Fifo[SIZE];                                         \
void NAME ## Fifo_Init(void) {                                          \
    NAME ## PutPt = NAME ## GetPt = &NAME ## Fifo[0]; \
}                                                       \
int NAME ## Fifo_Put (TYPE * datapt) {                                  \
    TYPE volatile *nextPutPt;                                   \
    nextPutPt = NAME ## PutPt + 1;                                  \
    if (nextPutPt == &NAME ## Fifo[SIZE]) {                     \
        nextPutPt = &NAME ## Fifo[0];                       \
    }                                   \
    if (nextPutPt == NAME ## GetPt) {                                   \
        return (FAIL);                                      \
    } else {                                            \
    memcpy( NAME ## PutPt , datapt, sizeof( TYPE ) );     \
        NAME ## PutPt = nextPutPt;          \
        return (SUCCESS);   \
    }   \
}       \
int NAME ## Fifo_Get (TYPE * datapt) {                               \
    if (NAME ## PutPt == NAME ## GetPt) {                           \
        return (FAIL);      \
    }           \
    memcpy( datapt , NAME ## GetPt, sizeof( TYPE ) );           \
    NAME ## GetPt  ++;                                    \
    if (NAME ## GetPt == &NAME ## Fifo[SIZE]) {             \
        NAME ## GetPt = &NAME ## Fifo[0];                               \
    }               \
    return (SUCCESS);   \
}   \

#endif /* FIFO_H_ */
