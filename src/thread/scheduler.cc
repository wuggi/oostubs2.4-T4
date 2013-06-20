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
    if(!active())
    {
        if(first)
        {
            this->go(first);
        }
    }

}

/**\~english \todo implement**/
void Scheduler::ready(Thread& that){

   threads.push_back(that);
}

/**\~english \todo implement**/
void Scheduler::exit(){
    Thread* thread = (Thread*)threads.deque;
    if(thread)
    {
        dispatch(thread);
    }
}

/**\~english \todo implement**/
void Scheduler::kill(Thread& that){

    threads.erase(that);
}

/**\~english \todo implement**/
void Scheduler::resume(){
    Thread* thread = (Thread*)threads.deque;
    if(thread)
    {
        threads.push_back((Thread*)active());
        dispatch(thread);
    }
}
