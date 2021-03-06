/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                         M A I N                                               *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   INCLUDES                      #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "machine/virtcpu.h"
#include "machine/swpic.h"
#include "machine/plugbox.h"
#include "device/curskbd.h"
#include "device/cursstr.h"
#include "device/panic.h"
#include "device/watch.h"
#include "thread/scheduler.h"
#include "user/task4.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                GLOBAL OBJECTS                   #
\* * * * * * * * * * * * * * * * * * * * * * * * */
unsigned int uiSpuriousInterruptCount;

Virtual_CPU     cpu;
Software_PIC    pic;
Panic           panic;
Plugbox         plugbox;
Curses_Stream   kout;
Curses_Keyboard keyboard;
Scheduler       scheduler;
Watch           watch;


/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   METHODS                       #
\* * * * * * * * * * * * * * * * * * * * * * * * */
/** \brief kernel entry point
 *
 * This is the entry point of the operating system.  If this function returns
 * all interrupts will be disabled and the cpu will be halted.
 **/
void kernel(){
  kout.setpos(20,5);
  kout << "Choose Subtask(A,B)!" << endl;
  Key k;
  do
  {
    k = keyboard.key_hit();
  }while(!k.valid() || (k.ascii()!='A' && k.ascii()!='B'));
  kout << endl << "Subtask " << k.ascii() << " chosen." << endl;
  Task4 task(k.ascii()=='A');

  keyboard.plugin();
  if(k.ascii()=='B')
      watch.windup();

  scheduler.schedule(task);
}
