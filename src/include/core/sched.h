#ifndef _CPU_SCHEDULER_H
#define _CPU_SCHEDULER_H

#include <core/sched/task.h>
#include <arch/i386/idt.h>
#include <def/compile.h>
#include <stdint.h>

void schedule();

void scheduler_init();
void scheduler_add_task(struct Task* task);
void scheduler_remove_task(struct Task* task);

struct Task* scheduler_pick_next();

// Dispatcher
int __must_check dispatcher_load(struct Task* task);

// Process Control Block
int __must_check pcb_save_current(struct InterruptFrame* frame);
struct Task* pcb_current();
int pcb_switch(struct Task* task);
int pcb_page_current();

#endif
