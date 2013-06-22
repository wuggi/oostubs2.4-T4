/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                 Technische Informatik II                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 *                                         S C H E D U L E R                                     *
 *                                                                                               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   INCLUDES                      #
\* * * * * * * * * * * * * * * * * * * * * * * * */

#include "thread/scheduler.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                   METHODS                       #
\* * * * * * * * * * * * * * * * * * * * * * * * */

/**\~english \todo implement**/
void Scheduler::schedule(Thread& first){
}

/**\~english \todo implement**/
void Scheduler::ready(Thread& that){
}

/**\~english \todo implement**/
void Scheduler::exit(){
}

/**\~english \todo implement**/
void Scheduler::kill(Thread& that){
}

/**\~english \todo implement**//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
* Technische Informatik II *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *
* S C H E D U L E R *
* *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
# INCLUDES #
\* * * * * * * * * * * * * * * * * * * * * * * * */

#include "thread/scheduler.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *\
# METHODS #
\* * * * * * * * * * * * * * * * * * * * * * * * */

/**\~english \todo implement**/
void Scheduler::schedule(Thread& first){
    if(!active())
    {
            this->go(first);

    }

}

/**\~english \todo implement**/
void Scheduler::ready(Thread& that){
    Thread* thread = &that;
   threads.push_back(thread);
}

/**\~english \todo implement**/
void Scheduler::exit(){
    Thread* thread = threads.pop_front();
    dispatch(*thread);
}

/**\~english \todo implement**/
void Scheduler::kill(Thread& that){

    threads.erase();
}

/**\~english \todo implement**/
void Scheduler::resume(){
    Thread* thread = threads.deque;
    if(thread)
    {
        threads.push_back((Thread*)active());
        dispatch(thread);
    }
}
void Scheduler::resume(){
}
//
